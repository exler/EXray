#ifndef IMAGE_H
#define IMAGE_H

#include <iostream>

#include "../Texture.hpp"
#include "../Utility.hpp"

class Image : public Texture
{
public:
    Image();
    Image(const char *filename);
    ~Image();

    virtual Color3 value(float u, float v, const Vector3 &p) const override;

private:
    unsigned char *_data;
    int _width, _height;
};

#endif