#include "Metal.hpp"

Metal::Metal(const Color3 &a) : _albedo(a) {}

bool Metal::scatter(const Ray &r_in, const HitRecord &rec, Color3 &attenuation, Ray &scattered) const
{
    Vector3 reflected = Vector3::reflect(unit_vector(r_in.direction()), rec.normal);
    scattered = Ray(rec.p, reflected);
    attenuation = _albedo;
    return dot(scattered.direction(), rec.normal) > 0;
}