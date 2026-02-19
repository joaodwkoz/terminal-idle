#pragma once

#include <map>
#include <vector>
#include "./upgrade_target.hpp"
#include "./upgrade.hpp"

struct Shop {
    std::map<UpgradeTarget, std::vector<Upgrade>> available_upgrades;
    std::map<UpgradeTarget, std::vector<Upgrade>> all_upgrades;

    Shop(const std::map<UpgradeTarget, std::vector<Upgrade>> &available_upgrades, const std::map<UpgradeTarget, std::vector<Upgrade>> &all_upgrades) : available_upgrades(available_upgrades), all_upgrades(all_upgrades) {}
};