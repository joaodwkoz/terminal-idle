#include "systems/economy_system.hpp"
#include "nlohmann/json.hpp"
#include <algorithm>

using json = nlohmann::json;

EconomySystem::EconomySystem(const json &json_data) {
    bits = json_data.value("economy.bits", 0ULL);
    remainder = json_data.value("economy.remainder", 0ULL);
}

void EconomySystem::accumulate(ull curr_production, int delta_time) {
    ull new_bits = (curr_production * delta_time + remainder);
    bits += new_bits / 1000;
    remainder = new_bits % 1000;
}