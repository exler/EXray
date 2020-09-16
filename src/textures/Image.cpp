#include "Image.hpp"

#define STB_IMAGE_IMPLEMENTATION
#include "../../lib/stb/stb_image.h"

Image::Image() : _data(nullptr),
                 _width(0),
                 _height(0) {}
Image::Image(const char *filename)
{
    int comp;
    _data = stbi_load(
        filename, &_width, &_height, &comp, 0);

    if (!_data)
    {
        std::cerr << "ERROR: Could not load texture image file '" << filename << "'." << std::endl;
        _width = _height = 0;
    }
}
Image::~Image()
{
    delete _data;
}

Color3 Image::value(float u, float v, const Vector3 &p) const
{
    // If we have no texture data, return solid cyan
    if (_data == nullptr)
        return Color3(0, 1, 1);

    int i = u * _width;
    int j = (1 - v) * _height - 0.001;

    i = clamp(i, 0, _width - 1);
    j = clamp(j, 0, _height - 1);

    return Vector3(static_cast<int>(_data[3 * i + 3 * _width * j + 0]) / 255.0f,
                   static_cast<int>(_data[3 * i + 3 * _width * j + 1]) / 255.0f,
                   static_cast<int>(_data[3 * i + 3 * _width * j + 2]) / 255.0f);
}