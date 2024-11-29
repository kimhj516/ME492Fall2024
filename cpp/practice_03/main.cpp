#include "GeometryData.h"
#include "GeometryReader.h"
#include "GeometryWriter.h"
#include "MathFunctions.h"
#include <boost/algorithm/string/predicate.hpp>
#include <boost/algorithm/string/trim.hpp>
#include <boost/filesystem.hpp>
#include <boost/program_options.hpp>
#include <iostream>
#include <vector>


std::array<double, 3> compute_centroid(GeometryData& geometry_data)
{
    return {0.0, 0.0, 0.0};
}


std::vector<double> compute_distance_from_centroid(GeometryData& geometry_data, std::array<double, 3>& centroid)
{
    return std::vector<double>(geometry_data.number_of_points());
}


int main (int argc, char *argv[])
{
    time_t start_time = time(&start_time);
    std::string input_file;
    std::string output_file;
    boost::program_options::options_description command_line_options("Command line options");
    command_line_options.add_options()
        ("input_file",
         boost::program_options::value<std::string>(&input_file),
         "input text file - containing x, y, z coordinates")
        ("output_file",
         boost::program_options::value<std::string>(&output_file),
         "output text file - containing x, y, z, and distance")
        ("help", "Print usage");

    boost::program_options::variables_map config_map;

    try
    {
        store(boost::program_options::parse_command_line(argc, argv, command_line_options), config_map);
        notify(config_map);
    }
    catch (const std::exception& ex)
    {
        std::cerr << "Error: " << ex.what() << std::endl;
        return 1;
    }
    if (config_map.count("help"))
    {
        std::cerr << "Usage: " << command_line_options << std::endl;
        return 1;
    }

    try
    {
        GeometryReader reader;
        GeometryData geometry_data = reader.read(input_file);
        std::array<double, 3> centroid = compute_centroid(geometry_data);
        std::vector<double> distances = compute_distance_from_centroid(geometry_data, centroid);
        GeometryWriter writer(geometry_data);
        writer.write_coordinates_and_distance(distances, output_file);
    }

    catch (const std::string& exception)
    {
        std::cerr << exception << std::endl;
        return 1;
    }
    catch (const char* exception)
    {
        std::cerr << exception << std::endl;
        return 1;
    }

    time_t end_time = time(&end_time);
    std::cout << "Practice_03: duration: " << end_time - start_time << " seconds" << std::endl;
    return 0;
}
