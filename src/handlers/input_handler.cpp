#include "handlers/input_handler.hpp"
#include "types/game.hpp"

GameCommand InputHandler::handle(char key, ScreenType &screen) {
    switch (screen) {
        case ScreenType::MAIN_MENU:
            switch (key) {
                case '1':
                    return GameCommand::START_GAME;
                case '2':
                    return GameCommand::LOAD_SAVE;
                case '3':
                    return GameCommand::EXIT_GAME;
            }
        default:
            switch (key) {
                case '1':
                    return GameCommand::START_GAME;
                case '2':
                    return GameCommand::LOAD_SAVE;
                case '3':
                    return GameCommand::EXIT_GAME;
            }
    }
}