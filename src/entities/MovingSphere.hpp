#ifndef MOVING_SPHERE_H
#define MOVING_SPHERE_H

#include <memory>

#include "../Entity.hpp"
#include "../Utility.hpp"
#include "../Material.hpp"
#include "../AABB.hpp"

class MovingSphere : public Entity
{
public:
    MovingSphere();
    MovingSphere(Vector3 cen0,
                 Vector3 cen1,
                 float t0,
                 float t1,
                 float r,
                 std::shared_ptr<Material> m);

    virtual bool hit(const Ray &r, float t_min, float t_max, HitRecord &rec) const override;
    virtual bool bounding_box(float t0, float t1, AABB &output_box) const override;

    Vector3 center(float time) const;

private:
    Vector3 _center0, _center1;
    float _time0, _time1;
    float _radius;
    std::shared_ptr<Material> _mat;
};

#endif