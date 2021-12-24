#include "Utility.hpp"
#include "Camera.hpp"
#include "Scene.hpp"

#include "EntityList.hpp"
#include "entities/Sphere.hpp"
#include "entities/Box.hpp"
#include "entities/Translate.hpp"
#include "materials/Dielectric.hpp"
#include "materials/Diffuse.hpp"
#include "materials/Metal.hpp"
#include "materials/Light.hpp"
#include "textures/Image.hpp"

EntityList cornell_box()
{
    EntityList objects;

    auto red = std::make_shared<Diffuse>(Color3(.65, .05, .05));
    auto white = std::make_shared<Diffuse>(Color3(.73, .73, .73));
    auto green = std::make_shared<Diffuse>(Color3(.12, .45, .15));
    auto light = std::make_shared<Light>(Color3(15, 15, 15));
    auto image = std::make_shared<Diffuse>(std::make_shared<Image>("texture.jpg"));

    objects.add(std::make_shared<YZRect>(0, 555, 0, 555, 555, green));
    objects.add(std::make_shared<YZRect>(0, 555, 0, 555, 0, red));
    objects.add(std::make_shared<XZRect>(213, 343, 227, 332, 554, light));
    objects.add(std::make_shared<XZRect>(0, 555, 0, 555, 0, white));
    objects.add(std::make_shared<XZRect>(0, 555, 0, 555, 555, white));
    objects.add(std::make_shared<XZRect>(0, 555, 0, 555, 555, white));

    Entity::ptr box1 = std::make_shared<Box>(Vector3(0, 0, 0), Vector3(165, 330, 165), image);
    box1 = std::make_shared<Translate>(box1, Vector3(265, 0, 295));
    objects.add(box1);

    Entity::ptr box2 = std::make_shared<Box>(Vector3(0, 0, 0), Vector3(165, 165, 165), white);
    box2 = std::make_shared<Translate>(box2, Vector3(130, 0, 65));
    objects.add(box2);

    return objects;
}

int main()
{
    // Details
    int image_width = 512;
    int image_height = 512;
    float aspect_ratio = image_width / image_height;
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
    Scene scene(image_width, image_height);
    scene.set_camera(&cam);
    scene.set_world(&world);
    scene.set_samples_per_pixel(200);
    scene.set_background(background);
    scene.set_thread_count(8);

    scene.render();
    scene.save();

    return 0;
}
