#include <cmath>
#include "geometry.hpp"

double distance(CartesianPoint* p1, CartesianPoint* p2) noexcept {
    return sqrt(pow(p2->x - p1->x, 2) + pow(p2->y - p1->y, 2));
}
