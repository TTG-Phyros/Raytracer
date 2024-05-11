/**
 * @file Directional.cpp
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

#include "Directional.hpp"

extern "C" ILight *loadDirectionalLight()
{
    printf("[RayTracer::Light] Load Directional Light\n");
    return new DirectionalLight();
}

DirectionalLight::DirectionalLight()
{
    _type = "Directional";
    _origin = Math::Point3D();
    _direction = Math::Vector3D();
    _color = Color();
    _strengh = 0.0;
}

DirectionalLight::DirectionalLight(Math::Point3D origin, Math::Vector3D direction, Color color, double strengh)
{
    _type = "Directional";
    _origin = origin;
    _direction = direction;
    _color = color;
    _strengh = strengh;
}

void DirectionalLight::setType(std::string type)
{
    _type = type;
}

void DirectionalLight::setOrigin(Math::Point3D origin)
{
    _origin = origin;
}

void DirectionalLight::setDirection(Math::Vector3D direction)
{
    _direction = direction;
}

void DirectionalLight::setColor(Color color)
{
    _color = color;
}

void DirectionalLight::setStrengh(double strengh)
{
    _strengh = strengh;
}

std::string DirectionalLight::getType()
{
    return _type;
}

Math::Point3D DirectionalLight::getOrigin()
{
    return _origin;
}

Math::Vector3D DirectionalLight::getDirection()
{
    return _direction;
}

Color DirectionalLight::getColor()
{
    return _color;
}

double DirectionalLight::getStrengh()
{
    return _strengh;
}

DirectionalLight::~DirectionalLight()
{

}
