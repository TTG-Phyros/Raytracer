/*
** EPITECH PROJECT, 2024
** BootStrap
** File description:
** testMain
*/

#include "Ray.hpp"
#include "Sphere.hpp"
#include "Point3D.hpp"
#include "Vector3D.hpp"

int main (void)
{
    RayTracer::Ray ray = RayTracer::Ray(Math::Point3D(), Math::Vector3D(-2, -2, -2));
    RayTracer::Sphere sphere = RayTracer::Sphere(Math::Point3D(5, 5, 5), 2);

    if (sphere.hits(ray))
        std::cout << ray << "\nhits\n" << sphere << std::endl;
    else
        std::cout << ray << " does not hit " << sphere << std::endl;
    return 84;
}
