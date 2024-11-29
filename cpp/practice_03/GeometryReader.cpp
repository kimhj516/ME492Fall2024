#include "GeometryData.h"
#include "GeometryReader.h"
#include <boost/algorithm/string/predicate.hpp>
#include <boost/algorithm/string/trim.hpp>
#include <boost/filesystem.hpp>
#include <boost/program_options.hpp>
#include <array>
#include <fstream>
#include <iostream>
#include <math.h>
#include <string>
#include <vector>


GeometryData GeometryReader::read(std::string input_file)
{
    GeometryData geometry_data;

    try
    {
        // read in input_file
        std::ifstream fin;
        fin.exceptions(std::fstream::badbit);
        fin.open(input_file.c_str(), std::ios_base::in);
        std::vector<std::string> input_strings;
        std::cout << "Reading " << input_file << std::endl;
        do
        {
            std::string line;
            getline(fin, line);
            boost::trim(line);
            if (line.size() > 0)
            {
                input_strings.push_back(line);
            }
        } while (!fin.eof());
        std::cout << "Completed reading in the file " << std::endl;
        fin.close();

        // loop over each read-in line and save the vertices into a vector data
        std::vector<double> vertices;
        for (int n = 0; n < static_cast<int>(input_strings.size()); ++n)
        {
            std::istringstream s(input_strings[n]);
            std::array<double, 3> xyz;
            s >> xyz[0] >> xyz[1] >> xyz[2];
            for (int i = 0; i < 3; ++i)
            {
                vertices.push_back(xyz[i]);
            }
        }

        // output vertices for debugging
        int number_of_points = static_cast<int>(static_cast<double>(vertices.size()) / 3);
        for (int i = 0; i < static_cast<int>(vertices.size()) / 3; ++i)
        {
            std::cout << "Input vertex: " << vertices[3 * i + 0] << " " << vertices[3 * i + 1] << " " << vertices[3 * i + 2] << std::endl;
        }
        geometry_data.number_of_points(number_of_points);
        geometry_data.coordinates(vertices);
    }
    catch (const std::string& exception)
    {
        std::cerr << exception << std::endl;
    }
    catch (const char* exception)
    {
        std::cerr << exception << std::endl;
    }
    return geometry_data;
}
