#ifndef VECTOR3_H
#define VECTOR3_H

#include <cmath>
#include <iostream>

class Vector3
{
public:
    float x;
    float y;
    float z;

    float r();
    float g();
    float b();

    Vector3();
    Vector3(float e0, float e1, float e2);

    Vector3 operator-() const;
    Vector3 &operator+=(const Vector3 &v);
    Vector3 &operator*=(const double t);
    Vector3 &operator/=(const double t);

    double length() const;
    double length_squared() const;
};

using Color3 = Vector3;

inline std::ostream &operator<<(std::ostream &out, const Vector3 &v)
{
    return out << '(' << v.x << ", " << v.y << ", " << v.z << ')';
}
inline Vector3 operator+(const Vector3 &u, const Vector3 &v)
{
    return Vector3(u.x + v.x, u.y + v.y, u.z + v.z);
}
inline Vector3 operator-(const Vector3 &u, const Vector3 &v)
{
    return Vector3(u.x - v.x, u.y - v.y, u.z - v.z);
}
inline Vector3 operator*(const Vector3 &u, const Vector3 &v)
{
    return Vector3(u.x * v.x, u.y * v.y, u.z * v.z);
}
inline Vector3 operator*(double t, const Vector3 &v)
{
    return Vector3(t * v.x, t * v.y, t * v.z);
}
inline Vector3 operator*(const Vector3 &v, double t)
{
    return t * v;
}
inline Vector3 operator/(const Vector3 &v, double t)
{
    return (1 / t) * v;
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
inline Vector3 unit_vector(const Vector3 &v)
{
    return v / v.length();
}

#endif