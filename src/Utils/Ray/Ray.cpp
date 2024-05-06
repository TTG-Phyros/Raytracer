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
