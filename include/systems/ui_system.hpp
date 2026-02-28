#pragma once

#include "ui/particle.hpp"
#include <vector>

struct UISystem {
    std::vector<Particle> particles;
    int accumulator;

    UISystem(const std::vector<Particle> &particles, int accumulator) : particles(particles), accumulator(accumulator) {}

    void process_particles(int delta_time);
};