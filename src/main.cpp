#include "Utility.hpp"
#include "Camera.hpp"
#include "Scene.hpp"

#include "EntityList.hpp"
#include "entities/Sphere.hpp"
#include "materials/Diffuse.hpp"
#include "materials/Metal.hpp"

int main()
{
    // Details
    float aspect_ratio = 16.0 / 9.0;
    int image_width = 400;

    // Camera
    Camera cam(aspect_ratio);

    // World
    EntityList world;

    auto material_ground = std::make_shared<Diffuse>(Color3(0.8, 0.8, 0.0));
    auto material_center = std::make_shared<Diffuse>(Color3(0.7, 0.3, 0.3));
    auto material_left = std::make_shared<Metal>(Color3(0.8, 0.8, 0.8), 0.3);
    auto material_right = std::make_shared<Metal>(Color3(0.8, 0.6, 0.2), 1.0);

    world.add(std::make_shared<Sphere>(Vector3(0.0, -100.5, -1.0), 100.0, material_ground));
    world.add(std::make_shared<Sphere>(Vector3(0.0, 0.0, -1.0), 0.5, material_center));
    world.add(std::make_shared<Sphere>(Vector3(-1.0, 0.0, -1.0), 0.5, material_left));
    world.add(std::make_shared<Sphere>(Vector3(1.0, 0.0, -1.0), 0.5, material_right));

    // Scene (image)
    Scene scene(aspect_ratio, image_width);
    scene.set_camera(&cam);
    scene.set_world(&world);

    scene.render();
    scene.save();

    return 0;
}