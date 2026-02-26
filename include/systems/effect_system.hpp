#pragma once

#include "core/effect.hpp"
#include <vector>

typedef unsigned long long ull;

struct EffectSystem {
    std::vector<Effect> active_effects;
    bool has_changed;

    void reset_has_changed();
    
    void activate_effect(const Effect &effect);

    void deactivate_effect(const Effect &effect);

    void process_time(int delta_time);

    int get_min_duration();
};