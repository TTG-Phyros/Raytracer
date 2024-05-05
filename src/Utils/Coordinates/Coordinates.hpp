/**
 * @file Coordinates.hpp
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

#ifndef COORDINATES_HPP
#define COORDINATES_HPP

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <tuple>

class Coordinates
{
    public:

        Coordinates();
        Coordinates(double x, double y, double z);

        ~Coordinates();

        std::vector<std::tuple<std::string, double>> getCoordinates();
        double getX();
        double getY();
        double getZ();

    protected:

    private:

        std::vector<std::tuple<std::string, double>> _Coordinates;

};

#endif // !COORDINATES_HPP
