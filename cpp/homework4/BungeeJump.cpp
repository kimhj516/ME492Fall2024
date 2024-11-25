#include "BungeeJump.h"
#include "BungeeJumpParameters.h"
#include <fstream>
#include <iostream>
#include <math.h>
#include <vector>


BungeeJump::BungeeJump(BungeeJumpParameters& parameters) :
    _parameters(parameters)
{
}

// construct a function of computing the acceleration at t_n when the velocity at t_n and the height at t_n are inputted
double BungeeJump::compute_acceleration(double current_vertical_velocity, double current_height)
{
    return - _parameters.gravitational_acceleration();
}


// construct a function of computing the vertical velocity at t_(n+1) when the acceleration and the velocity at t_n are inputted
double BungeeJump::compute_vertical_velocity(double current_acceleration, double current_vertical_velocity)
{
    return _parameters.initial_vertical_velocity();
}


// construct a function of computing the vertical height at t_(n+1) when the velocity and the height at t_n are inputted
double BungeeJump::compute_height(double current_velocity, double current_height)
{
    return _parameters.initial_height();
}


// construct a function of simulating bungee-jump as time increments starting from zero to maximum_time
// The computed acceleration, velocity, and height need to be saved as vector data
void BungeeJump::simulate_bungee()
{
}


// construct a function of writing the simulation results into a csv file format
// The csv file should contain time, acceleration, velocity, and height information for the time between zero and the maximum time
void BungeeJump::write(std::string outputfilename)
{
}
