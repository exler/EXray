#ifndef TEXTURE_H
#define TEXTURE_H

#include "Vector3.hpp"

class Texture
{
public:
    virtual Color3 value(float u, float v, const Vector3 &p) const = 0;
};

class SolidColor : public Texture
{
public:
    SolidColor();
    SolidColor(Color3 c);

    SolidColor(float r, float g, float b);

    virtual Color3 value(float u, float v, const Vector3 &p) const override;

private:
    Color3 color_value;
};

#endif