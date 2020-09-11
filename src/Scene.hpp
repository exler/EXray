#ifndef SCENE_H
#define SCENE_H

#include <vector>
#include <iostream>
#include <chrono>

#include "Utility.hpp"
#include "Camera.hpp"
#include "Ray.hpp"
#include "Vector3.hpp"
#include "ImageWriter.hpp"
#include "Material.hpp"
#include "EntityList.hpp"
#include "entities/Sphere.hpp"

class Scene
{
public:
    Scene(float aspect_ratio, int image_width);
    Scene(int image_width, int image_height);

    void set_camera(Camera *camera);
    void set_world(EntityList *world);
    void set_samples_per_pixel(const int samples_per_pixel);
    void set_max_depth(const int max_depth);
    void set_background(const Color3 &background);

    void render();

    void save(const std::string filename = "image.ppm");

private:
    Vector3 ray_color(const Ray &ray, int depth) const;
    Color3 transform_color(Vector3 &color) const;

    int _image_width;
    int _image_height;

    int _samples_per_pixel = 100;
    int _max_depth = 50;

    Camera *_camera;
    EntityList *_world;

    Color3 _background;

    std::vector<Color3> _image;
};

#endif