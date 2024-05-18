#include <cmath>
#include <iostream>
#include "geometry/geometry.hpp"

struct PolarPoint {
    float r;
    float phi;

    PolarPoint(float r, float phi) noexcept: r(r), phi(phi) {}
};

struct PointAdapter : public CartesianPoint {
    explicit PointAdapter(const PolarPoint &p) noexcept: CartesianPoint() {
        x = p.r * cos(p.phi);
        y = p.r * sin(p.phi);
    }
};

int main() {
    std::cout << "Working with cartesian coordinates" << std::endl;
    auto cartesian_point_1 = new CartesianPoint(12.23, 34.43);
    auto cartesian_point_2 = new CartesianPoint(56.78, 90.12);
    std::cout << distance(cartesian_point_1, cartesian_point_2) << std::endl;

    std::cout << "Working with polar coordinates" << std::endl;
    PolarPoint polar_point_1(42.0, M_PI);
    PolarPoint polar_point_2(42.0, M_PI / 2);
    PointAdapter adapted_point_1(polar_point_1);
    PointAdapter adapted_point_2(polar_point_2);
    std::cout << distance(std::addressof(adapted_point_1), std::addressof(adapted_point_2));
}
