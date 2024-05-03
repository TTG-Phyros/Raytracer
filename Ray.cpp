/*
** EPITECH PROJECT, 2024
** BootStrap
** File description:
** Ray
*/

#include "Ray.hpp"

RayTracer::Ray::Ray(Math::Point3D origin, Math::Vector3D direction)
{
    _origin = origin;
    _direction = direction;
}

std::ostream &operator<<(std::ostream &cout, RayTracer::Ray &ray)
{
    return cout << "Ray [\n\tOrigin : " << ray._origin << ",\n\tDirection : " << ray._direction << "\n]";
}

RayTracer::Ray::~Ray()
{
}
