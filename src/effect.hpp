enum class EFFECT_TYPE {
    MULTIPLIER,
    BUILD
};

enum class EFFECT_TARGET {
    GLOBAL_PROD,
    BUILD,
};

struct Effect {
    int id, target_id, duration;
    EFFECT_TYPE type;
    EFFECT_TARGET target;
    double value;

    Effect(int id, EFFECT_TYPE type, EFFECT_TARGET target, int target_id, double value, int duration) : id(id), type(type), target(target), target_id(target_id), value(value), duration(duration) {}
};