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
    _alpha = 0;
}

Color::Color(int red, int green, int blue, int opacity)
{
    _red = red;
    _green = green;
    _blue = blue;
    _alpha = opacity;
}

Color::~Color()
{
}

int Color::getRed()
{
    return _red;
}

int Color::getGreen()
{
    return _green;
}

int Color::getBlue()
{
    return _blue;
}

int Color::getOpacity()
{
    return _alpha;
}
