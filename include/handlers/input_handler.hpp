#pragma once

#include "types/game.hpp"
#include "types/screens.hpp"
#include "core/game.hpp"

struct InputHandler {
    GameCommand handle(char key, ScreenType &screen);
};