#include "Translate.hpp"

Translate::Translate(Entity::ptr p, const Vector3 &offset) : _ptr(p),
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
