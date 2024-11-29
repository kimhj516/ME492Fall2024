#include "BungeeJump.h"
#include "BungeeJumpParameters.h"
#include <fstream>
#include <iostream>
#include <cmath>
#include <vector>

BungeeJump::BungeeJump(BungeeJumpParameters& parameters) :
    _parameters(parameters)
{
}

// construct a function of computing the acceleration at t_n when the velocity at t_n and the height at t_n are inputted
double BungeeJump::compute_acceleration(double current_vertical_velocity, double current_height)
{
    double y0 = _parameters.initial_height();
    double L = _parameters.cord_length();
    double vn = current_vertical_velocity;
    double yn = current_height;
    double an;
    double g = _parameters.gravitational_acceleration();
    double C = _parameters.drag_coefficient();
    double m = _parameters.mass();
    double k = _parameters.spring_constant();
    if(y0 - L < yn){
        std::cout<<"before L// ";
        an = g -0.5*C*std::fabs(vn)*vn/m;
    } else{
        std::cout<<"after L// ";
        an = g - 0.5*C*std::fabs(vn)*vn/m - k*(yn-y0+L)/m;
    }
    return an;
}

// construct a function of computing the vertical velocity at t_(n+1) when the acceleration and the velocity at t_n are inputted
double BungeeJump::compute_vertical_velocity(double current_acceleration, double current_vertical_velocity)
{
    double vn = current_vertical_velocity;
    double an = current_acceleration;
    double dt = _parameters.time_step_size();
    return vn+an*dt;
}

// construct a function of computing the vertical height at t_(n+1) when the velocity and the height at t_n are inputted
double BungeeJump::compute_height(double current_velocity, double current_height)
{
    double yn = current_height;
    double vn = current_velocity;
    double dt = _parameters.time_step_size();
    return yn+vn*dt;
}

// construct a function of simulating bungee-jump as time increments starting from zero to maximum_time
// The computed acceleration, velocity, and height need to be saved as vector data
void BungeeJump::simulate_bungee()
{
    double tmax = _parameters.maximum_time();
    double dt = _parameters.time_step_size();
    int n=0;
    // initialization
    _height_data.push_back(_parameters.initial_height());
    _vertical_velocity_data.push_back(_parameters.initial_vertical_velocity());

    _vertical_acceleration_data.push_back(compute_acceleration(_vertical_velocity_data[0], _height_data[0]));
    while (n*dt<tmax)
    {
        // n: current time
        // appends n+1 data
        _height_data.push_back(compute_height(_vertical_velocity_data[n], _height_data[n]));
        _vertical_velocity_data.push_back(compute_vertical_velocity(_vertical_velocity_data[n], _vertical_acceleration_data[n]));
        _vertical_acceleration_data.push_back(compute_acceleration( _vertical_velocity_data[n], _height_data[n]));
        n++;
    }
    write("simulation_result.csv");
}

// construct a function of writing the simulation results into a csv file format
// The csv file should contain time, acceleration, velocity, and height information for the time between zero and the maximum time
void BungeeJump::write(std::string outputfilename)
{
    std::ofstream outputFile(outputfilename);
    if (!outputFile.is_open()) {
        std::cerr << "Error: Could not open the file " << outputfilename << std::endl;
        return;
    }
    outputFile << "Time,Acceleration,Velocity,Height\n";
    int size = _height_data.size();
    for (size_t i = 0; i < size; ++i) {
        // Assuming time step is uniform, starting from 0, you can replace this with your actual time data
        double time = i * _parameters.time_step_size();  // Example: assuming a time step of 0.1 seconds
        outputFile << time << "," << _vertical_acceleration_data[i] << "," << _vertical_velocity_data[i] << "," << _height_data[i] << "\n";
    }
    outputFile.close();
}
