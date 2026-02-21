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

    Effect(const EffectData* data, int value, int duration) : data(data), value(value), duration(duration) {}
};