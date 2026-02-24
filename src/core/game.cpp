#include <game.hpp>
#include "./data/builds/builds_data.hpp"
#include "./data/upgrades/upgrades_data.hpp"
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

    ull new_prod = calc_total_production();

    bool last_block_had_changes = false;

    while (remaining_delta > 0 && !active_effects.empty()) {
        int next_expiry = remaining_delta;

        for (const Effect &effect : active_effects) {
            if (effect.duration < next_expiry) {
                next_expiry = effect.duration;
            }
        }

        ull new_bits = (new_prod * next_expiry + remainder);
        bits += new_bits / 1000;
        remainder = new_bits % 1000;

        for (Effect& effect : active_effects) {
            if (!effect.is_infinity()) {
                effect.duration -= next_expiry;
            }

            if (effect.duration <= 0) {
                last_block_had_changes = true;
            }
        }

        active_effects.erase(
            remove_if(active_effects.begin(), active_effects.end(), [](const Effect& effect) { 
                return effect.duration <= 0; 
            }), 
            active_effects.end()
        );

        if (last_block_had_changes) {
            new_prod = calc_total_production();
        }

        remaining_delta -= next_expiry;
    }

    if (remaining_delta > 0) {
        ull new_bits = (new_prod * remaining_delta + remainder);
        bits += new_bits / 1000;
        remainder = new_bits % 1000;
    }
    
    curr_production = new_prod;
    
    ticks += delta_time;
}