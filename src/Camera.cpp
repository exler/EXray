#include "Camera.hpp"

Camera::Camera(float aspect_ratio, float vertical_fov, Vector3 lookfrom, Vector3 lookat, Vector3 vup)
{
    auto theta = degrees_to_radians(vertical_fov);
    auto h = tan(theta / 2);

    auto viewport_height = 2.0 * h;
    auto viewport_width = aspect_ratio * viewport_height;

    auto w = unit_vector(lookfrom - lookat);
    auto u = unit_vector(cross(vup, w));
    auto v = cross(w, u);

    _origin = lookfrom;
    _horizontal = viewport_width * u;
    _vertical = viewport_height * v;
    _lower_left_corner = _origin - _horizontal / 2 - _vertical / 2 - w;
}

Ray Camera::get_ray(float u, float v) const
{
    return Ray(
        _origin,
        _lower_left_corner + u * _horizontal + v * _vertical - _origin);
}