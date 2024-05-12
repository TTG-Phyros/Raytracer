/**
 * @file Color.cpp
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

#include "Color.hpp"

Color::Color()
{
    _red = 0;
    _green = 0;
    _blue = 0;
    _opacity = 0;
}

Color::Color(double red, double green, double blue, double opacity)
{
    _red = red;
    _green = green;
    _blue = blue;
    _opacity = opacity;
    if (red > 255)
        _red = 255;
    if (green > 255)
        _green = 255;
    if (blue > 255)
        _blue = 255;
    if (opacity > 255)
        _opacity = 255;
}

Color::~Color()
{
}

double Color::getRed()
{
    return _red;
}

double Color::getGreen()
{
    return _green;
}

double Color::getBlue()
{
    return _blue;
}

double Color::getOpacity()
{
    return _opacity;
}

void Color::setRed(double red)
{
    _red = red;
    if (red > 255)
        _red = 255;
}

void Color::setGreen(double green)
{
    _green = green;
    if (green > 255)
        _green = 255;
}

void Color::setBlue(double blue)
{
    _blue = blue;
    if (blue > 255)
        _blue = 255;
}

void Color::setOpacity(double opacity)
{
    _opacity = opacity;
    if (opacity > 255)
        _opacity = 255;
}

Color Color::operator+(Color color)
{
    return Color(_red + color.getRed(), _green + color.getGreen(), _blue + color.getBlue(), _opacity + color.getOpacity());
}

void Color::operator+=(Color color)
{
    _red += color.getRed();
    _green += color.getGreen();
    _blue += color.getBlue();
    _opacity += color.getOpacity();
    if (_red > 255)
        _red = 255;
    if (_green > 255)
        _green = 255;
    if (_blue > 255)
        _blue = 255;
    if (_opacity > 255)
        _opacity = 255;
}
