#ifndef TEXTURE_H
#define TEXTURE_H

#include "Vector3.hpp"

class Texture
{
public:
    virtual Color3 value(float u, float v) const = 0;
};

#endif
