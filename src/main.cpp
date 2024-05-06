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

int create_ppm ()
{
    std::ofstream image;
    image.open("image.ppm");

    if (image.is_open()) {
        image << "p3" << std::endl;
        image << "1920 1080" << std::endl;
        image << "255" << std::endl;

        for (int y = 0; y < 250; y++) {
            for (int x = 0; x < 250; x++) {
                image << x << " " << x << " " << x << std::endl;
            }
        }
    }
}

int main(int ac, char **av)
{
    try {
        if (ac == 2 && (std::string(av[1]) == "--help")) {
            std::cout << "USAGE: ./raytracer <SCENE_FILE>\n\tSCENE_FILE: scene configuration" << std::endl;
        } if (ac == 2) {
            Parser parser(av[1]);
        } else if ((ac == 3) && (std::string(av[2]) == "--debug")) {
            Parser parser(av[1], "--debug");
            create_ppm();
        } else {
            throw Exception("Error: invalid arguments");
        }
    } catch(Exception &e) {
        std::cerr << e.what() << std::endl;
        exit(84);
    }
    return 0;
}
