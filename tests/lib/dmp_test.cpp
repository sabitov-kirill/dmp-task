//
// Created by ne1mnn on 1/31/24.
//

#include <format>
#include <ranges>

#include "dmp_test.h"

void dmp_test::TearDown() {
    // Remove created _devices
    for (auto& device : _devices | std::ranges::views::reverse) {
        device.reset();
    }
    _devices.clear();
}
