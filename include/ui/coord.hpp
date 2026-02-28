#pragma once 

struct Coord {
    int x;
    int y;

    Coord(int x, int y) : x(x), y(y) {} 

    bool operator == (const Coord &other) const {
        return x == other.x && y == other.y;
    }

    Coord operator + (const Coord &other) const {
        return Coord(x + other.x, y + other.y);
    }

    Coord operator - (const Coord &other) const {
        return Coord(x - other.x, y - other.y);
    }

    Coord& operator += (const Coord &other) {
        x += other.x;
        y += other.y;
        return *this;
    }

    Coord& operator -= (const Coord &other) {
        x -= other.x;
        y -= other.y;
        return *this;
    }
};