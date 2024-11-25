#include "GeometryData.h"
#include "GeometryWriter.h"
#include <array>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>


GeometryWriter::GeometryWriter(
    GeometryData& geometry_data) :
    _geometry_data(geometry_data)
{
}


void GeometryWriter::write_coordinates_and_distance(std::vector<double> distance, std::string output_file)
{
    if (static_cast<int>(distance.size()) != _geometry_data.number_of_points())
    {
        throw "Input distance array does not match with the number of points of the GeometryData";
    }

    try
    {
        std::ofstream fout;
        fout.exceptions(std::fstream::badbit);
        fout.open(output_file.c_str(), std::ios_base::out);
        std::vector<double> coordinates = _geometry_data.coordinates();
        for (int i = 0; i < _geometry_data.number_of_points(); ++i)
        {
            fout << coordinates[3 * i + 0] << " " << coordinates[3 * i + 1] << " " << coordinates[3 * i + 2] << " " << distance[i] << std::endl;
        }
        fout.close();
    }
    catch (const std::string& exception)
    {
        std::cerr << exception << std::endl;
    }
}
