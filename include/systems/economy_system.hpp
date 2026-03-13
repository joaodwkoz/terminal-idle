#pragma once

#include "nlohmann/json_fwd.hpp"

typedef unsigned long long ull;

struct EconomySystem {
    ull bits;
    ull remainder;

    EconomySystem(ull bits, ull remainder) : bits(bits), remainder(remainder) {}

    EconomySystem(const nlohmann::json &json_data);

    void accumulate(ull curr_production, int delta_time);

    nlohmann::json to_json() const;
};