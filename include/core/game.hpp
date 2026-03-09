#pragma once

#include <string>
#include <vector>
#include "systems/effect_system.hpp"
#include "systems/economy_system.hpp"
#include "systems/inventory_system.hpp"
#include "systems/ui_system.hpp"

typedef unsigned long long ull;

struct Game {
    std::string name;
    EffectSystem effects;
    EconomySystem economy;
    InventorySystem inventory;
    EffectSystem effects;
    UISystem ui;
    ull curr_production;
    bool dirty_production;
    int ticks;

    Game(const std::string &name, const EconomySystem &economy, const InventorySystem &inventory,  const EffectSystem &effects, const UISystem &ui, ull curr_production, bool dirty_production, int ticks) : name(name), economy(economy), inventory(inventory), effects(effects), ui(ui), curr_production(curr_production), dirty_production(dirty_production), ticks(ticks) {}

    static Game init(const std::string &name);

    void refresh_production_if_dirty();
    
    void update_tick(int delta_time);
};