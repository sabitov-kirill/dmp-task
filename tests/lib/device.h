//
// Created by root on 2/1/24.
//

#ifndef DMP_DEVICE_H
#define DMP_DEVICE_H

#include <vector>
#include <string>
#include <optional>
#include <filesystem>
#include <fstream>

namespace fs = std::filesystem;

class file_descriptor {
public:
    file_descriptor() = default;

    file_descriptor(const fs::path &path, int flag);

    ~file_descriptor();

    file_descriptor(const file_descriptor &) = delete;

    file_descriptor &operator=(const file_descriptor &) = delete;

    file_descriptor(file_descriptor &&other) noexcept;

    file_descriptor &operator=(file_descriptor &&other) noexcept;

    [[nodiscard]] int get() const;

    [[nodiscard]] bool is_valid() const;

private:
    int _fd{-1};
};

class device {
public:
    explicit device(std::string name);

    virtual ~device() = default;

    virtual bool is_present();

    const std::string &get_name() const;

protected:
    std::string _name;
    bool valid{};
};

class loop_device : public device {
public:
    loop_device(const fs::path &loop_device_path, const fs::path &file_path);

    template<typename Container>
    loop_device(const fs::path &loop_device_path, const Container &buffer,
                const std::optional<fs::path> &file_path = std::nullopt) : device(loop_device_path.string()) {
        fs::path device_img_path = file_path.has_value() ?
                                   file_path.value() : fs::temp_directory_path() / "tempfile.img";

        std::ofstream temp_file(device_img_path, std::ios::out | std::ios::binary);
        temp_file.write(buffer.data(), static_cast<std::streamsize>(buffer.size()));

        init_device(device_img_path, loop_device_path);
    }

    ~loop_device() override;

    bool is_present() override;

private:
    void init_device(const fs::path &file_path, const fs::path &loop_device_path);
};

class device_mapper_device : public device {
public:
    device_mapper_device(std::string device_name, size_t begin, size_t len, const char *target_name,
                         const std::string &params = "");

    ~device_mapper_device() override;

    bool is_present() override;
};

#endif //DMP_DEVICE_H
