#include "Light.hpp"

Light::Light(std::shared_ptr<Texture> a) : _emit(a) {}
Light::Light(Color3 c) : _emit(std::make_shared<SolidColor>(c)) {}

bool Light::scatter(const Ray &r_in, const HitRecord &rec, Color3 &attenuation, Ray &scattered) const
{
    return false;
}

Color3 Light::emitted(float u, float v, const Vector3 &p) const
{
    return _emit->value(u, v, p);
}