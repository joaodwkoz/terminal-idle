#pragma once

typedef unsigned long long ull;

struct EconomySystem {
    ull bits;
    ull remainder;

    EconomySystem(ull bits, ull remainder) : bits(bits), remainder(remainder) {}

    void accumulate(ull curr_production, int delta_time);
};