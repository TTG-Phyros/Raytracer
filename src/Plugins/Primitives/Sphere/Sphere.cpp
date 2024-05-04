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
    _origin = Coordinates();
    _radius = 0.0;
    _color = Color();
}

Sphere::Sphere(Coordinates origin, double radius, Color color)
{
    _form = "Sphere";
    _origin = origin;
    _radius = radius;
    _color = color;
}

Sphere::~Sphere()
{
}

bool Sphere::hits(Coordinates vectorOrigin, Coordinates vectorDirection)
{
    double offsetX = _origin.getX();
    double offsetY = _origin.getY();
    double offsetZ = _origin.getZ();

    Coordinates point = Coordinates(vectorOrigin.getX() - _origin.getX(), vectorOrigin.getY() - _origin.getY(), vectorOrigin.getZ() - _origin.getZ());

    Coordinates vector = Coordinates(
        vectorDirection.getX() - _origin.getX(),
        vectorDirection.getY() - _origin.getY(),
        vectorDirection.getZ() - _origin.getZ()
    );

    double a = ((vector.getX() * vector.getX()) + (vector.getY() * vector.getY()) + (vector.getZ() * vector.getZ()));
    double b = (2 * ((point.getX() * vector.getX()) + (point.getY() * vector.getY()) + (point.getZ() * vector.getZ())));
    double c = ((point.getX() * point.getX()) + (point.getY() * point.getY()) + (point.getZ() * point.getZ()) - (_radius * _radius));

    double delta = (b * b) - (4 * a * c);

    return delta < 0 ? false : true;
}

void Sphere::setColor(Color color)
{
    _color = color;
}

void Sphere::setOrigin(Coordinates origin)
{
    _origin = origin;
}

std::string Sphere::getForm()
{
    return _form;
}

Coordinates Sphere::getOrigin()
{
    return _origin;
}

Color Sphere::getColor()
{
    return _color;
}

double Sphere::getRadius()
{
    return _radius;
}
