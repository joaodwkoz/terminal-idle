#include "production/production.hpp"

using namespace std;

typedef unsigned long long ull;

namespace production {
    ull calc_build_production(const InventorySystem &inventory, const EffectSystem &effects, int build_id) {
        if (build_id < 0 || build_id > data::BUILDS.size()) {
            return 0ULL;
        }

        const BuildData *data = &data::BUILDS[build_id];

        int build_id = data->id;
        ull base_prod = data->base_prod;
        int quantity = inventory.builds[build_id].quantity;

        int effect_multipliers = 100;

        for (const Effect &effect : effects.active_effects) {
            const EffectData *data = effect.data;

            if (data->target == EffectTarget::GLOBAL_PRODUCTION || (data->target == EffectTarget::BUILD && data->target_id == build_id)) {
                effect_multipliers *= effect.get_effect_stacked_multiplier();
                effect_multipliers /= 100;
            }
        }
        
        return base_prod * quantity * effect_multipliers / 100;
    }

    ull calc_total_production(const InventorySystem &inventory, const EffectSystem &effects) {
        ull prod = 0;

        for (const Build &build : inventory.builds) {
            prod += calc_build_production(inventory, effects, build.data->id);
        }

        return prod;
    }
}