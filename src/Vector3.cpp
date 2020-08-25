#include "Vector3.hpp"

Vector3::Vector3() : x(0), y(0), z(0) {}
Vector3::Vector3(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}

float Vector3::r()
{
    return x;
}
float Vector3::g()
{
    return y;
}
float Vector3::b()
{
    return z;
}

Vector3 Vector3::operator-() const
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
Vector3 &Vector3::operator*=(const float t)
{
    x *= t;
    y *= t;
    z *= t;
    return *this;
}
Vector3 &Vector3::operator/=(const float t)
{
    return *this *= 1 / t;
}

float Vector3::length() const
{
    return sqrt(length_squared());
}
float Vector3::length_squared() const
{
    return x * x + y * y + z * z;
}

Vector3 Vector3::random_unit_vector()
{
    // Returns a random unit vector using Lambertian reflectance
    float a = random_float(0, 2 * pi);
    float z = random_float(-1, 1);
    float r = sqrt(1 - z * z);
    return Vector3(r * cos(a), r * sin(a), z);
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