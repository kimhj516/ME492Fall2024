#pragma once

#include <math.h>
#include <array>


class MathFunctions
{
public:

    MathFunctions() = default;

    int compute_factorial(int n);
    double compute_dot_product(std::array<double, 3> vector_u, std::array<double, 3> vector_v);
    std::array<double, 3> compute_cross_product(std::array<double, 3> vector_u, std::array<double, 3> vector_v);

private:
};
