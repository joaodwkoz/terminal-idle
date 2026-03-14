#include <iostream>
#include <conio.h>
#include <chrono>
#include <thread>
#include <map>
#include <vector>

#include "core/game.hpp"
#include "ui/renderer.hpp"

constexpr int FPS = 60;
constexpr int TARGET_MS = 1000 / FPS;

typedef unsigned long long ull;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    Game game = Game::init("Qualquer nome");
    Renderer renderer = Renderer();

    auto last_time = std::chrono::high_resolution_clock::now();

    while (true) {
        auto curr_time = std::chrono::high_resolution_clock::now();
        auto diff = std::chrono::duration_cast<std::chrono::milliseconds>(curr_time - last_time);
        last_time = curr_time;

        if (_kbhit()) {
            char key = _getch();

            if (key == 'l') {
                game.ui.set_screen(ScreenType::GAME_LOOP);
            } else if (key == 'm') {
                game.ui.set_screen(ScreenType::MAIN_MENU);
            } else if (key == 's') {
                game.ui.set_screen(ScreenType::SHOP);
            } else if (key == 'u') {
                game.ui.set_screen(ScreenType::UPGRADES);
            } else if (key == 'q') {
                break;
            }
        }

        game.update_tick((int) diff.count());

        renderer.render(game);

        auto processing_time = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - curr_time);
        auto wait_time = std::chrono::milliseconds(TARGET_MS) - processing_time;

        if (wait_time > std::chrono::milliseconds(0)) {
            std::this_thread::sleep_for(wait_time);
        }
    }

    return 0;
}