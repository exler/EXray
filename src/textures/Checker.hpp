#ifndef CHECKER_H
#define CHECKER_H

#include <memory>
#include <cmath>

#include "../Vector3.hpp"
#include "../Texture.hpp"

class Checker : public Texture
{
public:
    Checker();
    Checker(std::shared_ptr<Texture> t0, std::shared_ptr<Texture> t1);
    Checker(Color3 c1, Color3 c2);

    virtual Color3 value(float u, float v, const Vector3 &p) const override;

private:
    std::shared_ptr<Texture> even;
    std::shared_ptr<Texture> odd;
};

#endif