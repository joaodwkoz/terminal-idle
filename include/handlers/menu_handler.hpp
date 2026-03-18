#pragma once

#include "types/game.hpp"
#include "core/game.hpp"
#include "systems/save_manager.hpp"

struct MenuHandler {
    void execute(GameCommand &command, Game &game, const SaveManager &save);
};