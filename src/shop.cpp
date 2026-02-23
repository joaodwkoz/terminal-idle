#include "../include/upgrade_view.hpp"
#include "../include/build_view.hpp"
#include "../include/effect.hpp"
#include "../include/game.hpp"
#include <vector>
#include <algorithm>
#include <cmath>

#define BUILD_GROWTH_MULTIPLIER 1.15

using namespace std;

vector<UpgradeView> get_available_upgrades(const Game &game) {
    vector<UpgradeView> available_upgrades;

    for (const UpgradeData &upgrade : UPGRADES) {
        if (!game.purchased_upgrades[upgrade.id]) {
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
            if (all_satisfied && game.bits >= upgrade.base_cost) {
                state = UpgradeState::PURCHASABLE;
            } else if (all_satisfied) {
                state = UpgradeState::AVAILABLE;
            } else if (any_satisfied) {
                state = UpgradeState::VISIBLE;
            } else {
                state = UpgradeState::LOCKED;
            }

            const UpgradeView new_upgrade = UpgradeView(&upgrade, state);

            available_upgrades.push_back(new_upgrade);
        }
    }

    sort(available_upgrades.begin(), available_upgrades.end(), [](const UpgradeView &a, const UpgradeView &b) {
        return a.data->base_cost < b.data->base_cost;
    });

    return available_upgrades;
}

vector<BuildView> get_available_builds(const Game &game) {
    vector<BuildView> available_builds;

    for (const BuildData &build : BUILDS) {
        int build_id = build.id;

        BuildState state;
        if (game.bits >= calc_build_value(build_id, game.builds[build_id].quantity)) {
            state = BuildState::PURCHASABLE;
        } else if (game.builds[build_id].quantity || game.bits >= build.base_val) {
            state = BuildState::VISIBLE;
        } else {
            state = BuildState::LOCKED;
        }

        const BuildView new_build = BuildView(&build, state);

        available_builds.push_back(new_build);
    }

    return available_builds;
}

ull calc_build_value(int build_id, int curr_quantity) {
    if (build_id < 0 || build_id >= BUILDS.size()) {
        return 0ULL;
    };

    return static_cast<ull>(BUILDS[build_id].base_val * pow(BUILD_GROWTH_MULTIPLIER, curr_quantity));
}

ull calc_build_series_value(const Game &game, int build_id, int quantity) {
    if (build_id < 0 || build_id >= BUILDS.size()) {
        return 0ULL;
    };

    return static_cast<ull>((calc_build_value(build_id, game.builds[build_id].quantity) * ((double) pow(BUILD_GROWTH_MULTIPLIER, quantity) - 1)) / ((double) BUILD_GROWTH_MULTIPLIER - 1));
}

void buy_build(Game &game, int build_id, int quantity) {
    if (build_id >= 0 && build_id < BUILDS.size()) {
        ull build_series_value = calc_build_series_value(game, build_id, quantity);

        if (game.bits >= build_series_value) {
            game.builds[build_id].quantity += quantity;
            game.bits -= build_series_value;
            game.curr_production = game.calc_total_production();
        }
    };
}

void buy_upgrade(Game &game, int upgrade_id) {
    if (upgrade_id >= 0 && upgrade_id < UPGRADES.size()) {
        if (!game.purchased_upgrades[upgrade_id]) {
            const UpgradeData *upgrade = &UPGRADES[upgrade_id];
        
            if (game.bits >= upgrade->base_cost) {
                game.bits -= upgrade->base_cost;

                for (int effect_id : upgrade->effects_ids) {
                    const EffectData *effect_data = &EFFECTS[effect_id];
                    Effect effect(effect_data, effect_data->base_value, effect_data->base_duration, 1);
                    game.activate_effect(effect);
                }

                game.purchased_upgrades[upgrade_id] = true;

                game.curr_production = game.calc_total_production();
            }
        }
    }
}