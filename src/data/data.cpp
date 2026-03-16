#include "data/data.hpp"

namespace data {
    bool is_valid_build_id(const int id) {
        return id >= 0 && id < (int) BUILDS.size();
    }

    bool is_valid_effect_id(const int id) {
        return id >= 0 && id < (int) EFFECTS.size();
    }

    bool is_valid_upgrade_id(const int id) {
        return id >= 0 && id < (int) UPGRADES.size();
    }
}