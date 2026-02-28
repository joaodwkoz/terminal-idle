#include "core/effect.hpp"

using namespace std;

bool Effect::is_finished() const {
    return duration <= 0;
}

bool Effect::is_infinity() const {
    return duration == Effect::INFINITY;
}

int Effect::get_effect_stacked_multiplier() const {
    int effect_multiplier = 100;

    for (int i = 0; i < stacks; i++) {
        effect_multiplier *= value;
        effect_multiplier /= 100;
    }

    return effect_multiplier;
}