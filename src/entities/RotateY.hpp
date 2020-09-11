#ifndef ROTATE_Y_H
#define ROTATE_Y_H

#include <cmath>
#include <memory>

#include "../Vector3.hpp"
#include "../Ray.hpp"
#include "../Entity.hpp"
#include "../AABB.hpp"

class RotateY : public Entity
{
public:
    RotateY(std::shared_ptr<Entity> p, float angle);

    virtual bool hit(
        const Ray &r, float t_min, float t_max, HitRecord &rec) const override;

    virtual bool bounding_box(float t0, float t1, AABB &output_box) const override;

public:
    std::shared_ptr<Entity> _ptr;
    float _sin_theta;
    float _cos_theta;
    bool _hasbox;
    AABB _bbox;
};

#endif