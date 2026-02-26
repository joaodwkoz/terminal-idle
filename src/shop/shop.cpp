#include "core/game.hpp"
#include "shop/shop.hpp"
#include <vector>
#include <algorithm>
#include <cmath>

#define BUILD_GROWTH_MULTIPLIER 1.15

using namespace std;

namespace shop {
    vector<UpgradeEntry> get_available_upgrades(const Game &game) {
        vector<UpgradeEntry> available_upgrades;

        for (const UpgradeData &upgrade : data::UPGRADES) {
            if (!game.inventory.purchased_upgrades[upgrade.id]) {
                bool any_satisfied = false;
                bool all_satisfied = true;

                for (const Requirement &requirement : upgrade.requirements) {
                    if (requirement.is_satisfied(game)) {
                        any_satisfied = true;
                    } else {
                        all_satisfied = false;
                    }
                }

                UpgradeState state;
                if (all_satisfied && game.economy.bits >= upgrade.base_cost) {
                    state = UpgradeState::PURCHASABLE;
                } else if (all_satisfied) {
                    state = UpgradeState::AVAILABLE;
                } else if (any_satisfied) {
                    state = UpgradeState::VISIBLE;
                } else {
                    state = UpgradeState::LOCKED;
                }

                const UpgradeEntry new_upgrade = UpgradeEntry(&upgrade, state);

                available_upgrades.push_back(new_upgrade);
            }
        }

        sort(available_upgrades.begin(), available_upgrades.end(), [](const UpgradeEntry &a, const UpgradeEntry &b) {
            return a.data->base_cost < b.data->base_cost;
        });

        return available_upgrades;
    }

    vector<BuildEntry> get_available_builds(const Game &game) {
        vector<BuildEntry> available_builds;

        for (const BuildData &build : data::BUILDS) {
            int build_id = build.id;

            BuildState state;
            if (game.economy.bits >= calc_build_value(build_id, game.inventory.builds[build_id].quantity)) {
                state = BuildState::PURCHASABLE;
            } else if (game.inventory.builds[build_id].quantity || game.economy.bits >= build.base_val) {
                state = BuildState::VISIBLE;
            } else {
                state = BuildState::LOCKED;
            }

            const BuildEntry new_build = BuildEntry(&build, state);

            available_builds.push_back(new_build);
        }

        return available_builds;
    }

    ull calc_build_value(int build_id, int curr_quantity) {
        if (build_id < 0 || build_id >= data::BUILDS.size()) {
            return 0ULL;
        }

        return static_cast<ull>(data::BUILDS[build_id].base_val * pow(BUILD_GROWTH_MULTIPLIER, curr_quantity));
    }

    ull calc_build_series_value(const Game &game, int build_id, int quantity) {
        if (build_id < 0 || build_id >= data::BUILDS.size()) {
            return 0ULL;
        }

        return static_cast<ull>((calc_build_value(build_id, game.inventory.builds[build_id].quantity) * ((double) pow(BUILD_GROWTH_MULTIPLIER, quantity) - 1)) / ((double) BUILD_GROWTH_MULTIPLIER - 1));
    }

    void buy_build(Game &game, int build_id, int quantity) {
        if (build_id < 0 || build_id >= data::BUILDS.size()) {
            return;
        }
        
        ull build_series_value = calc_build_series_value(game, build_id, quantity);

        if (game.economy.bits >= build_series_value) {
            game.inventory.builds[build_id].quantity += quantity;
            game.economy.bits -= build_series_value;
            
            game.dirty_production = true;
        } 
    }

    void buy_upgrade(Game &game, int upgrade_id) {
        if (upgrade_id < 0 || upgrade_id >= data::UPGRADES.size()) {
            return;
        }

        if (game.inventory.purchased_upgrades[upgrade_id]) {
            return;
        }

        const UpgradeData *upgrade = &data::UPGRADES[upgrade_id];

        if (game.economy.bits >= upgrade->base_cost) {
            game.economy.bits -= upgrade->base_cost;

            for (int effect_id : upgrade->effects_ids) {
                const EffectData *effect_data = &data::EFFECTS[effect_id];
                Effect effect(effect_data, effect_data->base_value, effect_data->base_duration, 1);
                game.effects.activate_effect(effect);
            }

            game.inventory.purchased_upgrades[upgrade_id] = true;

            game.dirty_production = true;
        }
    }
}