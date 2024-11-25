#pragma once

#include "GeometryData.h"
#include <array>
#include <string>
#include <vector>


class GeometryWriter
{
public:

    GeometryWriter(GeometryData& geometry_data);
    ~GeometryWriter() = default;

    void write_coordinates_and_distance(std::vector<double> distance, std::string coordinatefile);

private:

    GeometryData&  _geometry_data;
};
