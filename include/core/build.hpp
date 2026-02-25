#pragma once

#include "data/builds_data.hpp"

struct Build {
    const BuildData *data;
    int quantity;

    Build(const BuildData* data, int quantity) : data(data), quantity(quantity) {}
};