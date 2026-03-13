#pragma once

#include "core/build.hpp"
#include "nlohmann/json_fwd.hpp"
#include <vector>

struct InventorySystem {
    std::vector<bool> purchased_upgrades;
    std::vector<Build> builds;

    InventorySystem(const std::vector<bool> &purchased_upgrades, const std::vector<Build> &builds) : purchased_upgrades(purchased_upgrades), builds(builds) {}

    InventorySystem(const nlohmann::json &json_data);

    bool has_upgrade(int upgrade_id) const;

    void apply_upgrade(int upgrade_id);

    int get_quantity(int build_id) const;

    void add_quantity(int build_id, int quantity);

    nlohmann::json to_json() const;
};