#pragma once

#include <string>
#include <vector>
#include <shop.hpp>
#include <upgrade.hpp>
#include <effect.hpp>
#include <build.hpp>

struct Game {
    std::string name;
    int score;
    Shop shop;
    std::vector<Upgrade> purchased_upgrades;
    std::vector<Effect> active_effects;
    std::vector<Build> builds;

    Game(const std::string &name, int score, Shop shop, const std::vector<Upgrade> &purchased_upgrades, const std::vector<Effect> &active_effects, const std::vector<Build> &builds) : name(name), score(score), shop(shop), purchased_upgrades(purchased_upgrades), active_effects(active_effects), builds(builds) {}
};