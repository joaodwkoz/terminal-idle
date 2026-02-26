#pragma once

#include "core/build.hpp"
#include <vector>

struct InventorySystem {
    std::vector<bool> purchased_upgrades;
    std::vector<Build> builds;

    bool has_upgrade(int upgrade_id) const;

    void apply_upgrade(int upgrade_id);

    int get_quantity(int build_id) const;

    void add_quantity(int build_id, int quantity);
};