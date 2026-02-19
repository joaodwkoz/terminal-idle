#pragma once

#include "../src/data/builds/builds_data.hpp"

struct Build {
    int quantity;
    const BuildData *data;

    Build(const BuildData* data, int quantity) : data(data), quantity(quantity) {}
};