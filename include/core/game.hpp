#pragma once

#include <string>
#include <vector>
#include "systems/effect_system.hpp"
#include "systems/economy_system.hpp"
#include "systems/inventory_system.hpp"

typedef unsigned long long ull;

struct Game {
    std::string name;
    EffectSystem effects;
    EconomySystem economy;
    InventorySystem inventory;
    ull curr_production;
    bool dirty_production;
    int ticks;

    Game(const std::string &name, const EffectSystem &effects, const EconomySystem &economy, const InventorySystem &inventory, ull curr_production, bool dirty_production, int ticks) : name(name), effects(effects), economy(economy), inventory(inventory), curr_production(curr_production), dirty_production(dirty_production), ticks(ticks) {}

    void refresh_production_if_dirty();
    
    void update_tick(int delta_time);
};