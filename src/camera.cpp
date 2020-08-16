#include "camera.hpp"

Camera::Camera(float aspect_ratio)
{
    auto _viewport_height = 2.0;
    auto _viewport_width = aspect_ratio * _viewport_height;
    auto _focal_length = 1.0;

    _origin = Vector3(0, 0, 0);
    _horizontal = Vector3(_viewport_width, 0, 0);
    _vertical = Vector3(0, _viewport_height, 0);
    _lower_left_corner = _origin - _horizontal / 2 - _vertical / 2 - Vector3(0, 0, _focal_length);
}

Ray Camera::get_ray(double u, double v) const
{
    return Ray(
        _origin,
        _lower_left_corner + u * _horizontal + v * _vertical - _origin);
}