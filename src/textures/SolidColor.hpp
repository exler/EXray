#ifndef SOLID_COLOR_H
#define SOLID_COLOR_H

#include "../Vector3.hpp"
#include "../Texture.hpp"

class SolidColor : public Texture
{
public:
    SolidColor(Color3 c) : color_value(c) {}
    SolidColor(float r, float g, float b) : SolidColor(Color3(r, g, b)) {}

    virtual Color3 value(float u, float v) const override
    {
        return color_value;
    }

private:
    Color3 color_value;
};

#endif
