#include "systems/effect_system.hpp"
#include "data/data.hpp"
#include "nlohmann/json.hpp"
#include <algorithm>

using json = nlohmann::json;

EffectSystem::EffectSystem(const json &json_data) {
    active_effects = {};

    auto active_json_data = json_data.value("active", json::array());

    if (!active_json_data.empty() && !active_json_data.is_discarded()) {
        for (const auto &json_e : active_json_data) {
            int json_id = json_e.value("id", 0);

            if (!data::is_valid_effect_id(json_id)) {
                continue;
            }

            Effect effect(&data::EFFECTS[json_id], json_e);

            active_effects.push_back(effect);
        }
    }
}

void EffectSystem::reset_has_changed() {
    has_changed = false;
}

void EffectSystem::activate_effect(const Effect &effect) {
    auto it = find_if(active_effects.begin(), active_effects.end(), [&effect](const Effect &other){
        return effect.data->id == other.data->id;
    });

    if (it != active_effects.end()) {
        if (!it->is_permanent()) {
            it->duration = effect.duration;
        } else {
            it->stacks += 1;
        }
    } else {
        active_effects.push_back(effect);
    }
}

void EffectSystem::deactivate_effect(const Effect &effect) {
    auto it = find(active_effects.begin(), active_effects.end(), effect);
    
    if (it != active_effects.end()) {
        active_effects.erase(it);
    } 
}

void EffectSystem::process_time(int delta_time) {
    for (Effect &effect : active_effects) {
        if (!effect.is_permanent()) {
            effect.duration -= delta_time;
        }
    }

    auto it = remove_if(active_effects.begin(), active_effects.end(), [](const Effect& effect) { 
        return effect.is_finished(); 
    });

    if (it != active_effects.end()) {
        has_changed = true;
        active_effects.erase(it, active_effects.end());
    }
}

int EffectSystem::get_min_duration() {
    int min_duration = Effect::PERMANENT;

    for (Effect &effect : active_effects) {
        min_duration = std::min(min_duration, effect.duration);
    }

    return min_duration;
}