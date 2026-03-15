#pragma once 

#include <string>

typedef unsigned long long ull;

namespace utils {
    std::string pad(const std::string &str, char f, int len);

    std::string format_bits(ull bits);
}