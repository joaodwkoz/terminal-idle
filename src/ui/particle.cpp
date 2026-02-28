#include "ui/particle.hpp"

using namespace std;

bool Particle::is_finished() const{
    return curr_step + 1 >= (int) steps.size();
}

void Particle::process_time(int delta_time) {
    if (curr_step >= (int) steps.size()) {
        return;
    }

    for (int i = 1; i <= delta_time && curr_step + i < (int) steps.size(); i++) {
        curr_coord += steps[curr_step + i];
        curr_step += 1;
    }
}