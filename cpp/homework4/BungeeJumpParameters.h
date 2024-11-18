#pragma once

#include <iostream>
#include <vector>


struct BungeeJumpParameters
{
public:

    BungeeJumpParameters() = default;

    double gravitational_acceleration() const; 
    // construct a function outputing the parameter value
    double mass();
    double drag_coefficient();
    double initial_vertical_velocity();
    double initial_height();
    double bottom_height();
    double spring_constant();
    double cord_length();
    double time_step_size();
    double maximum_time();
    void gravitational_acceleration(double acceleration);
    // construct a function saving the inputted parameter value 
    void mass(double mass);
    void drag_coefficient(double drag_coefficient);
    void initial_vertical_velocity(double velocity);
    void initial_height(double initial_height);
    void bottom_height(double bottom_height);
    void spring_constant(double spring_constant);
    void cord_length(double cord_length);
    void time_step_size(double time_step_size);
    void maximum_time(double maximum_time);

private:

    double  _gravitational_acceleration;
    double  _mass;
    double  _drag_coefficient;
    double  _initial_vertical_velocity;
    double  _initial_height;
    double  _bottom_height;
    double  _spring_constant;
    double  _cord_length;
    double  _time_step_size;
    double  _maximum_time;
};
