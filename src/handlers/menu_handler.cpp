#include "handlers/menu_handler.hpp"
#include "types/game.hpp"
#include "core/game.hpp"

void MenuHandler::execute(GameCommand &command, Game &game, const SaveManager &save) {
    switch (command) {
        case GameCommand::START_GAME:
            game.ui.set_screen(ScreenType::GAME_LOOP);
            break;
        case GameCommand::LOAD_SAVE:
            auto save_data = save.load_file("save.json");
            game.load_save(save_data);
            game.ui.set_screen(ScreenType::GAME_LOOP);
            break;
        case GameCommand::EXIT_GAME:
            game.exit();
            break;
        default:
            game.ui.set_screen(ScreenType::GAME_LOOP);
            break;
    }
}