#pragma once 

#include "data/builds_data.hpp"

typedef unsigned long long ull;

enum class BuildState {
    LOCKED,
    VISIBLE,
    PURCHASABLE,
};

struct BuildEntry {
    const BuildData *data;
    ull value;
    BuildState state;

    BuildEntry(const BuildData *data, BuildState state) : data(data), state(state) {}
};