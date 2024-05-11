/**
 * @file Output.hpp
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

#ifndef OUTPUT_HPP_
#define OUTPUT_HPP_

#include <algorithm>
#include <iterator>
#include <sstream>
#include <fstream>
#include <vector>
#include <iostream>
#include <utility>
#include <map>

#include "../Utils/Exception/Exception.hpp"
#include "../Camera/Camera.hpp"
#include "../Plugins/Primitives/IPrimitives.hpp"
#include "../Utils/Color/Color.hpp"

class Output
{
    public:
        Output(Camera *camera, std::vector<IPrimitives *> primitives, std::vector<Color> pixels, const std::string &filepath, const std::string &flag = "");
        ~Output();

    protected:

    private:
        std::string _filePath; ///< The path to the output file.
        std::string _flag; ///< Additional flag for additional information, if needed.
};

#endif /* !OUTPUT_HPP_ */
