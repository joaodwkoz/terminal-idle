#include "ui/renderer.hpp"

Renderer::Renderer() {
    int width;
    int height;

    get_terminal_size(width, height);

    back_buffer.assign(height, std::string(width, ' '));
    front_buffer.assign(height, std::string(width, ' '));

    screens[ScreenType::MAIN_MENU] = &Renderer::draw_menu;
    screens[ScreenType::GAME_LOOP] = &Renderer::draw_game_loop;
    screens[ScreenType::SHOP] = &Renderer::draw_shop;
    screens[ScreenType::UPGRADES] = &Renderer::draw_upgrades;

    std::cout << "\033[2J\033[1;1H";
    
    hide_cursor();
    reset_cursor();
}

void Renderer::show_cursor() const {
    std::cout << "\033[?25h";
}

void Renderer::hide_cursor() const {
    std::cout << "\033[?25l";
}

void Renderer::reset_cursor() const {
    std::cout << "\033[H";
}

void Renderer::move_cursor(const Coord &coord) const {
    std::cout << "\033[" << (coord.y + 1) << ";" << (coord.x + 1) << "H";
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

void Renderer::draw_string(const Coord &coord, const std::string &str) {
    if (coord.x >= 0 && coord.x + (int) str.size() < (int) back_buffer[0].size() && coord.y >= 0 && coord.y < (int) back_buffer.size()) {
        for (int i = 0; i < (int) str.size(); i++) {
            back_buffer[coord.y][coord.x + i] = str[i];
        }
    }
}

void Renderer::draw_menu(const Game &Game) {
    /* EM BREVE */
}

void Renderer::draw_game_loop(const Game &Game) {
    /* EM BREVE */
}

void Renderer::draw_shop(const Game &Game) {
    /* EM BREVE */
}

void Renderer::draw_upgrades(const Game &Game) {
    /* EM BREVE */
}

void Renderer::draw_screen(const ScreenType &type, const Game &game) {
    if (screens.count(type)) {
        (this->*screens[type])(game);
    }
}

void Renderer::render(const Game &game) {
    clear();

    draw_screen(game.ui.current_screen, game);

    for (int i = 0; i < (int) back_buffer.size(); i++) {
        for (int j = 0; j < (int) back_buffer[0].size(); j++) {
            if (back_buffer[i][j] != front_buffer[i][j]) {
                move_cursor(Coord(j, i));
                std::cout << back_buffer[i][j];
                front_buffer[i][j] = back_buffer[i][j];
            }
        }    
    }

    reset_cursor();
    hide_cursor();
}