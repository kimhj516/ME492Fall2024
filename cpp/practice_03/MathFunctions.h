#pragma once

#include <math.h>
#include <array>


class MathFunctions
{
public:

    MathFunctions() = default;

    double compute_norm(std::array<double, 3> vector_u);
    double compute_dot_product(std::array<double, 3> vector_u, std::array<double, 3> vector_v);

private:
};
