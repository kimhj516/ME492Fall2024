#include "BungeeJump.h"
#include "BungeeJumpParameters.h"
#include <fstream>
#include <iostream>
#include <math.h>
#include <string>

BungeeJump::BungeeJump(BungeeJumpParameters &parameters)
    : _parameters(parameters) {}

// construct a function of computing the acceleration at t_n when the velocity
// at t_n and the height at t_n are inputted
double BungeeJump::compute_acceleration(double current_vertical_velocity,
                                        double current_height) {
  auto v = current_vertical_velocity;
  auto l = _parameters.cord_length();
  auto y0 = _parameters.initial_height();
  auto k = _parameters.spring_constant();
  double f_c;
  if (current_height < y0 - l) {
    f_c = -k * (current_height - y0 + l);
  } else if (current_height > y0 + l) {
    f_c = -k * (current_height - y0 - l);
  } else {
    f_c = 0.0;
  }
  auto drag_coeff = _parameters.drag_coefficient();
  auto m = _parameters.mass();
  auto g = _parameters.gravitational_acceleration();

  return (m * g - drag_coeff * v * abs(v) + f_c) / m;
}

// construct a function of computing the vertical velocity at t_(n+1) when the
// acceleration and the velocity at t_n are inputted
double BungeeJump::compute_vertical_velocity(double current_acceleration,
                                             double current_vertical_velocity) {
  return current_vertical_velocity +
         current_acceleration * _parameters.time_step_size();
}

// construct a function of computing the vertical height at t_(n+1) when the
// velocity and the height at t_n are inputted
double BungeeJump::compute_height(double current_velocity,
                                  double current_height) {
  return current_height + current_velocity * _parameters.time_step_size();
}

// construct a function of simulating bungee-jump as time increments starting
// from zero to maximum_time The computed acceleration, velocity, and height
// need to be saved as vector data
void BungeeJump::simulate_bungee() {
  double current_height = _parameters.initial_height();
  double current_velocity = _parameters.initial_vertical_velocity();
  double current_acceleration;
  double t = 0.0;
  while (t < _parameters.maximum_time()) {
    current_acceleration =
        compute_acceleration(current_velocity, current_height);
    _vertical_acceleration_data.push_back(current_acceleration);

    current_velocity =
        compute_vertical_velocity(current_acceleration, current_velocity);
    _vertical_velocity_data.push_back(current_velocity);

    current_height = compute_height(current_velocity, current_height);
    _height_data.push_back(current_height);

    t += _parameters.time_step_size();
  }
}

// construct a function of writing the simulation results into a csv file format
// The csv file should contain time, acceleration, velocity, and height
// information for the time between zero and the maximum time
void BungeeJump::write(std::string outputfilename) {
  std::ofstream output_file(outputfilename);
  output_file << "time,acceleration,velocity,height" << std::endl;
  double t = 0.0;
  for (unsigned i = 0; i < _vertical_acceleration_data.size(); i++) {
    output_file << t << "," << _vertical_acceleration_data[i] << ","
                << _vertical_velocity_data[i] << "," << _height_data[i]
                << std::endl;
    t += _parameters.time_step_size();
  }
}
