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
        Color(int red, int green, int blue, int opacity);

        ~Color();

        int getRed();
        int getGreen();
        int getBlue();
        int getOpacity();

    protected:

    private:
        int _red;
        int _green;
        int _blue;
        int _alpha;
};

#endif // !COLOR_HPP
