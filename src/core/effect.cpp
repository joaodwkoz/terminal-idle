#include "core/effect.hpp"
#include "data/effects_data.hpp"
#include "data/data.hpp"
#include <nlohmann/json.hpp>

using json = nlohmann::json;

Effect::Effect(const EffectData* effect_data, const json &json_data) {
    data = effect_data;
    value = json_data.value("value", 1);
    duration = json_data.value("duration", 1);
    stacks = json_data.value("stacks", 0);
}

bool Effect::is_finished() const {
    return duration <= 0;
}

bool Effect::is_permanent() const {
    return duration == Effect::PERMANENT;
}

int Effect::get_effect_stacked_multiplier() const {
    int effect_multiplier = 100;

    for (int i = 0; i < stacks; i++) {
        effect_multiplier *= value;
        effect_multiplier /= 100;
    }

    return effect_multiplier;
}

json Effect::to_json() const {
    json json_effect;

    json_effect["id"] = data->id;
    json_effect["value"] = value;
    json_effect["duration"] = duration;
    json_effect["stacks"] = stacks;

    return json_effect;
}