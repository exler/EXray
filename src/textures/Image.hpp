#ifndef IMAGE_H
#define IMAGE_H

#include <iostream>

#include "../../lib/stb/stb_image.h"
#include "../Texture.hpp"
#include "../Utility.hpp"

class Image : public Texture
{
public:
    const static int bytes_per_pixel = 3;

    Image();
    Image(const char *filename);
    ~Image();

    virtual Color3 value(float u, float v, const Vector3 &p) const override;

private:
    unsigned char *_data;
    int _width, _height;
    int _bytes_per_scanline;
};

#endif