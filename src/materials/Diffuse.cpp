#include "Diffuse.hpp"

Diffuse::Diffuse(const Color3 &a) : _albedo(a) {}

bool Diffuse::scatter(const Ray &r_in, const HitRecord &rec, Color3 &attenuation, Ray &scattered) const
{
    Vector3 scatter_dir = rec.normal + Vector3::random_unit_vector();
    scattered = Ray(rec.p, scatter_dir);
    attenuation = _albedo;
    return true;
}