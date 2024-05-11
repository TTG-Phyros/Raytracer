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
    _radius = 0.0;
    _color = Color();
}

Plane::Plane(Math::Point3D origin, double radius, Color color)
{
    _form = "Plane";
    _origin = origin;
    _radius = radius;
    _color = color;
}

Plane::~Plane()
{
}

void Math::Vector3D::Normalize()
{
    double length = getLength();
    if (length != 0.0) {
        _x /= length;
        _y /= length;
        _z /= length;
    }
}

bool Plane::hits(RayTracer::Ray &ray, double &distance)
{
    // Définition de l'origine du plan XY comme (0, 0, 0)
    Math::Point3D planeOrigin(0.0, 0.0, 0.0);

    // Définition de la normale ( vecteur qui est perpendiculaire au plan ) du plan XY 
    Math::Vector3D planeNormal(0.0, 0.0, -1.0);

    // Calcul du vecteur entre l'origine du rayon et l'origine du plan XY


    /* ancienne ligne fausse mais que je garde au cas où ) // Math::Vector3D rayToPlane = planeOrigin - ray._origin;*/

    Math::Vector3D rayToPlane = Math::Vector3D(ray._origin, planeOrigin);
    
    // Calcul du numérateur pour l'intersection entre le rayon et le plan
    double numerator = rayToPlane.Dot(planeNormal);
    
    // Calcul du dénominateur pour l'intersection entre le rayon et le plan
    double denominator = ray._direction.Dot(planeNormal);

    if (denominator != 0.0)
    {
        // Calcul de la distance d'intersection entre le rayon et le plan
        double intersectionDistance = numerator / denominator;
        
        // je vérifie si l'intersection est dans la direction du rayon
        if (intersectionDistance > 0.0)
        {
            // je donne la distance d'intersection que j'ai calculée
            distance = intersectionDistance;
            return true;
        }
    }
    return false; 
}

std::vector<double> Plane::hits(std::vector<RayTracer::Ray> rays, double &minDistance, double &maxDistance)
{
    std::vector<double> distanceRays;
    return distanceRays;
}

// bool hits(const RayTracer::Ray &ray, double &distance)
// {
//     Math::Vector3D planeOrigin(0.0, 0.0, 0.0);

//     Math::Vector3D planeNormal(0.0, 0.0, -1.0);

//     Math::Vector3D rayDirection = ray._direction;
//     rayDirection.Normalize();

//     Math::Vector3D rayToPlane = planeOrigin - ray._origin;

//     double numerator = rayToPlane.Dot(planeNormal);
//     double denominator = rayDirection.Dot(planeNormal);
//     if (denominator != 0.0)
//     {
//         double intersectionDistance = numerator / denominator;
        
//         if (intersectionDistance > 0.0)
//         {
//             Math::Vector3D intersectionPoint = ray._origin + rayDirection * intersectionDistance;
            
//             if (abs(intersectionPoint._x) < 1.0 && abs(intersectionPoint._y) < 1.0)
//             {
//                 distance = intersectionDistance;
//                 return true;
//             }
//         }
//     }
//     return false;
// }

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
    if (size.size() != 1)
        return;
    _radius = size[0];
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
    return std::vector<double>(1, _radius);
}
