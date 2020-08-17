#include "Sphere.hpp"

Sphere::Sphere() {}
Sphere::Sphere(Vector3 c, float r) : _center(c), _radius(r) {}

bool Sphere::hit(const Ray &r, double t_min, double t_max, HitRecord &rec) const
{
    Vector3 oc = r.origin() - _center;
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
            Vector3 outward_normal = (rec.p - _center) / _radius;
            rec.set_face_normal(r, outward_normal);
            return true;
        }

        tmp = (-half_b + root) / a;
        if (tmp < t_max && tmp > t_min)
        {
            rec.t = tmp;
            rec.p = r.at(rec.t);
            Vector3 outward_normal = (rec.p - _center) / _radius;
            rec.set_face_normal(r, outward_normal);
            return true;
        }
    }

    return false;
}