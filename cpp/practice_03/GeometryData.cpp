#include "GeometryData.h"
#include <array>
#include <vector>


std::array<double, 3> GeometryData::coordinate_of_point(int n)
{
    if (n < 0 || n > _number_of_points - 1)
    {
        throw "Input point number is not within the range of the input data";
    }
    std::array<double, 3> xyz = {_coordinates[3*n+0], _coordinates[3*n+1], _coordinates[3*n+1]};
    return xyz;
}
