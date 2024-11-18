#include "BungeeJumpParameters.h"
#include <iostream>
#include <vector>


double BungeeJumpParameters::gravitational_acceleration() const
{
    return _gravitational_acceleration;
}

// construct a function outputing the parameter value
double BungeeJumpParameters::mass()
{
}

double BungeeJumpParameters::drag_coefficient()
{
}

double BungeeJumpParameters::initial_vertical_velocity()
{
}

double BungeeJumpParameters::initial_height()
{
}

double BungeeJumpParameters::bottom_height()
{
}

double BungeeJumpParameters::spring_constant()
{
}

double BungeeJumpParameters::cord_length()
{
}

double BungeeJumpParameters::time_step_size()
{
}

double BungeeJumpParameters::maximum_time()
{
}

void BungeeJumpParameters::gravitational_acceleration(double acceleration)
{
    _gravitational_acceleration = acceleration;
}

// construct a function saving the inputted parameter value 
void BungeeJumpParameters::mass(double mass)
{
}

void BungeeJumpParameters::drag_coefficient(double drag_coefficient)
{
}

void BungeeJumpParameters::initial_vertical_velocity(double velocity)
{
}

void BungeeJumpParameters::initial_height(double initial_height)
{
}

void BungeeJumpParameters::bottom_height(double bottom_height)
{
}

void BungeeJumpParameters::spring_constant(double spring_constant)
{
}

void BungeeJumpParameters::cord_length(double cord_length)
{
}

void BungeeJumpParameters::time_step_size(double time_step_size)
{
}

void BungeeJumpParameters::maximum_time(double maximum_time)
{
}
