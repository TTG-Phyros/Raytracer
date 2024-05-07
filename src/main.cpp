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
#include "Core/Core.hpp"
#include "Output/Output.hpp"
#include "Utils/Exception/Exception.hpp"

int main(int ac, char **av)
{
    try {
        if (ac == 2 && (std::string(av[1]) == "--help")) {
            std::cout << "USAGE: ./raytracer <SCENE_FILE>\n\tSCENE_FILE: scene configuration" << std::endl;
        } if (ac == 2) {
            // PARSING INPUT FILE
            Parser parser(av[1]);

            // DO CORE

            // WRITE OUTPUT FILE
            // Output output(parser.getCameraInfo(), parser.getPrimitives(), "./screenshots/image.ppm");
        } else if ((ac == 3) && (std::string(av[2]) == "--debug")) {
            // PARSING INPUT FILE
            Parser parser(av[1], "--debug");

            // DO CORE
            
            // WRITE OUTPUT FILE
            // Output output(parser.getCameraInfo(), parser.getPrimitives(), "./screenshots/image.ppm", "--debug");
        } else {
            throw Exception("Error: invalid arguments");
        }
    } catch(Exception &e) {
        std::cerr << e.what() << std::endl;
        exit(84);
    }
    return 0;
}
