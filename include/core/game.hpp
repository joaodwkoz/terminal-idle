#pragma once

#include <string>
#include <vector>
#include "systems/effect_system.hpp"
#include "systems/economy_system.hpp"
#include "systems/inventory_system.hpp"
#include "systems/ui_system.hpp"
#include "nlohmann/json_fwd.hpp"

typedef unsigned long long ull;
typedef long long ll;

struct Game {
    std::string name;
    EconomySystem economy;
    InventorySystem inventory;
    EffectSystem effects;
    UISystem ui;
    ull curr_production;
    bool dirty_production;
    int ticks;

    Game(const std::string &name, const EconomySystem &economy, const InventorySystem &inventory,  const EffectSystem &effects, const UISystem &ui, ull curr_production, bool dirty_production, int ticks) : name(name), economy(economy), inventory(inventory), effects(effects), ui(ui), curr_production(curr_production), dirty_production(dirty_production), ticks(ticks) {}

    Game(const nlohmann::json &json_data);

    static Game init(const std::string &name);

    void refresh_production();

    void refresh_production_if_dirty();
    
    void update_tick(ll delta_time);

    void load_save(const nlohmann::json &json_save);

    nlohmann::json to_json() const;
};