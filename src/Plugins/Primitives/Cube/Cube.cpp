/**
 * @file Cube.cpp
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

#include "Cube.hpp"

extern "C" IPrimitives *loadCube()
{
    printf("[RayTracer::Cube] Load Cube\n");
    return new Cube();
}

Cube::Cube()
{
    _form = "Cube";
    _origin = Math::Point3D();
    _side = 0.0;
    _color = Color();
}

Cube::Cube(Math::Point3D origin, double side, Color color)
{
    _form = "Cube";
    _origin = origin;
    _side = side;
    _color = color;
}

Cube::~Cube()
{
}

bool Cube::hits(RayTracer::Ray &ray)
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
    return false;
}

void Cube::setForm(std::string form)
{
    _form = form;
}

void Cube::setOrigin(Math::Point3D origin)
{
    _origin = origin;
}

void Cube::setColor(Color color)
{
    _color = color;
}

void Cube::setSize(std::vector<double> size)
{
    if (size.size() != 1)
        return;
    _side = size[0];
}

std::string Cube::getForm()
{
    return _form;
}

Math::Point3D Cube::getOrigin()
{
    return _origin;
}

Color Cube::getColor()
{
    return _color;
}

std::vector<double> Cube::getSize()
{
    return std::vector<double> (1, _side);
}
