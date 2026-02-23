#pragma once 

#include "../../src/data/upgrades/upgrades_data.hpp"

enum class UpgradeState {
    LOCKED,
    VISIBLE,
    AVAILABLE,
    PURCHASABLE,
};

struct UpgradeView {
    const UpgradeData *data;
    UpgradeState state;

    UpgradeView(const UpgradeData *data, UpgradeState state) : data(data), state(state) {}
};