#include "ray.hpp"

Ray::Ray() {}
Ray::Ray(const Vector3 &origin, const Vector3 &direction)
    : _orig(origin), _dir(direction) {}

Vector3 Ray::origin() const
{
    return _orig;
}
Vector3 Ray::direction() const
{
    return _dir;
}

Vector3 Ray::at(double t) const
{
    return _orig + t * _dir;
}

Vector3 Ray::lerp(const Vector3 &start_color, const Vector3 &end_color) const
{
    Vector3 unit_direction = unit_vector(_dir);
    auto t = 0.5 * (unit_direction.y + 1.0);

    // Linear blend (lerp)
    // blendedValue = (1 - t) * startValue + t * endValue
    return (1.0 - t) * start_color + t * end_color;
}