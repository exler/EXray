#include "Camera.hpp"

Camera::Camera(float aspect_ratio,
               float vertical_fov,
               Vector3 lookfrom,
               Vector3 lookat,
               Vector3 vup,
               float aperture,
               float focus_dist,
               float t0,
               float t1)
{
    auto theta = degrees_to_radians(vertical_fov);
    auto h = tan(theta / 2);

    auto viewport_height = 2.0 * h;
    auto viewport_width = aspect_ratio * viewport_height;

    auto w = unit_vector(lookfrom - lookat);
    _u = unit_vector(cross(vup, w));
    _v = cross(w, _u);

    _origin = lookfrom;
    _horizontal = focus_dist * viewport_width * _u;
    _vertical = focus_dist * viewport_height * _v;
    _lower_left_corner = _origin - _horizontal / 2 - _vertical / 2 - focus_dist * w;
    _lens_radius = aperture / 2;

    _time0 = t0;
    _time1 = t1;
}

Ray Camera::get_ray(float s, float t) const
{
    Vector3 rd = _lens_radius * Vector3::random_in_unit_disk();
    Vector3 offset = _u * rd.x() + _v * rd.y();

    return Ray(
        _origin + offset,
        _lower_left_corner + s * _horizontal + t * _vertical - _origin - offset,
        random_float(_time0, _time1));
}