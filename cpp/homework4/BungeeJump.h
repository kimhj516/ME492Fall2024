#pragma once

#include "BungeeJumpParameters.h"
#include <vector>

class BungeeJump {
public:
  BungeeJump(BungeeJumpParameters &parameters);
  ~BungeeJump() = default;

  double compute_acceleration(double current_vertical_velocity,
                              double current_height);
  double compute_vertical_velocity(double current_acceleration,
                                   double current_vertical_velocity);
  double compute_height(double current_velocity, double current_height);
  void simulate_bungee();
  void write(std::string outputfilename);

private:
  BungeeJumpParameters &_parameters;
  std::vector<double> _vertical_acceleration_data;
  std::vector<double> _vertical_velocity_data;
  std::vector<double> _height_data;
};
