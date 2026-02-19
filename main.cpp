#include <iostream>
#include <conio.h>
#include <chrono>
#include <thread>
#include <map>
#include <vector>

using namespace std;

enum class EFFECT_TYPE {
    MULTIPLIER,
    BUILD
};

enum class EFFECT_TARGET {
    GLOBAL_PROD,
    BUILD,
};

struct Effect {
    int id;
    string name, desc;
    EFFECT_TYPE type;
    EFFECT_TARGET target;
    int target_id;
    double value;
    int duration;

    Effect(int id, const string &name, const string &desc, EFFECT_TYPE type, EFFECT_TARGET target, int target_id, double value, int duration) : id(id), name(name), desc(desc), type(type), target(target), target_id(target_id), value(value), duration(duration) {}
};

struct Build {
    int id;
    string name;
    string desc;
    int base_prod;
    int quantity;

    Build(int id, const string &name, const string &desc, int base_prod, int quantity) : id(id), name(name), desc(desc), base_prod(base_prod), quantity(quantity) {}
};

struct Upgrade {
    int id;
    vector<Effect> effects;

    Upgrade(int id, const vector<Effect> &effects) : id(id), effects(effects) {}
};

struct UpgradeTarget {
    EFFECT_TARGET type;
    int id;

    bool operator < (const UpgradeTarget &other) const {
        if (type != other.type) {
            return (int) type < (int) other.type;
        }
        return id < other.id;
    }
};

struct Shop {
    map<UpgradeTarget, vector<Upgrade>> available_upgrades;
    map<UpgradeTarget, vector<Upgrade>> all_upgrades;

    Shop(const map<UpgradeTarget, vector<Upgrade>> &available_upgrades, const map<UpgradeTarget, vector<Upgrade>> &all_upgrades) : available_upgrades(available_upgrades), all_upgrades(all_upgrades) {}
};

struct Game {
    string terminalName;
    int score;
    Shop shop;
    vector<Upgrade> purchased_upgrades;
    vector<Effect> active_effects;
    vector<Build> builds;

    Game(const string &terminalName, int score, Shop shop, const vector<Upgrade> &purchased_upgrades, const vector<Effect> &active_effects, const vector<Build> &builds) : terminalName(terminalName), score(score), shop(shop), purchased_upgrades(purchased_upgrades), active_effects(active_effects), builds(builds) {}
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    /* Loop temporário para testar execução */
    
    int timer = 0;

    while (true) {
        cout << "O programa esta rodando por " << timer << " segundos!" << endl; 
        timer++;
        this_thread::sleep_for(chrono::seconds(1));
    }

    return 0;
}
