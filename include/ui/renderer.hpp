#pragma once

#include "ui/coord.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <windows.h>

class Renderer {
    private:
        std::vector<std::string> back_buffer;
        std::vector<std::string> front_buffer;

        void get_terminal_size(int &width, int &height) const;
    public:
        Renderer() {
            int width;
            int height;

            get_terminal_size(width, height);
        
            back_buffer.assign(height, std::string(width, ' '));
            front_buffer.assign(height, std::string(width, ' '));
            
            hide_cursor();
            reset_cursor();
        }

        void show_cursor() const;

        void hide_cursor() const;

        void reset_cursor() const;

        void move_cursor(const Coord &coord) const;
        
        void clear();

        void draw(const Coord &coord, char c);

        void draw_string(const Coord &coord, std::string str);

        void render();
};