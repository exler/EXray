#include "Ray.hpp"

Ray::Ray() {}
Ray::Ray(const Vector3 &origin, const Vector3 &direction, float time)
    : _orig(origin), _dir(direction), _time(time) {}

Vector3 Ray::origin() const
{
    return _orig;
}
Vector3 Ray::direction() const
{
    return _dir;
}
float Ray::time() const
{
    return _time;
}

Vector3 Ray::at(float t) const
{
    return _orig + t * _dir;
}