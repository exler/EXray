#ifndef UTILITY_H
#define UTILITY_H

#include <random>
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
inline float random_float()
{
    // Returns a random real number in [0, 1)
    std::uniform_real_distribution<float> distribution(0.0, 1.0);
    std::mt19937 gen;
    return distribution(gen);
}
inline float random_float(float min, float max)
{
    // Returns a random real number in [min, max)
    std::uniform_real_distribution<float> distribution(min, max);
    std::mt19937 gen;
    return distribution(gen);
}

#endif