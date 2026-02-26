#include "core/game.hpp"
#include "data/builds_data.hpp"
#include "data/upgrades_data.hpp"
#include <algorithm>

using namespace std;

typedef unsigned long long ull;

ull Game::calc_build_production(const Build &build) const {
    const BuildData* data = build.data;

    int build_id = data->id;
    ull base_prod = data->base_prod;
    int quantity = build.quantity;

    int effect_multipliers = 100;

    for (const Effect &effect : active_effects) {
        const EffectData *data = effect.data;

        if (data->target == EffectTarget::GLOBAL_PRODUCTION || (data->target == EffectTarget::BUILD && data->target_id == build_id)) {
            effect_multipliers *= effect.get_effect_stacked_multiplier();
            effect_multipliers /= 100;
        }
    }
     
    return base_prod * quantity * effect_multipliers / 100;
}

ull Game::calc_total_production() const {
    ull prod = 0;

    for (const Build &build : builds) {
        prod += calc_build_production(build);
    }

    return prod;
}

void Game::activate_effect(const Effect &effect) {
    auto it = find_if(active_effects.begin(), active_effects.end(), [&effect](const Effect &other){
        return effect.data->id == other.data->id;
    });

    if (it != active_effects.end()) {
        if (!it->is_infinity()) {
            it->duration = effect.duration;
        } else {
            it->stacks += 1;
        }
    } else {
        active_effects.push_back(effect);
    }

    curr_production = calc_total_production();
}

void Game::deactivate_effect(const Effect &effect) {
    auto it = find(active_effects.begin(), active_effects.end(), effect);
    
    if (it != active_effects.end()) {
        active_effects.erase(it);
        curr_production = calc_total_production();
    } 
}

void Game::update_tick(int delta_time) {
    int remaining_delta = delta_time;
    bool has_effects = !effects.active_effects.empty();

    while (remaining_delta > 0 && has_effects) {
        if (dirty_production) {

    ull new_prod = calc_total_production();

    bool last_block_had_changes = false;

    while (remaining_delta > 0 && !active_effects.empty()) {
        int next_expiry = remaining_delta;

        for (const Effect &effect : active_effects) {
            if (effect.duration < next_expiry) {
                next_expiry = effect.duration;
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


    if (remaining_delta > 0) {
        if (dirty_production) {
        ull new_bits = (new_prod * remaining_delta + remainder);
        bits += new_bits / 1000;
        remainder = new_bits % 1000;
    }
    
        economy.accumulate(curr_production, remaining_delta);
    }
    
    ticks += delta_time;
}