#include "systems/inventory_system.hpp"
#include "data/data.hpp"
#include "nlohmann/json.hpp"
#include <algorithm>

using json = nlohmann::json;

InventorySystem::InventorySystem(const json &json_data) {
    auto json_purchased_upgrades = json_data.value("purchased_upgrades", json::array());

    if (!json_purchased_upgrades.empty() && !json_purchased_upgrades.is_discarded()) {
        for (auto purchased_upgrades_id : json_purchased_upgrades) {
            apply_upgrade(purchased_upgrades_id);
        }
    }

    auto json_builds = json_data.value("builds", json::array());

    if (!json_builds.empty() && !json_builds.is_discarded()) {
        for (const auto &json_build : json_builds) {
            int json_id = json_build.value("id", 0);

            if (!data::is_valid_build_id(json_id)) {
                continue;
            }

            builds[json_id].quantity = json_build.value("quantity", 0);
        }
    }
}

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