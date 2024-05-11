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

Output::Output(Camera *camera, std::vector<IPrimitives *> primitives, std::vector<Color> pixels, const std::string &filepath, const std::string &flag)
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

        if (image.is_open()) {
            image << "P3" << std::endl;
            image << camera->getXResolution() << " ";
            image << camera->getYResolution() << std::endl;
            image << 255 << std::endl;

            for (auto pixel : pixels)
                image << round(pixel.getRed()) << " " << round(pixel.getGreen()) << " " << round(pixel.getBlue()) << std::endl;
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
