/*
** EPITECH PROJECT, 2024
** BootStrap
** File description:
** Sphere
*/

#include "Sphere.hpp"
#include "math.h"

RayTracer::Sphere::Sphere(Math::Point3D origin, double radius)
{
    _origin = origin;
    _radius = radius;
}

bool RayTracer::Sphere::hits(RayTracer::Ray &ray)
{
    double offsetX = _origin._x;
    double offsetY = _origin._y;
    double offsetZ = _origin._z;

    Math::Point3D point = Math::Point3D(
        ray._origin._x - _origin._x,
        ray._origin._y - _origin._y,
        ray._origin._z - _origin._z
    );
    Math::Vector3D vector = Math::Vector3D(
        ray._direction._x - ray._origin._x,
        ray._direction._y - ray._origin._y,
        ray._direction._z - ray._origin._z
    );

    double a = ((vector._x * vector._x) + (vector._y * vector._y) + (vector._z * vector._z));
    double b = (2 * ((point._x * vector._x) + (point._y * vector._y) + (point._z * vector._z)));
    double c = ((point._x * point._x) + (point._y * point._y) + (point._z * point._z) - (_radius * _radius));

    double delta = (b * b) - (4 * a * c);

    if (delta < 0)
        return false;
    else {
        double t1 = (-b + sqrt(delta)) / (2 * a);
        double t2 = (-b - sqrt(delta)) / (2 * a);
    }

    return true;
}

std::ostream &operator<<(std::ostream &cout, RayTracer::Sphere &sphere)
{
    return cout << "Sphere [\n\tOrigin : " << sphere._origin << ",\n\tRadius : " << sphere._radius << "\n]";
}

RayTracer::Sphere::~Sphere()
{
}
