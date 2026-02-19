#pragma once

#include <string>
#include <vector>
#include "../../../include/effect.hpp"

typedef unsigned long long ull;

struct UpgradeData {
    int id;
    std::string name, desc;
    std::vector<int> effect_ids;
    ull base_cost;

    UpgradeData(int id, const std::string &name, const std::string &desc, const std::vector<int> &effects_ids, ull base_cost) : id(id), name(name), desc(desc), effect_ids(effect_ids), base_cost(base_cost) {}
};

extern const std::vector<UpgradeData> UPGRADES;