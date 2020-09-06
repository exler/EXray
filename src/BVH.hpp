#ifndef BVH_H
#define BVH_H

#include <memory>
#include <vector>

#include "Entity.hpp"
#include "EntityList.hpp"
#include "Ray.hpp"
#include "Vector3.hpp"
#include "Utility.hpp"

class BVHNode : public Entity
{
public:
    BVHNode();
    BVHNode(EntityList &list, float t0, float t1);

    BVHNode(
        std::vector<std::shared_ptr<Entity>> objects,
        size_t start, size_t end, float t0, float t1);

    virtual bool hit(
        const Ray &r, float tmin, float tmax, HitRecord &rec) const override;
    virtual bool bounding_box(
        float t0, float t1, AABB &output_box) const override;

private:
    std::shared_ptr<Entity> left;
    std::shared_ptr<Entity> right;
    AABB box;
};

inline bool box_compare(const std::shared_ptr<Entity> a, const std::shared_ptr<Entity> b, int axis)
{
    AABB box_a;
    AABB box_b;

    if (!a->bounding_box(0, 0, box_a) || !b->bounding_box(0, 0, box_b))
        std::cerr << "No bounding box in bBVHNode constructor.\n";

    return box_a.min()[axis] < box_b.min()[axis];
}

bool box_x_compare(const std::shared_ptr<Entity> a, const std::shared_ptr<Entity> b)
{
    return box_compare(a, b, 0);
}

bool box_y_compare(const std::shared_ptr<Entity> a, const std::shared_ptr<Entity> b)
{
    return box_compare(a, b, 1);
}

bool box_z_compare(const std::shared_ptr<Entity> a, const std::shared_ptr<Entity> b)
{
    return box_compare(a, b, 2);
}

#endif