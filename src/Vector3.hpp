#ifndef VECTOR3_H
#define VECTOR3_H

#include <cmath>
#include <iostream>

#include "Utility.hpp"

class Vector3
{
public:
    float x() const { return e[0]; }
    float y() const { return e[1]; }
    float z() const { return e[2]; }

    float r() const { return e[0]; }
    float g() const { return e[1]; }
    float b() const { return e[2]; }

    Vector3();
    Vector3(float e0, float e1, float e2);

    Vector3 operator-() const;
    Vector3 &operator+=(const Vector3 &v);
    Vector3 &operator*=(const float t);
    Vector3 &operator/=(const float t);
    float operator[](int i) const;
    float &operator[](int i);

    float length() const;
    float length_squared() const;

    static Vector3 random();
    static Vector3 random(float min, float max);
    static Vector3 random_unit_vector();
    static Vector3 random_in_unit_disk();

    static Vector3 reflect(const Vector3 &v, const Vector3 &n);
    static Vector3 refract(const Vector3 &uv, const Vector3 &n, float refractive_div);

private:
    float e[3];
};

using Color3 = Vector3;

inline std::ostream &operator<<(std::ostream &out, const Vector3 &v)
{
    return out << '(' << v.x() << ", " << v.y() << ", " << v.z() << ')';
}
inline Vector3 operator+(const Vector3 &u, const Vector3 &v)
{
    return Vector3(u.x() + v.x(), u.y() + v.y(), u.z() + v.z());
}
inline Vector3 operator-(const Vector3 &u, const Vector3 &v)
{
    return Vector3(u.x() - v.x(), u.y() - v.y(), u.z() - v.z());
}
inline Vector3 operator*(const Vector3 &u, const Vector3 &v)
{
    return Vector3(u.x() * v.x(), u.y() * v.y(), u.z() * v.z());
}
inline Vector3 operator*(float t, const Vector3 &v)
{
    return Vector3(t * v.x(), t * v.y(), t * v.z());
}
inline Vector3 operator*(const Vector3 &v, float t)
{
    return t * v;
}
inline Vector3 operator/(const Vector3 &v, float t)
{
    return (1 / t) * v;
}

inline float dot(const Vector3 &u, const Vector3 &v)
{
    return (u.x() * v.x()) + (u.y() * v.y()) + (u.z() * v.z());
}
inline Vector3 cross(const Vector3 &u, const Vector3 &v)
{
    return Vector3(u.y() * v.z() - u.z() * v.y(),
                   u.z() * v.x() - u.x() * v.z(),
                   u.x() * v.y() - u.y() * v.x());
}
inline Vector3 normalize(const Vector3 &v)
{
    return v / v.length();
}

#endif