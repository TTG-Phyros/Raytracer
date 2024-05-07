/**
 * @file Output.cpp
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

#include "Output.hpp"

Output::Output(std::vector<std::tuple<std::string, std::string>> camerasInfo, std::vector<std::tuple<std::string, std::string>> primitivesInfo, const std::string &filepath, const std::string &flag)
    : _filePath(filepath), _flag(flag)
{
    if (!_flag.empty()) {
        std::cout << "--------------------------------" << std::endl;
        std::cout << "| Output : Debug Informations. |" << std::endl;
        std::cout << "--------------------------------" << std::endl;
    }
    try
    {
        if (!_filePath.empty() && _filePath.length() <= 4 || _filePath.substr(_filePath.length() - 4, 4) != ".ppm") {
            throw Exception("Error: invalid file extension, see --help for more information");
        }
        std::ofstream image;
        image.open(_filePath);

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

        for (const auto& info : primitivesInfo) {
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
            std::cerr << "Error: Can't open image.ppm file" << std::endl;
        }
    }
    catch(const Exception& e)
    {
        std::cerr << e.what() << std::endl;
        exit(84);
    }
}

Output::~Output()
{
}
