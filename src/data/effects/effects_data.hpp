#pragma once

#include "../../../include/effect.hpp"
#include <string>

struct EffectData {
    int id, target_id, base_value, base_duration;
    EffectType type;
    EffectTarget target;
    std::string name, desc;

    EffectData(int id, EffectType type, EffectTarget target, int target_id, const std::string &name, const std::string &desc, int base_value, int base_duration) : id(id), type(type), target(target), target_id(target_id), name(name), desc(desc), base_value(base_value), base_duration(base_duration) {}
};