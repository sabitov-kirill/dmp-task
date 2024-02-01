//
// Created by ne1mnn on 1/31/24.
//

#ifndef DMP_DMP_TEST_H
#define DMP_DMP_TEST_H

#include <gtest/gtest.h>

#include "device.h"

class dmp_test : public testing::Test {
protected: /* Base class methods */
    void TearDown() override;

protected: /* User methods */
    template<typename DeviceType, typename... Args>
    void create_device(Args&&... args) {
        static_assert(std::is_base_of<device, DeviceType>::value, "DeviceType must be derived from device");
        _devices.push_back(std::make_unique<DeviceType>(std::forward<Args>(args)...));
    }

protected: /* Data */
    std::vector<std::unique_ptr<device>> _devices;
};


#endif //DMP_DMP_TEST_H
