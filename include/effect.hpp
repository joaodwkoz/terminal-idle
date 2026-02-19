#pragma once

#include "../src/data/effects/effects_data.hpp"

enum class EFFECT_TYPE {
    MULTIPLIER,
};

enum class EFFECT_TARGET {
    GLOBAL_PROD,
    BUILD,
};

struct Effect {
    const EffectData* data;
    int value;
    int duration;

    Effect(const EffectData* data, int value, int duration) : data(data), value(value), duration(duration) {}
};