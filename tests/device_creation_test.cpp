//
// Created by ne1mnn on 1/31/24.
//

#include <fstream>
#include <filesystem>
#include <unordered_set>

#include "lib/dmp_test.h"
#include "lib/sectioned_data_parser.h"
#include "lib/convert.h"

namespace fs = std::filesystem;

class device_creation_test : public dmp_test {
};

TEST_F(device_creation_test, file_existance_zero) {
    create_device<device_mapper_device>("zero1", 0, 128, "zero");
    create_device<device_mapper_device>("dmp1", 0, 128, "dmp", "/dev/mapper/zero1");

    for (auto &&d: _devices) {
        EXPECT_TRUE(d->is_present());
    }
}

TEST_F(device_creation_test, file_existance_loop) {
    fs::path loop_device_path = "/dev/loop3";
    constexpr size_t temp_file_size = 4096;

    std::array<char, temp_file_size> buffer{0};
    create_device<loop_device>(loop_device_path, buffer);
    create_device<device_mapper_device>("dmp_test", 0, temp_file_size / 512, "dmp", loop_device_path);

    for (auto &&d: _devices) {
        EXPECT_TRUE(d->is_present());
    }
}