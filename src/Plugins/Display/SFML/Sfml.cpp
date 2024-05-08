/**
 * @file Sfml.cpp
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

#include "Sfml.hpp"

extern "C" IDisplay *loadSFML()
{
    printf("[RayTracer::Display] Load SFML\n");
    return new Sfml();
}

Sfml::Sfml()
{
    _window.create(sf::VideoMode(426, 240), "RayTracer");
    _xSize = 426;
    _ySize = 240;
}

Sfml::Sfml(int xSize, int ySize)
{
    _window.create(sf::VideoMode(xSize, ySize), "RayTracer");
    _xSize = xSize;
    _ySize = ySize;
}

void Sfml::setPixel(int x, int y, double red, double green, double blue)
{
    if (x < 0 || x > _xSize)
        return;
    if (y < 0 || y > _ySize)
        return;
    sf::RectangleShape pixel = sf::RectangleShape(sf::Vector2f(1,1));
    pixel.setPosition(sf::Vector2f(x, y));
    pixel.setFillColor(sf::Color(red, green, blue));
    _window.draw(pixel);
}

void Sfml::display()
{
    _window.display();
}

void Sfml::clear()
{
    _window.clear();
}

Sfml::~Sfml()
{
    _window.close();
}
