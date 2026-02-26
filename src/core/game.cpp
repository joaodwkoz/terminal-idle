#include "core/game.hpp"
#include "data/builds_data.hpp"
#include "data/upgrades_data.hpp"
#include "production/production.hpp"
#include <algorithm>

using namespace std;

typedef unsigned long long ull;

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
    
    ticks += delta_time;
}