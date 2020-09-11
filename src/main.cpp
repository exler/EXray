#include "Utility.hpp"
#include "Camera.hpp"
#include "Scene.hpp"

#include "EntityList.hpp"
#include "BVH.hpp"
#include "entities/MovingSphere.hpp"
#include "entities/Sphere.hpp"
#include "entities/Box.hpp"
#include "entities/Translate.hpp"
#include "entities/RotateY.hpp"
#include "materials/Dielectric.hpp"
#include "materials/Diffuse.hpp"
#include "materials/Metal.hpp"
#include "materials/Light.hpp"
#include "textures/Checker.hpp"
#include "textures/Image.hpp"
#include "textures/Noise.hpp"

EntityList cornell_box()
{
    EntityList objects;

    auto red = std::make_shared<Diffuse>(Color3(.65, .05, .05));
    auto white = std::make_shared<Diffuse>(Color3(.73, .73, .73));
    auto green = std::make_shared<Diffuse>(Color3(.12, .45, .15));
    auto light = std::make_shared<Light>(Color3(15, 15, 15));

    objects.add(std::make_shared<YZRect>(0, 555, 0, 555, 555, green));
    objects.add(std::make_shared<YZRect>(0, 555, 0, 555, 0, red));
    objects.add(std::make_shared<XZRect>(213, 343, 227, 332, 554, light));
    objects.add(std::make_shared<XZRect>(0, 555, 0, 555, 0, white));
    objects.add(std::make_shared<XZRect>(0, 555, 0, 555, 555, white));
    objects.add(std::make_shared<XZRect>(0, 555, 0, 555, 555, white));

    std::shared_ptr<Entity> box1 = std::make_shared<Box>(Vector3(0, 0, 0), Vector3(165, 330, 165), white);
    box1 = std::make_shared<RotateY>(box1, 15);
    box1 = std::make_shared<Translate>(box1, Vector3(265, 0, 295));
    objects.add(box1);

    std::shared_ptr<Entity> box2 = std::make_shared<Box>(Vector3(0, 0, 0), Vector3(165, 165, 165), white);
    box2 = std::make_shared<RotateY>(box2, -18);
    box2 = std::make_shared<Translate>(box2, Vector3(130, 0, 65));
    objects.add(box2);

    return objects;
}

int main()
{
    // Details
    float aspect_ratio = 1.0;
    int image_width = 600;
    Vector3 lookfrom(278, 278, -800);
    Vector3 lookat(278, 278, 0);
    Vector3 vup(0, 1, 0);
    Color3 background = Color3(0, 0, 0);
    auto dist_to_focus = 10;
    auto aperture = 0.1;
    auto vfov = 40.0;

    // Camera
    Camera cam(aspect_ratio, vfov, lookfrom, lookat, vup, aperture, dist_to_focus, 0.0, 1.0);

    // World
    EntityList world = cornell_box();

    // Scene (image)
    Scene scene(aspect_ratio, image_width);
    scene.set_camera(&cam);
    scene.set_world(&world);
    scene.set_samples_per_pixel(200);
    scene.set_background(background);

    scene.render();
    scene.save();

    return 0;
}