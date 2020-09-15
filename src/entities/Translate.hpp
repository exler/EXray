#ifndef TRANSLATE_H
#define TRANSLATE_H

#include <memory>

#include "../Vector3.hpp"
#include "../Ray.hpp"
#include "../AABB.hpp"
#include "../Entity.hpp"

class Translate : public Entity
{
public:
    Translate(Entity::ptr p, const Vector3 &offset);

    virtual bool hit(const Ray &r, float t_min, float t_max, HitRecord &rec) const override;
    virtual bool bounding_box(float t0, float t1, AABB &output_box) const override;

private:
    Entity::ptr _ptr;
    Vector3 _offset;
};

#endif