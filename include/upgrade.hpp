#pragma once 

#include "../src/data/upgrades/upgrades_data.hpp"

enum class UpgradeState {
    LOCKED,
    VISIBLE,
    AVAILABLE,
    PURCHASABLE,
};

struct Upgrade {
    const UpgradeData *data;
    UpgradeState state;

    Upgrade(const UpgradeData *data, UpgradeState state) : data(data), state(state) {}
};