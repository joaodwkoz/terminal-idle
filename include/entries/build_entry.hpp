#pragma once 

#include "data/builds_data.hpp"
#include "types/builds.hpp"

typedef unsigned long long ull;

struct BuildEntry {
    const BuildData *data;
    ull value;
    BuildState state;

    BuildEntry(const BuildData *data, BuildState state) : data(data), state(state) {}
};