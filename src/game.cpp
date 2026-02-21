#include <game.hpp>
#include "./data/builds/builds_data.hpp"
#include "./data/upgrades/upgrades_data.hpp"

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
            effect_multipliers *= effect.value;
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