#pragma once 

#include "data/upgrades_data.hpp"

enum class UpgradeState {
    LOCKED,
    VISIBLE,
    AVAILABLE,
    PURCHASABLE,
};

struct UpgradeEntry {
    const UpgradeData *data;
    UpgradeState state;

    UpgradeEntry(const UpgradeData *data, UpgradeState state) : data(data), state(state) {}
};