#include "systems/ui_system.hpp"
#include <algorithm>

void UISystem::process_particles(int delta_time) {
    for (Particle &particle : particles) {
        particle.process_time(delta_time);
    }

    auto it = remove_if(particles.begin(), particles.end(), [](const Particle &particle) {
        return particle.is_finished();
    });

    if (it != particles.end()) {
        particles.erase(it, particles.end());
    }
}