#pragma once 

#include "systems/economy_system.hpp"
#include "systems/inventory_system.hpp"

#include "entries/upgrade_entry.hpp"
#include "entries/build_entry.hpp"

#include <vector>

namespace shop {
    std::vector<UpgradeEntry> get_available_upgrades(const Game &game);
    std::vector<BuildEntry> get_available_builds(const Game &game);

    ull calc_build_value(int build_id, int curr_quantity);
    ull calc_build_series_value(const Game &game, int build_id, int quantity);

    void buy_build(EconomySystem &economy, InventorySystem &inventory, int build_id, int quantity);
    void buy_upgrade(EconomySystem &economy, InventorySystem &inventory, int upgrade_id);
}