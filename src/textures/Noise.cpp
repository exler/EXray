#include "Noise.hpp"

Noise::Noise() {}
Noise::Noise(float sc) : _scale(sc) {}

Color3 Noise::value(float u, float v, const Vector3 &p) const
{
    return Color3(1, 1, 1) * 0.5 * (1 + sin(_scale * p.z() + 10 * _noise.turbulence(p)));
}