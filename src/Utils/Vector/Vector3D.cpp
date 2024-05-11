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

#include "Vector3D.hpp"

Math::Vector3D::Vector3D(double x, double y, double z)
{
    _x = x;
    _y = y;
    _z = z;
}

Math::Vector3D::Vector3D(Math::Point3D origin, Math::Point3D end)
{
    _origin = origin;
    _end = end;
    _x = _end._x - _origin._x;
    _y = _end._y - _origin._y;
    _z = _end._z - _origin._z;
}

double Math::Vector3D::getLength()
{
    return sqrt((_x * _x) + (_y * _y) + (_z * _z));
}

Math::Vector3D Math::Vector3D::operator+(Math::Vector3D &secondVector)
{
    return Math::Vector3D(_x + secondVector._x, _y + secondVector._y, _z + secondVector._z);
}

void Math::Vector3D::operator+=(Math::Vector3D &secondVector)
{
    _x += secondVector._x;
    _y += secondVector._y;
    _z += secondVector._z;
}

Math::Vector3D Math::Vector3D::operator-(Math::Vector3D &secondVector)
{
    return Math::Vector3D(_x - secondVector._x, _y - secondVector._y, _z - secondVector._z);
}

void Math::Vector3D::operator-=(Math::Vector3D &secondVector)
{
    _x -= secondVector._x;
    _y -= secondVector._y;
    _z -= secondVector._z;
}

Math::Vector3D Math::Vector3D::operator*(Math::Vector3D &secondVector)
{
    return Math::Vector3D(_x * secondVector._x, _y * secondVector._y, _z * secondVector._z);
}

void Math::Vector3D::operator*=(Math::Vector3D &secondVector)
{
    _x *= secondVector._x;
    _y *= secondVector._y;
    _z *= secondVector._z;
}

Math::Vector3D Math::Vector3D::operator/(Math::Vector3D &secondVector)
{
    return Math::Vector3D(_x / secondVector._x, _y / secondVector._y, _z / secondVector._z);
}

void Math::Vector3D::operator/=(Math::Vector3D &secondVector)
{
    _x /= secondVector._x;
    _y /= secondVector._y;
    _z /= secondVector._z;
}

Math::Vector3D Math::Vector3D::operator*(double nb)
{
    return Math::Vector3D(_x * nb, _y * nb, _z * nb);
}

void Math::Vector3D::operator*=(double nb)
{
    _x *= nb;
    _y *= nb;
    _z *= nb;
}

Math::Vector3D Math::Vector3D::operator/(double nb)
{
    return Math::Vector3D(_x / nb, _y / nb, _z / nb);
}

void Math::Vector3D::operator/=(double nb)
{
    _x /= nb;
    _y /= nb;
    _z /= nb;
}

double Math::Vector3D::dot(Math::Vector3D otherVector)
{
    return ((_x * otherVector._x) + (_y * otherVector._y) + (_z * otherVector._z));
}

double Math::Vector3D::dot(Math::Point3D otherPoint)
{
    return ((_x * otherPoint._x) + (_y * otherPoint._y) + (_z * otherPoint._z));
}

Math::Vector3D::~Vector3D()
{
}

std::ostream &operator<<(std::ostream &cout, Math::Vector3D &vector)
{
    return cout << "Vector [\n\tx : " << vector._x << ",\n\ty : " << vector._y << ",\n\tz : "<< vector._z << "\n]";
}