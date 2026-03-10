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

    static constexpr int PERMANENT = INT_MAX;

    bool operator == (const Effect&) const = default;

    bool is_finished() const;

    bool is_permanent() const;

    int get_effect_stacked_multiplier() const;
};