#pragma once 

#include "core/game.hpp"
#include "nlohmann/json_fwd.hpp"

struct SaveManager {
    nlohmann::json load_file(const std::string &FILE_NAME) const;

    void save_file(const Game &game, const std::string &FILE_NAME) const;
};