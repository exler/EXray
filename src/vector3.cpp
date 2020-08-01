#include "vector3.hpp"

Vector3::Vector3() : x(0), y(0), z(0) {}
Vector3::Vector3(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}

inline Vector3 Vector3::operator-() const
{
    return Vector3(-x, -y, -z);
}

Vector3 &Vector3::operator+=(const Vector3 &v)
{
    x += v.x;
    y += v.y;
    z += v.z;
    return *this;
}
Vector3 &Vector3::operator*=(const double t)
{
    x *= t;
    y *= t;
    z *= t;
    return *this;
}
Vector3 &Vector3::operator/=(const double t)
{
    return *this *= 1 / t;
}

inline double Vector3::length() const
{
    return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
}
inline double dot(const Vector3 &u, const Vector3 &v)
{
    return (u.x * v.x) + (u.y * v.y) + (u.z * v.z);
}
inline Vector3 cross(const Vector3 &u, const Vector3 &v)
{
    return Vector3(u.y * v.z - u.z * v.y,
                   u.z * v.x - u.x * v.z,
                   u.x * v.y - u.y * v.x);
}
inline Vector3 unit(const Vector3 &v)
{
    return v / v.length();
}

float Vector3::r()
{
    // Translate X from [0..1] to [0..255] for RGB
    return static_cast<int>(round(255 * x));
}
float Vector3::g()
{
    // Translate Y from [0..1] to [0..255] for RGB
    return static_cast<int>(round(255 * y));
}
float Vector3::b()
{
    // Translate Z from [0..1] to [0..255] for RGB
    return static_cast<int>(round(255 * z));
}