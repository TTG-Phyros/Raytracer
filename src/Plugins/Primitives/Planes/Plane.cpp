/**
 * @file Plane.cpp
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

#include "Plane.hpp"

extern "C" IPrimitives *loadPlane()
{
    printf("[RayTracer::Plane] Load Plane\n");
    return new Plane();
}

Plane::Plane()
{
    _form = "Plane";
    _origin = Math::Point3D();
    _color = Color();
}

Plane::Plane(Math::Point3D origin, Color color)
{
    _form = "Plane";
    _origin = origin;
    _color = color;
}

Plane::~Plane()
{
}

bool Plane::hits(RayTracer::Ray &ray, double &distance)
{
    double multiplier;
    if (_origin._x != 0) {
        multiplier = _origin._x / -(ray._direction._x);
        if (multiplier < 0)
            return false;
        distance = (ray._direction * multiplier).getLength();
    }
    if (_origin._y != 0) {
        multiplier = _origin._y / -(ray._direction._y);
        if (multiplier < 0)
            return false;
        distance = (ray._direction * multiplier).getLength();
    }
    if (_origin._z != 0) {
        multiplier = _origin._z / -(ray._direction._z);
        if (multiplier < 0)
            return false;
        distance = (ray._direction * multiplier).getLength();
    }
    return true;
}

std::vector<double> Plane::hits(std::vector<RayTracer::Ray> rays, double &minDistance, double &maxDistance)
{
    std::vector<double> distanceRays;
    double multiplier;
    for (int i = 0; i < rays.size(); i++) {
        if (_origin._x != 0) {
            multiplier = _origin._x / -(rays[i]._direction._x);
            if (multiplier < 0) {
                distanceRays.push_back(-1);
                continue;
            }
            distanceRays.push_back((rays[i]._direction * multiplier).getLength());
            if (distanceRays[i] < minDistance)
                minDistance = distanceRays[i];
            if (distanceRays[i] > maxDistance)
                maxDistance = distanceRays[i];
        }
        if (_origin._y != 0) {
            multiplier = _origin._y / -(rays[i]._direction._y);
            if (multiplier < 0) {
                distanceRays.push_back(-1);
                continue;
            }
            distanceRays.push_back((rays[i]._direction * multiplier).getLength());
            if (distanceRays[i] < minDistance)
                minDistance = distanceRays[i];
            if (distanceRays[i] > maxDistance)
                maxDistance = distanceRays[i];
        }
        if (_origin._z != 0) {
            multiplier = _origin._z / -(rays[i]._direction._z);
            if (multiplier < 0) {
                distanceRays.push_back(-1);
                continue;
            }
            distanceRays.push_back((rays[i]._direction * multiplier).getLength());
            if (distanceRays[i] < minDistance)
                minDistance = distanceRays[i];
            if (distanceRays[i] > maxDistance)
                maxDistance = distanceRays[i];
        }
    }
    return distanceRays;
}

void Plane::setForm(std::string form)
{
    _form = form;
}

void Plane::setOrigin(Math::Point3D origin)
{
    _origin = origin;
}

void Plane::setColor(Color color)
{
    _color = color;
}

void Plane::setSize(std::vector<double> size)
{
    if (size.size() != 3)
        return;
    _origin = Math::Point3D(size[0], size[1], size[2]);
}

std::string Plane::getForm()
{
    return _form;
}

Math::Point3D Plane::getOrigin()
{
    return _origin;
}

Color Plane::getColor()
{
    return _color;
}

std::vector<double> Plane::getSize()
{
    std::vector<double> size;
    size.push_back(_origin._x);
    size.push_back(_origin._y);
    size.push_back(_origin._z);
    return size;
}
