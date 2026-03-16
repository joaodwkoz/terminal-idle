#pragma once

#include "nlohmann/json_fwd.hpp"
#include <climits>

struct EffectData;

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

    Effect(const EffectData* data, const nlohmann::json &json_data);

    static constexpr int PERMANENT = INT_MAX;

    bool operator == (const Effect&) const = default;

    bool is_finished() const;

    bool is_permanent() const;

    int get_effect_stacked_multiplier() const;

    nlohmann::json to_json() const;
};