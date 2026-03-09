#pragma once

#include "data/builds_data.hpp"
#include "data/effects_data.hpp"
#include "data/upgrades_data.hpp"

namespace data {
    bool is_valid_build_id(const int id);

    bool is_valid_effect_id(const int id);

    bool is_valid_upgrade_id(const int id);
}