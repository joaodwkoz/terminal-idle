#pragma once 

#include "data/upgrades_data.hpp"
#include "types/upgrades.hpp"

struct UpgradeEntry {
    const UpgradeData *data;
    UpgradeState state;

    UpgradeEntry(const UpgradeData *data, UpgradeState state) : data(data), state(state) {}
};