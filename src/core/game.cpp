#include "core/game.hpp"
#include "data/builds_data.hpp"
#include "data/upgrades_data.hpp"
#include "production/production.hpp"
#include "nlohmann/json.hpp"
#include <algorithm>

using json = nlohmann::json;

typedef unsigned long long ull;
typedef long long ll;

constexpr int FRAMES = 60;
constexpr int MS_PER_FRAME = 1000 / FRAMES;

Game::Game(const json &json_data) 
    :   name(json_data.value("name", "No name")),
        economy(json_data.value("economy", json::object())),
        inventory(json_data.value("inventory", json::object())),
        effects(json_data.value("effects", json::object())),
        ui(ScreenType::GAME_LOOP, {}, 0),
        curr_production(json_data.value("current_production", 0ULL)),
        dirty_production(false),
        ticks(json_data.value("total_ticks", 0LL)),
        is_running(true)
{
   
}

Game Game::init(const std::string &name) {
    return Game(
        name,
        EconomySystem(0, 0),
        InventorySystem({}, {}),
        EffectSystem({}, false),
        UISystem(ScreenType::MAIN_MENU, {}, 0),
        0,
        false,
        0,
        true
    );
}

void Game::refresh_production() {
    curr_production = production::calc_total_production(inventory, effects);
}

void Game::refresh_production_if_dirty() {
    if (!dirty_production) {
        return;
    }

    refresh_production();

    dirty_production = false;
}

void Game::update_tick(ll delta_time) {
    int remaining_delta = delta_time;
    bool has_effects = !effects.active_effects.empty();

    while (remaining_delta > 0 && has_effects) {
        refresh_production_if_dirty();

        int next_expiry = std::min(remaining_delta, effects.get_min_duration());

        economy.accumulate(curr_production, next_expiry);

        effects.process_time(next_expiry);

        if (effects.has_changed) {
            dirty_production = true;
            has_effects = !effects.active_effects.empty();
            effects.reset_has_changed();
        }

        remaining_delta -= next_expiry;
    }

    refresh_production_if_dirty();

    if (remaining_delta > 0) {
        if (dirty_production) {
            refresh_production_if_dirty();
        }

        economy.accumulate(curr_production, remaining_delta);
    }

    ui.accumulator += delta_time;
    ui.process_particles(ui.accumulator / MS_PER_FRAME);
    ui.accumulator %= MS_PER_FRAME;
    
    ticks += delta_time;
}

void Game::load_save(const json &json_save) {
    name = json_save.value("name", "No name");
    
    economy = EconomySystem(json_save.value("economy", json::object()));
    inventory = InventorySystem(json_save.value("inventory", json::object()));
    effects = EffectSystem(json_save.value("effects", json::object()));
    ui = UISystem(ScreenType::GAME_LOOP, {}, 0);

    refresh_production();

    dirty_production = false;

    ticks = json_save.value("total_ticks", 0);

    ll now = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    ll last_save = json_save.value("last_save", 0LL);
    ll delta = now - last_save;

    if (last_save > 0LL) {
        ll delta = now - last_save;
        ll delta_ticks = delta / 16LL;
        update_tick(delta_ticks);
    }
}

json Game::to_json() const {
    json json_game;

    json_game["name"] = name;

    json_game["economy"] = economy.to_json();
    json_game["inventory"] = inventory.to_json();
    json_game["effects"] = effects.to_json();

    json_game["total_ticks"] = ticks;

    auto now = std::chrono::system_clock::now();
    auto epoch = now.time_since_epoch();
    auto time_ms = std::chrono::duration_cast<std::chrono::milliseconds>(epoch).count();

    json_game["last_save"] = time_ms;

    return json_game;
}

void Game::exit() {
    is_running = false;
}