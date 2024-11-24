#include "BungeeJump.h"
#include "BungeeJumpParameters.h"
#include <boost/algorithm/string/predicate.hpp>
#include <boost/algorithm/string/trim.hpp>
#include <boost/filesystem.hpp>
#include <boost/program_options.hpp>
#include <iostream>

int main(int argc, char *argv[]) {
  double acceleration = 0.0;
  double mass = 0.0;
  double drag_coefficient = 0.0;
  double initial_height = 0.0;
  double bottom_height = 0.0;
  double initial_vertical_velocity = 0.0;
  double spring_constant = 0.0;
  double cord_length = 0.0;
  double time_step_size = 0.0;
  double maximum_time = 0.0;
  std::string outputfilename = "";

  boost::program_options::options_description command_line_options(
      "Command line options");
  command_line_options.add_options()(
      "acceleration",
      boost::program_options::value<double>(&acceleration)
          ->default_value(-9.81),
      "input gravitational acceleration")(
      "mass", boost::program_options::value<double>(&mass)->default_value(80.0),
      "input bungee jumper's mass")(
      "drag_coefficient",
      boost::program_options::value<double>(&drag_coefficient)
          ->default_value(0.25),
      "input drag coefficient")(
      "initial_vertical_velocity",
      boost::program_options::value<double>(&initial_vertical_velocity)
          ->default_value(0.0),
      "input initial vertical velocity")(
      "initial_height",
      boost::program_options::value<double>(&initial_height)
          ->default_value(250.0),
      "input initial height")(
      "bottom_height",
      boost::program_options::value<double>(&bottom_height)
          ->default_value(10.0),
      "input bottom height")(
      "spring_constant",
      boost::program_options::value<double>(&spring_constant)
          ->default_value(10.0),
      "input spring constant")(
      "cord_length",
      boost::program_options::value<double>(&cord_length)->default_value(200.0),
      "input cord length")(
      "time_step_size",
      boost::program_options::value<double>(&time_step_size)
          ->default_value(0.01),
      "input time step size (delta t)")(
      "maximum_time",
      boost::program_options::value<double>(&maximum_time)->default_value(20.0),
      "input maximum time to execute the simulation")(
      "outputfilename",
      boost::program_options::value<std::string>(&outputfilename)
          ->default_value(""),
      "input output filename")("help", "Print usage");

  boost::program_options::variables_map config_map;

  try {
    store(boost::program_options::parse_command_line(argc, argv,
                                                     command_line_options),
          config_map);
    notify(config_map);
  } catch (const std::exception &ex) {
    std::cerr << "Error: " << ex.what() << std::endl;
    return 1;
  }
  if (config_map.count("help")) {
    std::cerr << "Usage: " << command_line_options << std::endl;
    return 1;
  }

  try {
    BungeeJumpParameters parameters;
    parameters.gravitational_acceleration(acceleration);
    parameters.mass(mass);
    parameters.drag_coefficient(drag_coefficient);
    parameters.initial_height(initial_height);
    parameters.bottom_height(bottom_height);
    parameters.initial_vertical_velocity(initial_vertical_velocity);
    parameters.spring_constant(spring_constant);
    parameters.cord_length(cord_length);
    parameters.time_step_size(time_step_size);
    parameters.maximum_time(maximum_time);

    BungeeJump bungee(parameters);
    bungee.simulate_bungee();
    if (outputfilename != "") {
      bungee.write(outputfilename);
    }
  }

  catch (const std::string &exception) {
    std::cerr << exception << std::endl;
    return 1;
  } catch (const char *exception) {
    std::cerr << exception << std::endl;
    return 1;
  }

  return 0;
}
