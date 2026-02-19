#pragma once

enum class EFFECT_TYPE {
    MULTIPLIER,
};

enum class EFFECT_TARGET {
    GLOBAL_PROD,
    BUILD,
};

struct Effect {
    int id, target_id, value, duration;
    EFFECT_TYPE type;
    EFFECT_TARGET target;

    Effect(int id, EFFECT_TYPE type, EFFECT_TARGET target, int target_id, int value, int duration) : id(id), type(type), target(target), target_id(target_id), value(value), duration(duration) {}
};