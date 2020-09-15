#include "BVH.hpp"

inline bool box_compare(const Entity::ptr a, const Entity::ptr b, int axis)
{
    AABB box_a, box_b;

    if (!a->bounding_box(0, 0, box_a) || !b->bounding_box(0, 0, box_b))
        std::cerr << "No bounding box in bBVHNode constructor.\n";

    return box_a.min()[axis] < box_b.min()[axis];
}

bool box_x_compare(const Entity::ptr a, const Entity::ptr b)
{
    return box_compare(a, b, 0);
}

bool box_y_compare(const Entity::ptr a, const Entity::ptr b)
{
    return box_compare(a, b, 1);
}

bool box_z_compare(const Entity::ptr a, const Entity::ptr b)
{
    return box_compare(a, b, 2);
}

BVHNode::BVHNode() {}
BVHNode::BVHNode(EntityList &list, float t0, float t1) : BVHNode(
                                                             list.obj(), 0, list.obj().size(), t0, t1) {}
BVHNode::BVHNode(
    std::vector<Entity::ptr> objects,
    size_t start, size_t end, float t0, float t1)
{
    int axis = random_int(0, 2);
    auto comparator = (axis == 0) ? box_x_compare
                                  : (axis == 1) ? box_y_compare
                                                : box_z_compare;

    size_t object_span = end - start;

    if (object_span == 1)
    {
        left = right = objects[start];
    }
    else if (object_span == 2)
    {
        if (comparator(objects[start], objects[start + 1]))
        {
            left = objects[start];
            right = objects[start + 1];
        }
        else
        {
            left = objects[start + 1];
            right = objects[start];
        }
    }
    else
    {
        std::sort(objects.begin() + start, objects.begin() + end, comparator);

        auto mid = start + object_span / 2;
        left = std::make_shared<BVHNode>(objects, start, mid, t0, t1);
        right = std::make_shared<BVHNode>(objects, mid, end, t0, t1);
    }

    AABB box_left, box_right;

    if (!left->bounding_box(t0, t1, box_left) || !right->bounding_box(t0, t1, box_right))
        std::cerr << "No bounding box in BVHNode constructor.\n";

    box = AABB::surrounding_box(box_left, box_right);
}

bool BVHNode::hit(const Ray &r, float tmin, float tmax, HitRecord &rec) const
{
    if (!box.hit(r, tmin, tmax))
        return false;

    bool hit_left = left->hit(r, tmin, tmax, rec);
    bool hit_right = right->hit(r, tmin, hit_left ? rec.t : tmax, rec);

    return hit_left || hit_right;
}

bool BVHNode::bounding_box(float t0, float t1, AABB &output_box) const
{
    output_box = box;
    return true;
}