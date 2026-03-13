#include "core/game.hpp"
#include "data/builds_data.hpp"
#include "data/upgrades_data.hpp"
#include "production/production.hpp"
#include "nlohmann/json.hpp"
#include <algorithm>

using namespace std;
using json = nlohmann::json;

typedef unsigned long long ull;

constexpr int FRAMES = 60;
constexpr int MS_PER_FRAME = 1000 / FRAMES;

Game::Game(const json &json_data) 
    :   name(json_data.value("name", "Sem nome")),
        economy(json_data.value("economy", json::object())),
        inventory(json_data.value("inventory", json::object())),
        effects(json_data.value("effects", json::object())),
        ui(ScreenType::GAME_LOOP, {}, 0),
        curr_production(json_data.value("current_production", 0ULL)),
        dirty_production(false),
        ticks(json_data.value("total_ticks", 0))
{
   
}

Game Game::init(const string &name) {
    return Game(
        name,
        EconomySystem(0, 0),
        InventorySystem({}, {}),
        EffectSystem({}, false),
        UISystem(ScreenType::GAME_LOOP, {}, 0),
        0,
        false,
        0
    );
}

void Game::refresh_production() {
    curr_production = production::calc_total_production(inventory, effects);
}

void Game::refresh_production_if_dirty() {
    if (!dirty_production) {
        return;
    }

    curr_production = production::calc_total_production(inventory, effects);

    dirty_production = false;
}

void Game::update_tick(int delta_time) {
    int remaining_delta = delta_time;
    bool has_effects = !effects.active_effects.empty();

    while (remaining_delta > 0 && has_effects) {
        if (dirty_production) {
            refresh_production_if_dirty();
        }

        int next_expiry = min(remaining_delta, effects.get_min_duration());

        economy.accumulate(curr_production, next_expiry);

        effects.process_time(next_expiry);

        if (effects.has_changed) {
            dirty_production = true;
            has_effects = !effects.active_effects.empty();
            effects.reset_has_changed();
        }

        remaining_delta -= next_expiry;
    }

    refresh_production_if_dirty();

    if (remaining_delta > 0) {
        if (dirty_production) {
            refresh_production_if_dirty();
        }

        economy.accumulate(curr_production, remaining_delta);
    }

    ui.accumulator += delta_time;
    ui.process_particles(ui.accumulator / MS_PER_FRAME);
    ui.accumulator %= MS_PER_FRAME;
    
    ticks += delta_time;
}