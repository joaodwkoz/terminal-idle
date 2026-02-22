#pragma once

#include <string>
#include <vector>
#include "../../../include/effect.hpp"
#include "../../../include/requirement.hpp"

typedef unsigned long long ull;

enum class UpgradeTarget {
    BUILD,
    GLOBAL,
};

struct UpgradeData {
    int id;
    UpgradeTarget target;
    int target_id;
    std::string name;
    std::string desc;
    std::vector<Requirement> requirements;
    std::vector<int> effects_ids;
    ull base_cost;

    UpgradeData(int id, UpgradeTarget target, int target_id, const std::string &name, const std::string &desc, const std::vector<Requirement> &requirements, const std::vector<int> &effects_ids, ull base_cost) : id(id), target(target), target_id(target_id), name(name), desc(desc), requirements(requirements), effects_ids(effects_ids), base_cost(base_cost) {}
};

extern const std::vector<UpgradeData> UPGRADES;