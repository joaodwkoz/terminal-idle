#pragma once 

#include "core/game.hpp"
#include "types/requirements.hpp"

typedef unsigned long long ull;

struct Requirement {
    RequirementType type;
    int target_id;
    ull min_value;

    Requirement(RequirementType type, int target_id, ull min_value) : type(type), target_id(target_id), min_value(min_value) {}

    bool is_satisfied(const Game& game) const;
};