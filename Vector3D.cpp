/*
** EPITECH PROJECT, 2024
** BootStrap
** File description:
** Vector3D
*/

#include "Vector3D.hpp"
#include <math.h>

Math::Vector3D::Vector3D(double x, double y, double z)
{
    _x = x;
    _y = y;
    _z = z;
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

double Math::Vector3D::dot()
{
    return (_x + _y + _z);
}

Math::Vector3D::~Vector3D()
{
}

std::ostream &operator<<(std::ostream &cout, Math::Vector3D &vector)
{
    return cout << "Vector [\n\tx : " << vector._x << ",\n\ty : " << vector._y << ",\n\tz : "<< vector._z << "\n]";
}