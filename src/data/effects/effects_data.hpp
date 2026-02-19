#pragma once

#include "../../../include/effect.hpp"
#include <string>

struct EffectData {
    int id, target_id, base_value, base_duration;
    EFFECT_TYPE type;
    EFFECT_TARGET target;
    std::string name, desc;

    EffectData(int id, EFFECT_TYPE type, EFFECT_TARGET target, int target_id, const string &name, const string &desc, int base_value, int base_duration) : id(id), type(type), target(target), target_id(target_id), name(name), desc(desc), base_value(base_value), base_duration(base_duration) {}
};