#include "Diffuse.hpp"

Diffuse::Diffuse(const Color3 &a) : _albedo(std::make_shared<SolidColor>(a)) {}
Diffuse::Diffuse(std::shared_ptr<Texture> a) : _albedo(a) {}

bool Diffuse::scatter(const Ray &r_in, const HitRecord &rec, Color3 &attenuation, Ray &scattered) const
{
    Vector3 scatter_dir = rec.normal + Vector3::random_unit_vector();
    scattered = Ray(rec.p, scatter_dir, r_in.time());
    attenuation = _albedo->value(rec.u, rec.v);
    return true;
}
