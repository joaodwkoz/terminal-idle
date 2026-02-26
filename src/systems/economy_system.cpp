#include "systems/economy_system.hpp"
#include <algorithm>

void EconomySystem::accumulate(ull curr_production, int delta_time) {
    ull new_bits = (curr_production * delta_time + remainder);
    bits += new_bits / 1000;
    remainder = new_bits % 1000;
}