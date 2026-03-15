#include "utils/utils.hpp"

typedef unsigned long long ull;

namespace utils {
    std::string pad(const std::string &str, char f, int len) {
        int str_len = (int) str.size();

        if (len - str_len < 0) {
            return "";
        }

        return std::string(len - str_len, f) + str;
    }

    std::string format_bits(ull bits) {
        std::string scales[7] = {"b", "Kb", "Mb", "Gb", "Tb", "Pb", "Eb"};

        ull temp_bits = bits;
        int scales_idx = 0;

        while (temp_bits >= (1 << 10) && scales_idx < 6) {
            temp_bits >>= 10;
            scales_idx++;
        }

        ull scales_val = 1 << (scales_idx * 10);

        std::string int_part = std::to_string(bits / scales_val);
        std::string frac_part = pad(std::to_string((bits % scales_val) * 100 / scales_val), '0', 2);
        std::string total = int_part + (scales_idx > 0 ? "." + frac_part : "") + " " + scales[scales_idx];

        return total;
    }
}