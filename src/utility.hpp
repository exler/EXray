#ifndef UTILITY_H
#define UTILITY_H

#include <cmath>
#include <limits>

// Constants
constexpr double infinity = std::numeric_limits<double>::infinity();
constexpr double pi = 3.14159265358979323846;

// Functions
inline float degrees_to_radias(double degrees)
{
    return degrees * M_PI / 180;
}

#endif