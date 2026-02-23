#include "../../include/effect.hpp"

using namespace std;

int Effect::get_effect_stacked_multiplier() const {
    int effect_multiplier = 100;

    for (int i = 0; i < stacks; i++) {
        effect_multiplier *= value;
        effect_multiplier /= 100;
    }

    return effect_multiplier;
}