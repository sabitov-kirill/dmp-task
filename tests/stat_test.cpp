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

class stat_test : public dmp_test {};

fs::path stat_file_path("/sys/module/dmp/stat/volumes");

TEST_F(stat_test, file_existance) {
    EXPECT_TRUE(fs::exists(stat_file_path));
}

using sectioned_data_parser_t = sectioned_data_parser<std::unordered_map<std::string, std::string>>;
TEST_F(stat_test, file_format) {
    std::ifstream f(stat_file_path.string());
    sectioned_data_parser_t parser(f);

    sectioned_data_parser_t::sections_container_t sections{};
    EXPECT_NO_THROW(sections = parser.parse());

    std::unordered_set<std::string> expected_sections_names{"read", "write", "total"};
    std::unordered_set<std::string> expected_fields_names{"reqs", "avg size"};

    // Check if all expected section names are present
    EXPECT_EQ(sections.size(), expected_sections_names.size());
    for (const auto &section : sections) {
        EXPECT_EQ(expected_sections_names.count(section.first), 1);

        // Check if all expected fields are present in each section
        for (const auto &field : section.second) {
            EXPECT_EQ(expected_fields_names.count(field.first), 1);

            auto value = convert_string<double>(field.second);
            EXPECT_TRUE(value.has_value());
        }
    }
}


