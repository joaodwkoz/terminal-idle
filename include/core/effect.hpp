#pragma once

#include "data/effects_data.hpp"
#include <climits>

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
    int stacks;

    Effect(const EffectData* data, int value, int duration, int stacks) : data(data), value(value), duration(duration), stacks(stacks) {}

    static const int INFINITY = INT_MAX;

    bool operator == (const Effect&) const = default;

    bool is_infinity() const {
        return duration == Effect::INFINITY;
    }

    int get_effect_stacked_multiplier() const;
};