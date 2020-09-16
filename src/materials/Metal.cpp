#include "Metal.hpp"

Metal::Metal(const Color3 &a, float f) : _albedo(a), _fuzz(f) {}

bool Metal::scatter(const Ray &r_in, const HitRecord &rec, Color3 &attenuation, Ray &scattered) const
{
    Vector3 reflected = Vector3::reflect(normalize(r_in.direction()), rec.normal);
    scattered = Ray(rec.p, reflected + _fuzz * Vector3::random_unit_vector(), r_in.time());
    attenuation = _albedo;
    return dot(scattered.direction(), rec.normal) > 0;
}