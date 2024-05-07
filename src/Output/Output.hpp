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

class Output
{
    public:
        Output(std::vector<std::tuple<std::string, std::string>> camerasInfo, std::vector<std::tuple<std::string, std::string>> primitivesInfo, const std::string &filepath = "", const std::string &flag = "");
        ~Output();

    protected:

    private:
        std::string _filePath;
        std::string _flag;
};

#endif /* !OUTPUT_HPP_ */
