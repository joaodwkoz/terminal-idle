#pragma once

enum class UpgradeTarget {
    BUILD,
    GLOBAL,
};

enum class UpgradeState {
    LOCKED,
    VISIBLE,
    AVAILABLE,
    PURCHASABLE,
};