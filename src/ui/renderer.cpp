#include "ui/renderer.hpp"

using namespace std;

void Renderer::show_cursor() const {
    cout << "\033[?25h";
}

void Renderer::hide_cursor() const {
    cout << "\033[?25l";
}

void Renderer::reset_cursor() const {
    cout << "\033[H";
}

void Renderer::move_cursor(const Coord &coord) const {
    cout << "\033[" << (coord.y + 1) << ";" << (coord.x + 1) << "H";
}

void Renderer::get_terminal_size(int &width, int &height) const {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    width = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    height = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
}

void Renderer::clear() {
    for (int i = 0; i < (int) back_buffer.size(); i++) {
        back_buffer[i].assign(back_buffer[0].size(), ' ');
    }
}

void Renderer::draw(const Coord &coord, char c) {
    if (coord.x >= 0 && coord.x < (int) back_buffer[0].size() && coord.y >= 0 && coord.y < (int) back_buffer.size()) {
        back_buffer[coord.y][coord.x] = c;
    }
}

void Renderer::draw_string(const Coord &coord, string str) {
    if (coord.x >= 0 && coord.x + (int) str.size() < (int) back_buffer[0].size() && coord.y >= 0 && coord.y < (int) back_buffer.size()) {
        for (int i = 0; i < (int) str.size(); i++) {
            back_buffer[coord.y][coord.x + i] = str[i];
        }
    }
}

void Renderer::render() {
    for (int i = 0; i < (int) back_buffer.size(); i++) {
        for (int j = 0; j < (int) back_buffer[0].size(); j++) {
            if (back_buffer[i][j] != front_buffer[i][j]) {
                move_cursor(Coord(j, i));
                cout << back_buffer[i][j];
                front_buffer[i][j] = back_buffer[i][j];
            }
        }    
    }

    reset_cursor();
    hide_cursor();
}