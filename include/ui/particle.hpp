#pragma once

#include "ui/coord.hpp"
#include <vector>

struct Particle {
    Coord curr_coord;
    std::vector<Coord> steps;
    int curr_step;

    Particle(const Coord &curr_coord, const std::vector<Coord> &steps, int curr_step) : curr_coord(curr_coord), steps(steps), curr_step(curr_step) {}

    bool is_finished() const;

    void process_time(int delta_time);
};