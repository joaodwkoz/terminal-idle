#pragma once

#include "systems/inventory_system.hpp"
#include "systems/effect_system.hpp"

typedef unsigned long long ull;

namespace production {
    ull calc_build_production(const InventorySystem &inventory, const EffectSystem &effects, int build_id);

    ull calc_total_production(const InventorySystem &inventory, const EffectSystem &effects);
}