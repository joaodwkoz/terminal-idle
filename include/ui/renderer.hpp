#pragma once

#include "core/game.hpp"
#include "ui/coord.hpp"
#include "ui/screen_type.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <windows.h>

class Renderer {
    private:
        std::vector<std::string> back_buffer;
        std::vector<std::string> front_buffer;
        std::map<ScreenType, void (Renderer::*)(const Game &game)> screens;

        void get_terminal_size(int &width, int &height) const;
        
        void draw_menu(const Game &game);

        void draw_game_loop(const Game &game);

        void draw_shop(const Game &game);

        void draw_upgrades(const Game &game);
    public:
        Renderer() {
            
        }

        void show_cursor() const;

        void hide_cursor() const;

        void reset_cursor() const;

        void move_cursor(const Coord &coord) const;
        
        void clear();

        void draw(const Coord &coord, char c);

        void draw_string(const Coord &coord, const std::string &str);

        void draw_screen(const ScreenType &screen, const Game &game);

        void render(const Game &game);
};