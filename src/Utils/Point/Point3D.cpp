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

#include "Point3D.hpp"

Math::Point3D::Point3D(double x, double y, double z)
{
    _x = x;
    _y = y;
    _z = z;
}

Math::Point3D Math::Point3D::operator+(Math::Vector3D &secondVector)
{
    return Math::Point3D(_x + secondVector._x, _y + secondVector._y, _z + secondVector._z);
}

std::ostream &operator<<(std::ostream &cout, Math::Point3D &point)
{
    return cout << "Point [\n\tx : " << point._x << ",\n\ty : " << point._y << ",\n\tz : " << point._z << "\n]";
}

Math::Point3D::~Point3D()
{
}
