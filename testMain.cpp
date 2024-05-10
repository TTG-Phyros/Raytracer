/*
** EPITECH PROJECT, 2024
** BootStrap
** File description:
** testMain
*/

#include "src/Utils/Ray/Ray.hpp"
#include "src/Plugins/Primitives/Sphere/Sphere.hpp"
#include "src/Utils/Point/Point3D.hpp"
#include "src/Utils/Vector/Vector3D.hpp"
#include "src/Utils/Color/Color.hpp"

int main (void)
{
    RayTracer::Ray ray = RayTracer::Ray(Math::Point3D(0, 0, 0), Math::Point3D(1, 1, 1));
    Sphere sphere = Sphere(Math::Point3D(5, 5, 5), 2, Color(255, 0, 0, 100));

    if (sphere.hits(ray))
        std::cout << "hits" << std::endl;
        // std::cout << ray << "\nhits\n" << sphere << std::endl;
    else
        std::cout << "does not hits" << std::endl;
        // std::cout << ray << " does not hit " << sphere << std::endl;
    return 84;
}

