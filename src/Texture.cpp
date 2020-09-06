#include "Texture.hpp"

SolidColor::SolidColor() {}
SolidColor::SolidColor(Color3 c) : color_value(c) {}

SolidColor::SolidColor(float r, float g, float b) : SolidColor(Color3(r, g, b)) {}

Color3 SolidColor::value(float u, float v, const Vector3 &p) const
{
    return color_value;
}