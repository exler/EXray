#ifndef SCENE_H
#define SCENE_H

#include <vector>
#include <algorithm>
#include <iostream>

#include "Utility.hpp"
#include "Camera.hpp"
#include "Ray.hpp"
#include "Vector3.hpp"
#include "Entity.hpp"
#include "ImageWriter.hpp"
#include "entities/Sphere.hpp"

class Scene
{
public:
    Scene(float aspect_ratio, int image_width);
    Scene(int image_width, int image_height);

    void set_camera(Camera *camera);
    void set_world(EntityList *world);
    void set_samples_per_pixel(const int samples_per_pixel);

    void render();

    void save(const std::string filename = "image.ppm");

private:
    Vector3 lerp(const Ray &ray, const Vector3 &start_color, const Vector3 &end_color) const;
    Color3 transform_color(Vector3 &color) const;

    int _image_width;
    int _image_height;

    int _samples_per_pixel = 100;

    Camera *_camera;
    EntityList *_world;

    std::vector<Color3> _image;
};

#endif