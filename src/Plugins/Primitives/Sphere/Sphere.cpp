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

// bool Sphere::hits(RayTracer::Ray &ray)
// {
//     double offsetX = _origin._x;
//     double offsetY = _origin._y;
//     double offsetZ = _origin._z;

//     Math::Point3D point = Math::Point3D(
//         ray._origin._x + offsetX,
//         ray._origin._y + offsetY,
//         ray._origin._z + offsetZ
//     );
//     Math::Vector3D vector = Math::Vector3D(
//         ray._direction._x + offsetX,
//         ray._direction._y + offsetY,
//         ray._direction._z + offsetZ
//     );

//     double a = ((vector._x * vector._x) + (vector._y * vector._y) + (vector._z * vector._z));
//     double b = (2 * ((point._x * vector._x) + (point._y * vector._y) + (point._z * vector._z)));
//     double c = ((point._x * point._x) + (point._y * point._y) + (point._z * point._z) - (_radius * _radius));

//     double delta = (b * b) - (4 * a * c);

//     return delta < 0 ? false : true;
// }

bool Sphere::pointing(RayTracer::Ray &ray)
{
    Math::Vector3D toCenter = {_origin._x - ray._origin._x, _origin._y - ray._origin._y, _origin._z - ray._origin._z};
    float dotProduct = ray._direction._x * toCenter._x + ray._direction._y * toCenter._y + ray._direction._z * toCenter._z;

    return dotProduct >= 0;
}

bool Sphere::hits(RayTracer::Ray &ray, double &distance)
{
    if (!pointing(ray))
        return false;

    distance = -1;
    Math::Vector3D oc = {ray._origin._x - _origin._x, ray._origin._y - _origin._y, ray._origin._z - _origin._z};
    float a = ray._direction._x * ray._direction._x + ray._direction._y * ray._direction._y + ray._direction._z * ray._direction._z;
    float b = 2.0f * (oc._x * ray._direction._x + oc._y * ray._direction._y + oc._z * ray._direction._z);
    float c = oc._x * oc._x + oc._y * oc._y + oc._z * oc._z - _radius * _radius;
    float discriminant = b * b - 4 * a * c;

    if (discriminant > 0.0) {
        double t1 = (-b + sqrt(discriminant)) / (2.0 * a);
        double t2 = (-b - sqrt(discriminant)) / (2.0 * a);

        // std::cout << "Delta first solution : " << t1 << ", Delta second solution : " << t2 << std::endl;
        if (t1 < 0.0 || t2 < 0.0) {
            return false;
        } else {
            distance = t1 <= t2 ? t1 : t2;
            return true;
        }
    } else if (discriminant == 0) {
        // std::cout << "Delta only solution : " << -b / (2 * a) << std::endl;
        distance = -b / (2 * a);
        return true;
    } else {
        return false;
    }
}

std::vector<double> Sphere::hits(std::vector<RayTracer::Ray> rays, double &minDistance, double &maxDistance)
{
    std::vector<double> distanceRays;

    double distance = 0;
    for (unsigned int i = 0; i < rays.size(); i++) {
        if (!pointing(rays[i])) {
            distanceRays.push_back(-1);
            continue;
        }
        Math::Vector3D oc = {rays[i]._origin._x - _origin._x, rays[i]._origin._y - _origin._y, rays[i]._origin._z - _origin._z};
        float a = rays[i]._direction._x * rays[i]._direction._x + rays[i]._direction._y * rays[i]._direction._y + rays[i]._direction._z * rays[i]._direction._z;
        float b = 2.0f * (oc._x * rays[i]._direction._x + oc._y * rays[i]._direction._y + oc._z * rays[i]._direction._z);
        float c = oc._x * oc._x + oc._y * oc._y + oc._z * oc._z - _radius * _radius;
        float discriminant = b * b - 4 * a * c;

        if (discriminant > 0.0) {
            double t1 = (-b + sqrt(discriminant)) / (2.0 * a);
            double t2 = (-b - sqrt(discriminant)) / (2.0 * a);

            // std::cout << "Delta first solution : " << t1 << ", Delta second solution : " << t2 << std::endl;
            if (t1 < 0.0 || t2 < 0.0) {
                distanceRays.push_back(-1);
                continue;
            } else {
                distance = t1 <= t2 ? t1 : t2;
                minDistance = distance < minDistance ? distance : minDistance;
                maxDistance = distance > maxDistance ? distance : maxDistance;
                distanceRays.push_back(distance);
                continue;
            }
        } else if (discriminant == 0) {
            // std::cout << "Delta only solution : " << -b / (2 * a) << std::endl;
            distance = -b / (2 * a);
            minDistance = distance < minDistance ? distance : minDistance;
            maxDistance = distance > maxDistance ? distance : maxDistance;
            distanceRays.push_back(distance);
            continue;
        } else {
            distanceRays.push_back(-1);
            continue;
        }
    }
    return distanceRays;
}

// bool Sphere::hits(RayTracer::Ray &ray)
// {
//     Math::Point3D uv = 
// }

// bool Sphere::hits(RayTracer::Ray &ray)
// {
//     double offsetX = _origin._x;
//     double offsetY = _origin._y;
//     double offsetZ = _origin._z;

//     Math::Point3D point = Math::Point3D(
//         ray._origin._x + offsetX,
//         ray._origin._y + offsetY,
//         ray._origin._z + offsetZ
//     );
//     Math::Vector3D vector = Math::Vector3D(
//         ray._direction._x + offsetX,
//         ray._direction._y + offsetY,
//         ray._direction._z + offsetZ
//     );

//     double a = ((vector._x * vector._x) + (vector._y * vector._y) + (vector._z * vector._z));
//     double b = (2 * ((point._x * vector._x) + (point._y * vector._y) + (point._z * vector._z)));
//     double c = ((point._x * point._x) + (point._y * point._y) + (point._z * point._z) - (_radius * _radius));

//     double delta = (b * b) - (4 * a * c);

//     // std::cout << "Delta : " << delta << " = (" << b << " * " << b << ") - (4 * " << a << " * " << c << ")" << std::endl;

//     if (delta > 0.0) {
//         double numSQRT = sqrtf(delta);
//         double t1 = (-b + numSQRT) / 2.0;
//         double t2 = (-b - numSQRT) / 2.0;

//         // std::cout << "Squared delta : " << numSQRT << ", t1 : " << t1 << ", t2 : " << t2 << std::endl;
//         if (t1 < 0.0 || t2 < 0.0) {
//             return true;
//         } else {
//             return false;
//         }
//     } else {
//         return false;
//     }
// }

// bool Sphere::hits(RayTracer::Ray &ray)
// {
//     double a = 1.0;
//     double b = 2.0 * ray._direction.dot(ray._origin);
//     double c = ray._direction.dot(ray._direction) - 1.0;

//     double delta = (b * b) - (4 * a * c);

//     return delta > 0.0 ? true : false;
// }

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
