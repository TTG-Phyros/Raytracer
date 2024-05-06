/**
 * @file main.cpp
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

#include <iostream>
#include <algorithm>
#include <iterator>
#include <sstream>
#include <fstream>
#include <vector>
#include <iostream>
#include <utility>

#include "Parser/Parser.hpp"
#include "Utils/Exception/Exception.hpp"

int create_header_ppm(std::vector<std::tuple<std::string, std::string>> camerasInfo, std::vector<std::tuple<std::string, std::string>> primitiveInfo)
{
    std::ofstream image;
    image.open("image.ppm");

    std::string width;
    std::string height;
    std::string color_r;
    std::string color_g;
    std::string color_b;

    for (const auto& info : camerasInfo) {
        if (std::get<0>(info) == "width_resolution")
            width = std::get<1>(info);
        if (std::get<0>(info) == "height_resolution")
            height = std::get<1>(info);
    }

    for (const auto& info : primitiveInfo) {
        if (std::get<0>(info) == "color_r")
            color_r = std::get<1>(info);
        if (std::get<0>(info) == "color_g")
            color_g = std::get<1>(info);
        if (std::get<0>(info) == "color_b")
            color_b = std::get<1>(info);
    }

    if (image.is_open()) {
        image << "p3" << std::endl;
        image << width << " ";
        image << height << std::endl;
        image << color_r << " ";
        image << color_g << " ";
        image << color_b << std::endl;

        for (int y = 0; y < 250; y++) {
            for (int x = 0; x < 250; x++) {
                image << x << " " << x << " " << x << std::endl;
            }
        }
        image.close();
    } else {
        std::cerr << "Erreur: Impossible d'ouvrir le fichier image.ppm" << std::endl;
        return -1;
    }
    return 0;
}

int main(int ac, char **av)
{
    try {
        if (ac == 2 && (std::string(av[1]) == "--help")) {
            std::cout << "USAGE: ./raytracer <SCENE_FILE>\n\tSCENE_FILE: scene configuration" << std::endl;
        } if (ac == 2) {
            Parser parser(av[1]);
            create_header_ppm(parser.getCameraInfo(), parser.getPrimitivesInfo());
        } else if ((ac == 3) && (std::string(av[2]) == "--debug")) {
            Parser parser(av[1], "--debug");
        } else {
            throw Exception("Error: invalid arguments");
        }
    } catch(Exception &e) {
        std::cerr << e.what() << std::endl;
        exit(84);
    }
    return 0;
}
