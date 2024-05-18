#pragma once

struct CartesianPoint {
    float x, y;
    CartesianPoint() = default;
    CartesianPoint(float x, float y) : x(x), y(y) {};
};

double distance(CartesianPoint* p1, CartesianPoint* p2) noexcept;
