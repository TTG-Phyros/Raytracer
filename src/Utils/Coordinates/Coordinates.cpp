/**
 * @file Coordinates.cpp
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

#include "Coordinates.hpp"

#include <cmath>

Coordinates::Coordinates()
{
    _Coordinates.push_back(std::make_tuple("X", 0.0));
    _Coordinates.push_back(std::make_tuple("Y", 0.0));
    _Coordinates.push_back(std::make_tuple("Z", 0.0));
}

Coordinates::Coordinates(double x, double y, double z)
{
    _Coordinates.push_back(std::make_tuple("X", x));
    _Coordinates.push_back(std::make_tuple("Y", y));
    _Coordinates.push_back(std::make_tuple("Z", z));
}

Coordinates::~Coordinates()
{
}

std::vector<std::tuple<std::string, double>> Coordinates::getCoordinates()
{
    return _Coordinates;
}

double Coordinates::getX()
{
    for (const auto& coord : _Coordinates) {
        if (std::get<0>(coord) == "X") {
            return std::get<1>(coord);
        }
    }
    return 0.0;
}

double Coordinates::getY()
{
    for (const auto& coord : _Coordinates) {
        if (std::get<0>(coord) == "Y") {
            return std::get<1>(coord);
        }
    }
    return 0.0;
}

double Coordinates::getZ()
{
    for (const auto& coord : _Coordinates) {
        if (std::get<0>(coord) == "Z") {
            return std::get<1>(coord);
        }
    }
    return 0.0;
}
