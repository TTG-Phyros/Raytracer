/**
 * @file Sphere.cpp
 * @author COUSTABEAU Maxime (maxime.coustabeau@epitech.eu)
 *         GIRARD Anthony (anthony1.girard@epitech.eu)
 *         MERY Baptiste (baptiste.mery@epitech.eu)
 *         AUDIBERT Nicolas (nicolas.audibert@epitech.eu)
 * @brief EPITECH PROJECT, 2024
 * @version 0.1
 * @date 2024-05-03
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "Sphere.hpp"

extern "C" IPrimitives *loadSphere()
{
    printf("[RayTracer::Sphere] Load Sphere\n");
    return new Sphere();
}

Sphere::Sphere()
{
    _form = "Sphere";
    _origin = Math::Point3D();
    _radius = 0.0;
    _color = Color();
}

Sphere::Sphere(Math::Point3D origin, double radius, Color color)
{
    _form = "Sphere";
    _origin = origin;
    _radius = radius;
    _color = color;
}

Sphere::~Sphere()
{
}

bool Sphere::hits(RayTracer::Ray &ray)
{
    double offsetX = _origin._x;
    double offsetY = _origin._y;
    double offsetZ = _origin._z;

    Math::Point3D point = Math::Point3D(
        ray._origin._x + offsetX,
        ray._origin._y + offsetY,
        ray._origin._z + offsetZ
    );
    Math::Vector3D vector = Math::Vector3D(
        ray._direction._x + offsetX,
        ray._direction._y + offsetY,
        ray._direction._z + offsetZ
    );

    double a = ((vector._x * vector._x) + (vector._y * vector._y) + (vector._z * vector._z));
    double b = (2 * ((point._x * vector._x) + (point._y * vector._y) + (point._z * vector._z)));
    double c = ((point._x * point._x) + (point._y * point._y) + (point._z * point._z) - (_radius * _radius));

    double delta = (b * b) - (4 * a * c);

    return delta < 0 ? false : true;
}

void Sphere::setForm(std::string form)
{
    _form = form;
}

void Sphere::setOrigin(Math::Point3D origin)
{
    _origin = origin;
}

void Sphere::setColor(Color color)
{
    _color = color;
}

void Sphere::setSize(std::vector<double> size)
{
    if (size.size() != 1)
        return;
    _radius = size[0];
}

std::string Sphere::getForm()
{
    return _form;
}

Math::Point3D Sphere::getOrigin()
{
    return _origin;
}

Color Sphere::getColor()
{
    return _color;
}

std::vector<double> Sphere::getSize()
{
    return std::vector<double>(1, _radius);
}
