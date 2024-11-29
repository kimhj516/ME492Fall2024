#pragma once

#include <array>
#include <vector>


class GeometryData
{
public:

    GeometryData() = default;

    void number_of_points(int number_of_points) { _number_of_points = number_of_points; };
    void coordinates(std::vector<double> coordinates) { _coordinates = coordinates; };
    int number_of_points() const { return _number_of_points; };
    std::vector<double> coordinates() const { return _coordinates; };
    std::array<double, 3> coordinate_of_point(int n);

private:

    int _number_of_points;
    std::vector<double> _coordinates;
};
