#include "maths.h"
#include "camera.h"
#include "hittable.h"
#include "hittable_list.h"
#include "sphere.h"
#include "material.h"

int main() {

    // World

    hittable_list world;

    auto ground_material = make_shared<lambertian>(color(0.5, 1.0, 0.5));
    world.add(make_shared<sphere>(point3(0,-100.5,0), 100, ground_material));

    // for (int a = -11; a < 11; a++) {
    //     for (int b = -11; b < 11; b++) {
    //         auto choose_mat = random_double();
    //         point3 center(a + 0.9*random_double(), 0.2, b + 0.9*random_double());

    //         if ((center - point3(4, 0.2, 0)).length() > 0.9) {
    //             shared_ptr<material> sphere_material;

    //             if (choose_mat < 0.8) {
    //                 // diffuse
    //                 auto albedo = color::random() * color::random();
    //                 sphere_material = make_shared<lambertian>(albedo);
    //                 world.add(make_shared<sphere>(center, 0.2, sphere_material));
    //             } else if (choose_mat < 0.95) {
    //                 // metal
    //                 auto albedo = color::random(0.5, 1);
    //                 auto fuzz = random_double(0, 0.5);
    //                 sphere_material = make_shared<metal>(albedo, fuzz);
    //                 world.add(make_shared<sphere>(center, 0.2, sphere_material));
    //             } else {
    //                 // glass
    //                 sphere_material = make_shared<dielectric>(1.5);
    //                 world.add(make_shared<sphere>(center, 0.2, sphere_material));
    //             }
    //         }
    //     }
    // }

    // auto material_ground = make_shared<lambertian>(color(0.8, 0.8, 0.0));
    auto material_center = make_shared<lambertian>(color(0.8, 0.8, 0.9));
    auto material_left   = make_shared<dielectric>(2.20);
    auto material_bubble = make_shared<dielectric>(1.00 / 2.20);
    auto material_right  = make_shared<metal>(color(0.8, 0.6, 0.2), 1);

    // world.add(make_shared<sphere>(point3( 0.0, -20.5, -1.0), 20.0, material_ground));
    world.add(make_shared<sphere>(point3( 0.0,    0.0, -1.2),   0.5, material_center));
    world.add(make_shared<sphere>(point3(-1.0,    0.0, -0.5),   0.5, material_left));
    world.add(make_shared<sphere>(point3(-1.0,    0.0, -0.5),   0.45, material_bubble));
    world.add(make_shared<sphere>(point3( 1.0,    0.0, -0.5),   0.5, material_right));

    camera cam;

    cam.aspect_ratio = 16.0 / 9.0;
    cam.image_width  = 400;
    cam.samples_per_pixel = 500;
    cam.max_depth         = 100;

    cam.vfov = 70;
    cam.lookfrom = point3(-0.75,0.25,-0.25);
    cam.lookat   = point3(0,0.25,-0.7);
    cam.vup      = vec3(0,1,0);

    cam.render(world);
}