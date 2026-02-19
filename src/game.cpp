#include <game.hpp>
#include "./data/builds/builds_data.hpp"

typedef unsigned long long ull;

ull Game::calc_build_production(const Build &build) const {
    const BuildData* data = build.data;

    int build_id = data->id;
    ull base_prod = data->base_prod;
    int quantity = build.quantity;

    int upgrade_multipliers = 100;

    for (const Upgrade &purchased_upgrade : purchased_upgrades) {
        for (const Effect &effect : purchased_upgrade.effects) {
            if (effect.target == EFFECT_TARGET::GLOBAL_PROD || (effect.target == EFFECT_TARGET::BUILD && effect.target_id == build_id)) {
                upgrade_multipliers *= effect.value;
            }
        }
    }

    int effect_multipliers = 100;

    for (const Effect &active_effect : active_effects) {
        if (active_effect.target == EFFECT_TARGET::GLOBAL_PROD || (active_effect.target == EFFECT_TARGET::BUILD && active_effect.target_id == build_id)) {
            effect_multipliers *= active_effect.value;
        }
    }
     
    return base_prod * quantity * upgrade_multipliers * effect_multipliers / 10000;
}

ull Game::calc_total_production() const {
    ull prod = 0;

    for (const Build &build : builds) {
        prod += calc_build_production(build);
    }

    return prod;
}