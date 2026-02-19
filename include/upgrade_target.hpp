#pragma once

#include "./effect.hpp"

struct UpgradeTarget {
    EFFECT_TARGET type;
    int id;

    bool operator < (const UpgradeTarget &other) const {
        if (type != other.type) {
            return (int) type < (int) other.type;
        }
        return id < other.id;
    }
};