#pragma once 

#include "../src/data/builds/builds_data.hpp"

typedef unsigned long long ull;

enum class BuildState {
    LOCKED,
    VISIBLE,
    PURCHASABLE,
};

struct BuildView {
    const BuildData *data;
    ull value;
    BuildState state;

    BuildView(const BuildData *data, BuildState state) : data(data), state(state) {}
};