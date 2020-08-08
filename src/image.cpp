#include "image.hpp"

Image::Image(const int image_width) : _image_width(image_width)
{
    _image_height = static_cast<int>(_image_width / _aspect_ratio);
}
Image::Image(const int image_width, const int image_height) : _image_width(image_width), _image_height(image_height) {}

int Image::get_image_width() const
{
    return _image_width;
}
int Image::get_image_height() const
{
    return _image_height;
}
Vector3 Image::get_origin() const
{
    return Vector3(0, 0, 0);
}
Vector3 Image::get_horizontal() const
{
    return Vector3(_viewport_width, 0, 0);
}
Vector3 Image::get_vertical() const
{
    return Vector3(0, _viewport_height, 0);
}

Vector3 Image::lower_left_corner() const
{
    return _origin - _horizontal / 2 - _vertical / 2 - Vector3(0, 0, _focal_length);
}