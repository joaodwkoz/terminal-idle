#pragma once 

#include "core/game.hpp"

typedef unsigned long long ull;

enum class RequirementType {
    TOTAL_BITS,
    TOTAL_TICKS,
    BUILDS_AMOUNT,
    UPGRADE_PURCHASED,
};

struct Requirement {
    RequirementType type;
    int target_id;
    ull min_value;

    Requirement(RequirementType type, int target_id, ull min_value) : type(type), target_id(target_id), min_value(min_value) {}

    bool is_satisfied(const Game& game) const;
};