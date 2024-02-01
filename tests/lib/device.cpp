//
// Created by ne1mnn on 2/1/24.
//

#include <format>
#include <utility>
#include <cstring>

#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/loop.h>

#include "device.h"

file_descriptor::file_descriptor(const fs::path &path, int flag) : _fd(open(path.c_str(), flag)) {}

file_descriptor::~file_descriptor() {
    if (_fd != -1) close(_fd);
}

file_descriptor::file_descriptor(file_descriptor &&other) noexcept: _fd(other._fd) {
    other._fd = -1;
}

file_descriptor &file_descriptor::operator=(file_descriptor &&other) noexcept {
    if (this != &other) {
        _fd = std::exchange(other._fd, -1);
    }
    return *this;
}

int file_descriptor::get() const { return _fd; }

bool file_descriptor::is_valid() const { return _fd != -1; }

device::device(std::string name) : _name(std::move(name)) {}

bool device::is_present() { return false; }

const std::string &device::get_name() const {
    return _name;
}

loop_device::loop_device(const fs::path &loop_device_path, const fs::path &file_path)
        : device(loop_device_path.string()) {
    init_device(file_path, loop_device_path);
}

loop_device::~loop_device() {
    if (!valid) return;

    auto loop_fd = file_descriptor(_name, O_RDWR);
    if (!loop_fd.is_valid()) return;

    // Use LOOP_CLR_FD to clear the association with the file
    if (ioctl(loop_fd.get(), LOOP_CLR_FD, 0) == -1) {
        perror("Error clearing loop device association");
    }
}

void loop_device::init_device(const fs::path &file_path, const fs::path &loop_device_path) {
    auto file_fd = file_descriptor(file_path, O_RDWR);
    if (!file_fd.is_valid()) return;

    auto loop_fd = file_descriptor(loop_device_path, O_RDWR);
    if (loop_fd.is_valid()) return;

    if (ioctl(loop_fd.get(), LOOP_SET_FD, file_fd.get()) == -1) {
        return;
    }

    valid = true;
}

bool loop_device::is_present() {
    auto fd = file_descriptor(_name, O_RDONLY);
    return fd.is_valid();
}

device_mapper_device::device_mapper_device(std::string device_name, size_t begin, size_t len, const char *target_name,
                                           const std::string &params)
        : device(device_name) {
    std::string dm_cmd = std::format("dmsetup create {} --table \"{} {} {}", device_name, begin, len, target_name);
    if (!params.empty()) {
        dm_cmd += " " + params;
    }
    dm_cmd += "\"";
    if (system(dm_cmd.c_str()) != 0) return;

    valid = true;
}

device_mapper_device::~device_mapper_device() {
    if (!valid) return;

    std::string dm_cmd = std::format("dmsetup remove {}", _name);
    if (system(dm_cmd.c_str()) != 0) {
        perror("Failed to remove device");
    }
}

bool device_mapper_device::is_present() {
    // Open pipe with ls command and use unique_ptr to manage its lifetime
    auto pipe_deleter = [](FILE *pipe) {
        if (pipe) pclose(pipe);
    };
    std::unique_ptr<FILE, decltype(pipe_deleter)> lsblk_pipe(popen("ls /dev/mapper/*", "r"), pipe_deleter);
    if (!lsblk_pipe) {
        return false;
    }

    std::array<char, 128> buffer{};
    bool device_found = false;
    while (fgets(buffer.data(), sizeof(buffer), lsblk_pipe.get()) != nullptr) {
        if (strstr(buffer.data(), _name.c_str()) != nullptr) {
            device_found = true;
            break;
        }
    }

    return device_found;
}
