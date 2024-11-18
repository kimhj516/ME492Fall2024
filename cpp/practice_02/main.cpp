#include "MathFunctions.h"
#include <boost/algorithm/string/predicate.hpp>
#include <boost/algorithm/string/trim.hpp>
#include <boost/filesystem.hpp>
#include <boost/program_options.hpp>
#include <iostream>
#include <vector>


int main (int argc, char *argv[])
{
    time_t start_time = time(&start_time);

    boost::program_options::options_description command_line_options("Command line options");
    command_line_options.add_options()
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
        MathFunctions mfs;
        std::cout << "Factorial: " << mfs.compute_factorial(10) << std::endl;
        std::array<double, 3> vector_u = {1.0, 0.0, 0.0};
        std::array<double, 3> vector_v = {0.0, 1.0, 0.0};
        std::cout << "Dot product: " << mfs.compute_dot_product(vector_u, vector_v) << std::endl;
        std::array<double, 3> cross_vector = mfs.compute_cross_product(vector_u, vector_v);
        std::cout << "Cross product: " << cross_vector[0] << " " << cross_vector[1] << " " << cross_vector[2] << std::endl;
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
    std::cout << "Practice_01: duration: " << end_time - start_time << " seconds" << std::endl;
    return 0;
}
