#pragma once

#include "ui/particle.hpp"
#include "types/screens.hpp"
#include <vector>

struct UISystem {
    ScreenType current_screen;
    std::vector<Particle> particles;
    int accumulator;

    UISystem(const ScreenType &current_screen, const std::vector<Particle> &particles, int accumulator) : current_screen(current_screen), particles(particles), accumulator(accumulator) {}

    void set_screen(const ScreenType &type);

    void process_particles(int delta_time);
};