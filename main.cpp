#include <iostream>
#include <conio.h>
#include <chrono>
#include <thread>
#include <map>
#include <vector>

#include "core/game.hpp"
#include "ui/renderer.hpp"

#include "handlers/input_handler.hpp"
#include "handlers/menu_handler.hpp"

#include "types/game.hpp"

constexpr int FPS = 60;
constexpr int TARGET_MS = 1000 / FPS;

typedef unsigned long long ull;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    Game game = Game::init("Qualquer nome");

    Renderer renderer = Renderer();
    InputHandler input;
    MenuHandler menu;


    auto last_time = std::chrono::high_resolution_clock::now();

    while (game.is_running) {
        auto curr_time = std::chrono::high_resolution_clock::now();
        auto diff = std::chrono::duration_cast<std::chrono::milliseconds>(curr_time - last_time);
        last_time = curr_time;

        if (_kbhit()) {
            char key = _getch();

            if (key != 0) {
                GameCommand cmd = input.handle(key, game.ui.current_screen);

                menu.execute(cmd, game, save);
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