//
// Created by ne1mnn on 2/1/24.
//

#ifndef DMP_CONVERT_H
#define DMP_CONVERT_H

#include <optional>
#include <sstream>

template <typename T>
std::optional<T> convert_string(const std::string &str) {
    std::istringstream stream(str);
    T result;
    if (stream >> result, stream.eof()) {
        return result;
    }
    return std::nullopt;
}

template <typename T>
bool convertible_to(const std::string &str) {
    return convert_string<T>(str).has_value();
}

#endif //DMP_CONVERT_H
