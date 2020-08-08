#ifndef IMAGE_H
#define IMAGE_H

#include "vector3.hpp"

class Image
{
public:
    Image(const int image_width);
    Image(const int image_width, const int image_height);

    int get_image_width() const;
    int get_image_height() const;
    Vector3 get_origin() const;
    Vector3 get_horizontal() const;
    Vector3 get_vertical() const;

    Vector3 lower_left_corner() const;

private:
    const float _aspect_ratio = 16.0 / 9.0;
    int _image_width;
    int _image_height;

    const float _viewport_height = 2.0;
    const float _viewport_width = _aspect_ratio * _viewport_height;
    const float _focal_length = 1.0;

    Vector3 _origin = Vector3(0, 0, 0);
    Vector3 _horizontal = Vector3(_viewport_width, 0, 0);
    Vector3 _vertical = Vector3(0, _viewport_height, 0);
};

#endif