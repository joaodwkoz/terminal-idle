#pragma once

#include <vector>
#include "./effect.hpp"
#include "../src/data/upgrades/upgrades_data.hpp"

struct Upgrade {
    const UpgradeData *data;
    bool purchased;

    Upgrade(const UpgradeData *data, bool purchased) : data(data), purchased(purchased) {}
};