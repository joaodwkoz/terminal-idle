#include <fstream>
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