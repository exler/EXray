#include "EntityList.hpp"

EntityList::EntityList() {}
EntityList::EntityList(std::shared_ptr<Entity> object)
{
    add(object);
}

void EntityList::clear()
{
    _objects.clear();
}
void EntityList::add(std::shared_ptr<Entity> object)
{
    _objects.push_back(object);
}

bool EntityList::hit(const Ray &r, float t_min, float t_max, HitRecord &rec) const
{
    HitRecord temp_rec;
    bool hit = false;
    auto closest = t_max;

    for (const auto &object : _objects)
    {
        if (object->hit(r, t_min, closest, temp_rec))
        {
            hit = true;
            closest = temp_rec.t;
            rec = temp_rec;
        }
    }

    return hit;
}

bool EntityList::bounding_box(float t0, float t1, AABB &output_box) const
{
    if (_objects.empty())
        return false;

    AABB temp_box;
    bool first_box = true;

    for (const auto &object : _objects)
    {
        if (!object->bounding_box(t0, t1, temp_box))
            return false;
        output_box = first_box ? temp_box : AABB::surrounding_box(output_box, temp_box);
        first_box = false;
    }

    return true;
}