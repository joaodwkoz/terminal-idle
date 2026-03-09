#include "systems/inventory_system.hpp"
#include "data/data.hpp"
#include <algorithm>

bool InventorySystem::has_upgrade(int upgrade_id) const {
    if (!data::is_valid_upgrade_id(upgrade_id)) {
        return false;
    }

    return purchased_upgrades[upgrade_id];
}

void InventorySystem::apply_upgrade(int upgrade_id) {
    if (!data::is_valid_upgrade_id(upgrade_id)) {
        return;
    }

    purchased_upgrades[upgrade_id] = true;
}

int InventorySystem::get_quantity(int build_id) const {
    if (!data::is_valid_build_id(build_id)) {
        return 0;
    }

    return builds[build_id].quantity;
}

void InventorySystem::add_quantity(int build_id, int quantity) {
    if (!data::is_valid_build_id(build_id)) {
        return;
    }

    builds[build_id].quantity += quantity;
}