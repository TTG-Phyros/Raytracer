/**
 * @file Parser.hpp
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

#ifndef PARSER_HPP
#define PARSER_HPP

#include <algorithm>
#include <iterator>
#include <sstream>
#include <fstream>
#include <vector>
#include <iostream>
#include <utility>
#include <map>

/**
 * @class Parser
 * @brief Class for parsing files.
 * @details This class provides functionality to parse a file containing information.
 */
class Parser
{
    public:
        Parser(const std::string &filepath = "", const std::string &flag = "");
        ~Parser();

    protected:

    private:
        

        std::string _filePath;            ///< The path to the file to be parsed.
        std::string _flag;                ///< Additional flag for parsing, if needed.
};

#endif // !PARSER_HPP
