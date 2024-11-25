#include "BungeeJumpParameters.h"

double BungeeJumpParameters::gravitational_acceleration() const {
  return _gravitational_acceleration;
}

// construct a function outputing the parameter value
double BungeeJumpParameters::mass() { return _mass; }

double BungeeJumpParameters::drag_coefficient() { return _drag_coefficient; }

double BungeeJumpParameters::initial_vertical_velocity() {
  return _initial_vertical_velocity;
}

double BungeeJumpParameters::initial_height() { return _initial_height; }

double BungeeJumpParameters::bottom_height() { return _bottom_height; }

double BungeeJumpParameters::spring_constant() { return _spring_constant; }

double BungeeJumpParameters::cord_length() { return _cord_length; }

double BungeeJumpParameters::time_step_size() { return _time_step_size; }

double BungeeJumpParameters::maximum_time() { return _maximum_time; }

void BungeeJumpParameters::gravitational_acceleration(double acceleration) {
  _gravitational_acceleration = acceleration;
}

// construct a function saving the inputted parameter value
void BungeeJumpParameters::mass(double mass) { _mass = mass; }

void BungeeJumpParameters::drag_coefficient(double drag_coefficient) {
  _drag_coefficient = drag_coefficient;
}

void BungeeJumpParameters::initial_vertical_velocity(double velocity) {
  _initial_vertical_velocity = velocity;
}

void BungeeJumpParameters::initial_height(double initial_height) {
  _initial_height = initial_height;
}

void BungeeJumpParameters::bottom_height(double bottom_height) {
  _bottom_height = bottom_height;
}

void BungeeJumpParameters::spring_constant(double spring_constant) {
  _spring_constant = spring_constant;
}

void BungeeJumpParameters::cord_length(double cord_length) {
  _cord_length = cord_length;
}

void BungeeJumpParameters::time_step_size(double time_step_size) {
  _time_step_size = time_step_size;
}

void BungeeJumpParameters::maximum_time(double maximum_time) {
  _maximum_time = maximum_time;
}
