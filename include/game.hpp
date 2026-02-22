#pragma once

#include <string>
#include <vector>
#include "./effect.hpp"
#include "./build.hpp"

typedef unsigned long long ull;

struct Game {
    std::string name;
    ull bits, curr_production;
    int ticks;
    std::vector<bool> purchased_upgrades;
    std::vector<Effect> active_effects;
    std::vector<Build> builds;

    Game(const std::string &name, ull bits, ull curr_production, int ticks, const std::vector<bool> &purchased_upgrades, const std::vector<Effect> &active_effects, const std::vector<Build> &builds) : name(name), bits(bits), curr_production(curr_production), ticks(ticks), purchased_upgrades(purchased_upgrades), active_effects(active_effects), builds(builds) {}

    ull calc_build_production(const Build &build) const;

    ull calc_total_production() const;

    void activate_effect(const Effect &effect);

    void deactivate_effect(const Effect &effect);

    void update_tick(int delta_time);
};