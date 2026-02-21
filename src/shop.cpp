#include "../include/build.hpp"
#include "../include/upgrade.hpp"
#include "../include/game.hpp"
#include <vector>
#include <algorithm>

using namespace std;

vector<Upgrade> get_available_upgrades(const Game &game) {
    vector<Upgrade> available_upgrades;

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

            const Upgrade new_upgrade = Upgrade(&upgrade, state);

            available_upgrades.push_back(new_upgrade);
        }
    }

    sort(available_upgrades.begin(), available_upgrades.end(), [](const Upgrade &a, const Upgrade &b) {
        return a.data->base_cost < b.data->base_cost;
    });

    return available_upgrades;
}