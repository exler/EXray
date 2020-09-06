#include "Vector3.hpp"

Vector3::Vector3() : e{0, 0, 0} {}
Vector3::Vector3(float _x, float _y, float _z) : e{_x, _y, _z} {}

Vector3 Vector3::operator-() const
{
    return Vector3(-e[0], -e[1], -e[2]);
}

Vector3 &Vector3::operator+=(const Vector3 &v)
{
    e[0] += v.e[0];
    e[1] += v.e[1];
    e[2] += v.e[2];
    return *this;
}
Vector3 &Vector3::operator*=(const float t)
{
    e[0] *= t;
    e[1] *= t;
    e[2] *= t;
    return *this;
}
Vector3 &Vector3::operator/=(const float t)
{
    return *this *= 1 / t;
}
float Vector3::operator[](int i) const
{
    return e[i];
}
float &Vector3::operator[](int i)
{
    return e[i];
}

float Vector3::length() const
{
    return sqrt(length_squared());
}
float Vector3::length_squared() const
{
    return e[0] * e[0] + e[1] * e[1] + e[2] * e[2];
}

Vector3 Vector3::random()
{
    return Vector3(random_float(), random_float(), random_float());
}
Vector3 Vector3::random(float min, float max)
{
    return Vector3(random_float(min, max), random_float(min, max), random_float(min, max));
}
Vector3 Vector3::random_unit_vector()
{
    // Returns a random unit vector using Lambertian reflectance
    float a = random_float(0, 2 * pi);
    float z = random_float(-1, 1);
    float r = sqrt(1 - z * z);
    return Vector3(r * cos(a), r * sin(a), z);
}
Vector3 Vector3::random_in_unit_disk()
{
    // Returns a random point inside unit disk
    while (true)
    {
        auto p = Vector3(random_float(-1, 1), random_float(-1, 1), 0);
        if (p.length_squared() >= 1)
            continue;
        return p;
    }
}

Vector3 Vector3::reflect(const Vector3 &v, const Vector3 &n)
{
    // Returns reflected ray direction v + 2b,
    // n is a unit vector, length of b is v dot n
    return v - 2 * dot(v, n) * n;
}
Vector3 Vector3::refract(const Vector3 &uv, const Vector3 &n, float refractive_div)
{
    // Returns refracted ray direction using Snell's law
    auto cos_theta = dot(-uv, n);
    Vector3 r_out_perp = refractive_div * (uv + cos_theta * n);
    Vector3 r_out_parallel = -sqrt(fabs(1.0 - r_out_perp.length_squared())) * n;
    return r_out_perp + r_out_parallel;
}