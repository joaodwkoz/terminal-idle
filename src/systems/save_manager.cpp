#include <fstream>
#include <iomanip>
#include "systems/save_manager.hpp"
#include "nlohmann/json.hpp"

using json = nlohmann::json;

json SaveManager::load_file(const std::string &FILE_NAME) const {
    std::ifstream file(FILE_NAME);

    json data;
    if (file.is_open()) {
        data = json::parse(file, nullptr, false);
    }

    if (data.is_discarded() || data.empty()) {
        return json();
    }

    return data;
}

void SaveManager::save_file(const Game &game, const std::string &FILE_NAME) const {
    std::ofstream file(FILE_NAME);

    json json_game = game.to_json();

    if (file.is_open()) {
        file << std::setw(4) << json_game << std::endl;
    }
}