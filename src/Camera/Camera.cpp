/**
 * @file Camera.cpp
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

#include "Camera.hpp"

Camera::Camera()
{
    _origin = Math::Point3D();
    _screenCenter = Math::Point3D();
    _xSize = 0;
    _ySize = 0;
}

Camera::Camera(Math::Point3D origin, Math::Point3D screenCenter, int xSize, int ySize)
{
    _origin = origin;
    _screenCenter = screenCenter;
    _xSize = xSize;
    _ySize = ySize;
}

void Camera::setXSize(int size)
{
    _xSize = size;
}

void Camera::setYSize(int size)
{
    _ySize = size;
}

int Camera::getXSize()
{
    return _xSize;
}

int Camera::getYSize()
{
    return _ySize;
}

void Camera::setOrigin(Math::Point3D origin)
{
    _origin = origin;
}

void Camera::setScreenCenter(Math::Point3D screenCenter)
{
    _screenCenter = screenCenter;
}

Math::Point3D Camera::getOrigin()
{
    return _origin;
}

Math::Point3D Camera::getScreenCenter()
{
    return _screenCenter;
}

RayTracer::Ray Camera::generateRay(int x, int y)
{
    double xMultiplier = 1 / (static_cast<double>(_xSize) / 2);
    double yMultiplier = 1 / (static_cast<double>(_ySize) / 2);

    // std::cout << "Camera Ray Multipliers : " << xMultiplier << " | " << yMultiplier << std::endl;
    return RayTracer::Ray(_origin, Math::Vector3D((static_cast<double>(x) * xMultiplier) - 1, (static_cast<double>(y) * yMultiplier) - 1));
}

Camera::~Camera()
{
}
