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
    _distance = Math::Point3D();
    _xSize = 0;
    _ySize = 0;
}

Camera::Camera(Math::Point3D origin, Math::Point3D distance, double resWidth, double resHeight)
{
    _origin = origin;
    _distance = distance;
    _xSize = 2;
    _ySize = 2 * (resHeight / resWidth);
    _xResolution = resWidth;
    _yResolution = resHeight;
}

void Camera::setXSize(double size)
{
    _xSize = size;
}

void Camera::setYSize(double size)
{
    _ySize = size;
}

double Camera::getXSize()
{
    return _xSize;
}

double Camera::getYSize()
{
    return _ySize;
}

void Camera::setXResolution(double resolution)
{
    _xResolution = resolution;
}

void Camera::setYResolution(double resolution)
{
    _yResolution = resolution;
}

double Camera::getXResolution()
{
    return _xResolution;
}

double Camera::getYResolution()
{
    return _yResolution;
}

void Camera::setOrigin(Math::Point3D origin)
{
    _origin = origin;
    _screenCenter = _origin + _distance;
}

Math::Point3D Camera::getOrigin()
{
    return _origin;
}

void Camera::setScreenDistance(Math::Point3D distance)
{
    _distance = distance;
}

Math::Point3D Camera::getScreenDistance()
{
    return _distance;
}

Math::Point3D Camera::getScreenCenter()
{
    return _origin + _distance;
}

std::vector<RayTracer::Ray> Camera::generateCameraRays()
{
    std::vector<RayTracer::Ray> rays;
    Math::Point3D topLeft = Math::Point3D(getScreenCenter()._x - (_xSize / 2), getScreenCenter()._y - (_ySize / 2), getScreenCenter()._z);
    double pixelXSize = _xSize / _xResolution;
    double pixelYSize = _ySize / _yResolution;
    double distance = 0;
    double offset = 0;

    for (double y = 0; y < _yResolution; y++) {
        for (double x = 0; x < _xResolution; x++) {
            Math::Point3D pixelPosition = Math::Point3D(topLeft._x + (x * pixelXSize), topLeft._y + (y * pixelYSize), topLeft._z);
            // std::cout << "PixelPosition (" << x << ", " << y << ") : " << pixelPosition << std::endl;
            Math::Vector3D direction = Math::Vector3D(_origin, pixelPosition);
            RayTracer::Ray ray = RayTracer::Ray(_origin, direction);
            rays.push_back(ray);
        }
    }
    return rays;
}

Camera::~Camera()
{
}
