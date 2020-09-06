#ifndef NOISE_H
#define NOISE_H

#include <memory>
#include <cmath>

#include "../Vector3.hpp"
#include "../Texture.hpp"
#include "../Perlin.hpp"

class Noise : public Texture
{
public:
    Noise();
    Noise(float sc);

    virtual Color3 value(float u, float v, const Vector3 &p) const override;

private:
    Perlin _noise;
    float _scale;
};

#endif