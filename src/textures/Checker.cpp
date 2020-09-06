#include "Checker.hpp"

Checker::Checker() {}
Checker::Checker(std::shared_ptr<Texture> t0, std::shared_ptr<Texture> t1) : even(t0),
                                                                             odd(t1) {}
Checker::Checker(Color3 c1, Color3 c2) : even(std::make_shared<SolidColor>(c1)),
                                         odd(std::make_shared<SolidColor>(c1)) {}

Color3 Checker::value(float u, float v, const Vector3 &p) const
{
    auto sines = sin(10 * p.x()) * sin(10 * p.y()) * sin(10 * p.z());
    if (sines < 0)
        return odd->value(u, v, p);
    else
        return even->value(u, v, p);
}