#include "MovingSphere.hpp"

MovingSphere::MovingSphere() {}
MovingSphere::MovingSphere(Vector3 cen0,
                           Vector3 cen1,
                           float t0,
                           float t1,
                           float r,
                           std::shared_ptr<Material> m) : _center0(cen0),
                                                          _center1(cen1),
                                                          _time0(t0),
                                                          _time1(t1),
                                                          _radius(r),
                                                          _mat(m) {}

bool MovingSphere::hit(const Ray &r, float t_min, float t_max, HitRecord &rec) const
{
    Vector3 oc = r.origin() - center(r.time());
    auto a = r.direction().length_squared();
    auto half_b = dot(oc, r.direction());
    auto c = oc.length_squared() - _radius * _radius;
    auto delta = half_b * half_b - a * c;

    if (delta > 0)
    {
        auto root = sqrt(delta);

        auto tmp = (-half_b - root) / a;
        if (tmp < t_max && tmp > t_min)
        {
            rec.t = tmp;
            rec.p = r.at(rec.t);
            Vector3 outward_normal = (rec.p - center(r.time())) / _radius;
            rec.set_face_normal(r, outward_normal);
            rec.mat = _mat;
            return true;
        }

        tmp = (-half_b + root) / a;
        if (tmp < t_max && tmp > t_min)
        {
            rec.t = tmp;
            rec.p = r.at(rec.t);
            Vector3 outward_normal = (rec.p - center(r.time())) / _radius;
            rec.set_face_normal(r, outward_normal);
            rec.mat = _mat;
            return true;
        }
    }

    return false;
}

bool MovingSphere::bounding_box(float t0, float t1, AABB &output_box) const
{
    AABB box0(
        center(t0) - Vector3(_radius, _radius, _radius),
        center(t0) + Vector3(_radius, _radius, _radius));
    AABB box1(
        center(t1) - Vector3(_radius, _radius, _radius),
        center(t1) + Vector3(_radius, _radius, _radius));
    output_box = AABB::surrounding_box(box0, box1);
    return true;
}

Vector3 MovingSphere::center(float time) const
{
    return _center0 + ((time - _time0) / (_time1 - _time0)) * (_center1 - _center0);
}