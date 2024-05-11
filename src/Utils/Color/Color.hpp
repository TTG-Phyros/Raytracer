/**
 * @file Color.hpp
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

#ifndef COLOR_HPP
#define COLOR_HPP

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <tuple>

class Color
{
    public:
        Color();
        Color(double red, double green, double blue, double opacity);

        ~Color();

        double getRed();
        double getGreen();
        double getBlue();
        double getOpacity();

        void setRed(double red);
        void setGreen(double green);
        void setBlue(double blue);
        void setOpacity(double opacity);

        Color operator+(Color color);
        void operator+=(Color color);

    protected:

    private:
        double _red;
        double _green;
        double _blue;
        double _opacity;
};

#endif // !COLOR_HPP
