#include "../../include/ui/renderer.hpp"

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

void Renderer::move_cursor(int x, int y) const {
    cout << "\033[" << (y + 1) << ";" << (x + 1) << "H";
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

void Renderer::draw(int x, int y, char c) {
    if (x >= 0 && x < (int) back_buffer[0].size() && y >= 0 && y < (int) back_buffer.size()) {
        back_buffer[y][x] = c;
    }
}

void Renderer::draw_string(int x, int y, string str) {
    if (x >= 0 && x + (int) str.size() < (int) back_buffer[0].size() && y >= 0 && y < (int) back_buffer.size()) {
        for (int i = 0; i < (int) str.size(); i++) {
            back_buffer[y][x + i] = str[i];
        }
    }
}

void Renderer::render() {
    for (int i = 0; i < (int) back_buffer.size(); i++) {
        for (int j = 0; j < (int) back_buffer[0].size(); j++) {
            if (back_buffer[i][j] != front_buffer[i][j]) {
                move_cursor(j, i);
                cout << back_buffer[i][j];
                front_buffer[i][j] = back_buffer[i][j];
            }
        }    
    }

    reset_cursor();
    hide_cursor();
}