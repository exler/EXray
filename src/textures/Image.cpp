#include "Image.hpp"

#define STB_IMAGE_IMPLEMENTATION
#include "../../lib/stb/stb_image.h"

Image::Image() : _data(nullptr),
                 _width(0),
                 _height(0),
                 _bytes_per_scanline(0) {}
Image::Image(const char *filename)
{
    auto components_per_pixel = bytes_per_pixel;

    _data = stbi_load(
        filename, &_width, &_height, &components_per_pixel, components_per_pixel);

    if (!_data)
    {
        std::cerr << "ERROR: Could not load texture image file '" << filename << "'." << std::endl;
        _width = _height = 0;
    }

    _bytes_per_scanline = bytes_per_pixel * _width;
}
Image::~Image()
{
    delete _data;
}

Color3 Image::value(float u, float v, const Vector3 &p) const
{
    // If we have no texture data, then return solid cyan as a debugging aid.
    if (_data == nullptr)
        return Color3(0, 1, 1);

    // Clamp input texture coordinates to [0, 1] x [1, 0]
    u = clamp(u, 0.0, 1.0);
    v = 1.0 - clamp(v, 0.0, 1.0); // Flip V to image coordinates

    auto i = static_cast<int>(u * _width);
    auto j = static_cast<int>(v * _height);

    // Clamp integer mapping, since actual coordinates should be less than 1.0
    if (i >= _width)
        i = _width - 1;
    if (j >= _height)
        j = _height - 1;

    const auto color_scale = 1.0 / 255.0;
    auto pixel = _data + j * _bytes_per_scanline + i * bytes_per_pixel;

    return Color3(color_scale * pixel[0], color_scale * pixel[1], color_scale * pixel[2]);
}