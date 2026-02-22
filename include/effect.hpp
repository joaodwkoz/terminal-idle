#pragma once

#include "../src/data/effects/effects_data.hpp"

enum class EffectType {
    MULTIPLIER,
};

enum class EffectTarget {
    GLOBAL_PRODUCTION,
    BUILD,
};

struct Effect {
    const EffectData* data;
    int value;
    int duration;

    static const int INFINITY = INT_MAX;

    bool operator == (const Effect&) const = default;

    bool is_infinity() const {
        return duration == Effect::INFINITY;
    }
};