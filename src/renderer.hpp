#ifndef RENDERER_H
#define RENDERER_H

#include "vector3.hpp"
#include "ray.hpp"
#include "entity.hpp"

class Renderer
{
public:
    static Vector3 lerp(const Ray &ray, const Entity &world, const Vector3 &start_color, const Vector3 &end_color);
};

#endif