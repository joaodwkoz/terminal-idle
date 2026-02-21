#include "../include/requirement.hpp"

using namespace std;

bool Requirement::is_satisfied(const Game &game) {
    if (type == RequirementType::TOTAL_BITS) {
        if (game.bits >= min_value) {
            return true;
        }
    } else if (type == RequirementType::TOTAL_TICKS) {
        if (game.ticks >= min_value) {
            return true;
        }
    } else if (type == RequirementType::BUILDS_AMOUNT) {
        if (target_id >= 0 && target_id < game.builds.size()) {
            if (game.builds[target_id].quantity >= min_value) {
                return true;
            }
        }
    } else if (type == RequirementType::UPGRADE_PURCHASED) {
        if (target_id >= 0 && target_id < game.purchased_upgrades.size()) {
            if (game.purchased_upgrades[target_id]) {
                return true;
            }
        }
    }

    return false;
}