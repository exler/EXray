#include "Translate.hpp"

Translate::Translate(std::shared_ptr<Entity> p, const Vector3 &offset) : _ptr(p),
                                                                         _offset(offset) {}

bool Translate::hit(const Ray &r, float t_min, float t_max, HitRecord &rec) const
{
    Ray moved_r(r.origin() - _offset, r.direction(), r.time());
    if (!_ptr->hit(moved_r, t_min, t_max, rec))
        return false;

    rec.p += _offset;
    rec.set_face_normal(moved_r, rec.normal);

    return true;
}
bool Translate::bounding_box(float t0, float t1, AABB &output_box) const
{
    if (_ptr->bounding_box(t0, t1, output_box))
        return false;

    output_box = AABB(
        output_box.min() + _offset,
        output_box.max() + _offset);

    return true;
}