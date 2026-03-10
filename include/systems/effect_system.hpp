#pragma once

#include "core/effect.hpp"
#include "nlohmann/json_fwd.hpp"
#include <vector>

typedef unsigned long long ull;

struct EffectSystem {
    std::vector<Effect> active_effects;
    bool has_changed;

    EffectSystem(const std::vector<Effect> &active_effects, bool has_changed) : active_effects(active_effects), has_changed(has_changed) {}

    EffectSystem(const nlohmann::json &json_data);

    void reset_has_changed();
    
    void activate_effect(const Effect &effect);

    void deactivate_effect(const Effect &effect);

    void process_time(int delta_time);

    int get_min_duration();
};