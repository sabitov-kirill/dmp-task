#include <filesystem>
#include <sys/syscall.h>
#include <unistd.h>

#include <gtest/gtest.h>
#include <fcntl.h>

namespace fs = std::filesystem;

class Environment : public ::testing::Environment {
private:
    bool unload_module = true;

public:
    ~Environment() override = default;

    void SetUp() override {
        fs::path module_path("dmp.ko");

        if (!fs::exists(module_path)) {
            throw std::runtime_error("Module dmp is not built");
        }

        int fd = open(module_path.c_str(), O_RDONLY);
        if (fd == -1) {
            throw std::runtime_error(std::string("Module dmp is not accessible: ") + strerror(errno));
        }

        if (syscall(SYS_finit_module, fd, "", 0)) {
            switch (errno) {
                case EPERM:
                    throw std::runtime_error("Can not load module: Permission denied. Try re-running tests as root.");
                case EEXIST:
                    std::cerr << "Warning: Using already loaded module" << std::endl;
                    unload_module = false;
                    break;
                default:
                    throw std::runtime_error(std::string("Can not load module: ") + strerror(errno));
            }
        }

        if (close(fd)) {
            std::cerr << "Warning: Could not close module file" << std::endl;
        }
    }

    void TearDown() override {
        if (unload_module) {
            if (syscall(SYS_delete_module, "dmp", 0)) {
                throw std::runtime_error(std::string("Can not unload module: ") + strerror(errno));
            }
        }
    }
};


int main(int argc, char **argv) {
    // gtest now owns this environment, no need to delete
    testing::AddGlobalTestEnvironment(new Environment);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}