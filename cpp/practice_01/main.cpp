#include <boost/algorithm/string/predicate.hpp>
#include <boost/algorithm/string/trim.hpp>
#include <boost/filesystem.hpp>
#include <boost/program_options.hpp>
#include <fstream>
#include <iostream>
#include <vector>


std::vector<double> readInputFile(std::string input_file)
{
    std::vector<double> vertices;

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
        for (int i = 0; i < static_cast<int>(vertices.size()) / 3; ++i)
        {
            std::cout << "Input vertex: " << vertices[3 * i + 0] << " " << vertices[3 * i + 1] << " " << vertices[3 * i + 2] << std::endl;
        }
    }
    catch (const std::string& exception)
    {
        std::cerr << exception << std::endl;
    }
    catch (const char* exception)
    {
        std::cerr << exception << std::endl;
    }
    return vertices;
}


std::vector<double> scaleData(std::vector<double> vertices, double scale_factor)
{
    return vertices;
}


void writeFile(std::vector<double> scaled_vertices, std::string output_file)
{
    try
    {
        std::ofstream fout;
        fout.exceptions(std::fstream::badbit);
        fout.open(output_file.c_str(), std::ios_base::out);
        for (int i = 0; i < static_cast<int>(scaled_vertices.size()) / 3; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                fout << scaled_vertices[3 * i + j] << " ";
            }
            fout << std::endl;
        }
        fout.close();
    }
    catch (const std::string& exception)
    {
        std::cerr << exception << std::endl;
    }
}


int main (int argc, char *argv[])
{
    time_t start_time = time(&start_time);

    std::string input_file;
    std::string output_file;
    double scale_factor = 1.0;

    boost::program_options::options_description command_line_options("Command line options");
    command_line_options.add_options()
        ("input_file",
         boost::program_options::value<std::string>(&input_file),
         "input text file - containing x, y, z coordinates")
        ("output_file",
         boost::program_options::value<std::string>(&output_file),
         "output file after scaling - containing x, y, z coordinates")
        ("scale_factor",
         boost::program_options::value<double>(&scale_factor)->default_value(1.0),
         "input scale factor - default value is 1.0")
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
    if (!boost::filesystem::exists(input_file))
    {
        std::cerr << "Error: file " << input_file << " does not exist" << std::endl;
        return 1;
    }

    try
    {
        std::vector<double> vertices = readInputFile(input_file);
        std::vector<double> scaled_vertices = scaleData(vertices, scale_factor);
        writeFile(scaled_vertices, output_file);
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
