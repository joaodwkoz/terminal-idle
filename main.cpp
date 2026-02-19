#include <iostream>
#include <conio.h>
#include <chrono>
#include <thread>
#include <map>
#include <vector>
#include "./include/game.hpp"

using namespace std;

typedef unsigned long long ull;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    /* Teste de loop de execução */

    ull curr_production = 1;
    ull total_score = 0;
    
    int timer = 1;

    while (timer < 10) {
        total_score += curr_production;
        timer++;
        this_thread::sleep_for(chrono::seconds(1));
    }

    cout << "Você produziu " << total_score << " bits!" << endl;

    return 0;
}
