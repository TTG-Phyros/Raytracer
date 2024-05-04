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

class Color
{
    public:

        Color();
        Color(int red, int green, int blue, int opacity);

        ~Color();

        std::vector<std::tuple<std::string, int>> getColor();
        int getRed();
        int getGreen();
        int getBlue();
        int getOpacity();

    protected:

    private:

        std::vector<std::tuple<std::string, int>> _Color;

};

#endif // !COLOR_HPP
