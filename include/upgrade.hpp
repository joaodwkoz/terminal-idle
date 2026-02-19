#pragma once

#include <vector>
#include "./effect.hpp"

struct Upgrade {
    int id;
    std::vector<Effect> effects;

    Upgrade(int id, const std::vector<Effect> &effects) : id(id), effects(effects) {}
};