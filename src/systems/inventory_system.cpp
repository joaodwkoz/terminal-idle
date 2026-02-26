#include "systems/inventory_system.hpp"
#include <algorithm>

bool InventorySystem::has_upgrade(int upgrade_id) const {
    if (upgrade_id < 0 || upgrade_id > purchased_upgrades.size()) {
        return false;
    }

    return purchased_upgrades[upgrade_id];
}

void InventorySystem::apply_upgrade(int upgrade_id) {
    if (upgrade_id < 0 || upgrade_id > purchased_upgrades.size()) {
        return;
    }

    purchased_upgrades[upgrade_id] = true;
}

int InventorySystem::get_quantity(int build_id) const {
    if (build_id < 0 || build_id > builds.size()) {
        return 0;
    }

    return builds[build_id].quantity;
}

void InventorySystem::add_quantity(int build_id, int quantity) {
    if (build_id < 0 || build_id > builds.size() || quantity <= 0) {
        return;
    }

    builds[build_id].quantity += quantity;
}