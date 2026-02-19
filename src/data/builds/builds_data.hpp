#pragma once

#include <string>
#include <vector>

typedef unsigned long long ull;

struct BuildData {
    int id;
    std::string name, desc;
    ull base_val, base_prod;

    BuildData(int id, const std::string &name, const std::string &desc, ull base_val, ull base_prod) : id(id), name(name), desc(desc), base_val(base_val), base_prod(base_prod) {}
};

extern const std::vector<BuildData> BUILDS;