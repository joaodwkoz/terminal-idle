#pragma once 

#include "core/game.hpp"
#include "entries/upgrade_entry.hpp"
#include "entries/build_entry.hpp"
#include <vector>

namespace shop {
    std::vector<UpgradeEntry> get_available_upgrades(const Game &game);
    std::vector<BuildEntry> get_available_builds(const Game &game);

    ull calc_build_value(int build_id, int curr_quantity);
    ull calc_build_series_value(const Game &game, int build_id, int quantity);

    void buy_build(Game &game, int build_id, int quantity);
    void buy_upgrade(Game &game, int upgrade_id);
}