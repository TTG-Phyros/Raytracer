/**
 * @file Core.hpp
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

#ifndef CORE_HPP
#define CORE_HPP

#include <algorithm>
#include <iterator>
#include <sstream>
#include <fstream>
#include <vector>
#include <iostream>
#include <utility>
#include <map>

#include "../Parser/Factory/Factory.hpp"
#include "../Parser/Parser.hpp"

class Core
{
    public:
        Core(Parser parser);
        ~Core();

    protected:

    private:
        std::string _flag; ///< Additional flag for additional information, if needed.
        
        std::vector<std::tuple<std::string, std::string>> _camerasInfo;
        std::vector<std::tuple<std::string, std::string>> _primitivesInfo;
        std::vector<std::tuple<std::string, std::string>> _lightInfo;
};

#endif // !CORE_HPP
