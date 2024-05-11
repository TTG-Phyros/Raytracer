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
    // std::cout << "Pixel at pos : (" << x << ", " << y << ") and color : (" << round(red) << ", " << round(green) << ", " << round(blue) << ")" << std::endl;
    sf::RectangleShape pixel = sf::RectangleShape(sf::Vector2f(1,1));
    pixel.setPosition(sf::Vector2f(x, y));
    pixel.setFillColor(sf::Color(round(red), round(green), round(blue)));
    _window.draw(pixel);
}

void Sfml::setResolution(int xSize, int ySize)
{
    _window.close();
    _window.create(sf::VideoMode(xSize, ySize), "RayTracer");
    _xSize = xSize;
    _ySize = ySize;
}

void Sfml::display()
{
    _window.display();
}

void Sfml::clear()
{
    _window.clear();
}

void Sfml::close()
{
    _window.close();
}

bool Sfml::isOpen()
{
    return _window.isOpen();
}

void Sfml::move(Camera *camera)
{
    Math::Point3D origin;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        std::cout << "Moved in x -5" << std::endl;
        origin = camera->getOrigin();
        Math::Point3D offset = Math::Point3D(-5, 0, 0);
        origin = origin + offset;
        camera->setOrigin(origin);
        origin = camera->getOrigin();
        std::cout << "New Coords : " << origin << std::endl;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        std::cout << "Moved in x +5" << std::endl;
        origin = camera->getOrigin();
        Math::Point3D offset = Math::Point3D(5, 0, 0);
        origin = origin + offset;
        camera->setOrigin(origin);
        origin = camera->getOrigin();
        std::cout << "New Coords : " << origin << std::endl;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        std::cout << "Moved in y +5" << std::endl;
        origin = camera->getOrigin();
        Math::Point3D offset = Math::Point3D(0, 5, 0);
        origin = origin + offset;
        camera->setOrigin(origin);
        origin = camera->getOrigin();
        std::cout << "New Coords : " << origin << std::endl;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        std::cout << "Moved in y -5" << std::endl;
        origin = camera->getOrigin();
        Math::Point3D offset = Math::Point3D(0, -5, 0);
        origin = origin + offset;
        camera->setOrigin(origin);
        origin = camera->getOrigin();
        std::cout << "New Coords : " << origin << std::endl;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::PageDown)) {
        std::cout << "Moved in z -5" << std::endl;
        origin = camera->getOrigin();
        Math::Point3D offset = Math::Point3D(0, 0, -5);
        origin = origin + offset;
        camera->setOrigin(origin);
        origin = camera->getOrigin();
        std::cout << "New Coords : " << origin << std::endl;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::PageUp)) {
        std::cout << "Moved in z +5" << std::endl;
        origin = camera->getOrigin();
        Math::Point3D offset = Math::Point3D(0, 0, 5);
        origin = origin + offset;
        camera->setOrigin(origin);
        origin = camera->getOrigin();
        std::cout << "New Coords : " << origin << std::endl;
    }
}

Sfml::~Sfml()
{
    _window.close();
}
