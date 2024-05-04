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
    _Color.push_back(std::make_tuple("R", 0));
    _Color.push_back(std::make_tuple("G", 0));
    _Color.push_back(std::make_tuple("B", 0));
    _Color.push_back(std::make_tuple("O", 0));
}

Color::Color(int red, int green, int blue, int opacity)
{
    _Color.push_back(std::make_tuple("R", red));
    _Color.push_back(std::make_tuple("G", green));
    _Color.push_back(std::make_tuple("B", blue));
    _Color.push_back(std::make_tuple("O", opacity));
}

Color::~Color()
{
}

std::vector<std::tuple<std::string, int>> Color::getColor()
{
    return _Color;
}

int Color::getRed()
{
    for (const auto& coord : _Color) {
        if (std::get<0>(coord) == "R") {
            return std::get<1>(coord);
        }
    }
    return 0.0;
}

int Color::getGreen()
{
    for (const auto& coord : _Color) {
        if (std::get<0>(coord) == "G") {
            return std::get<1>(coord);
        }
    }
    return 0.0;
}

int Color::getBlue()
{
    for (const auto& coord : _Color) {
        if (std::get<0>(coord) == "B") {
            return std::get<1>(coord);
        }
    }
    return 0.0;
}

int Color::getOpacity()
{
    for (const auto& coord : _Color) {
        if (std::get<0>(coord) == "O") {
            return std::get<1>(coord);
        }
    }
    return 0.0;
}
