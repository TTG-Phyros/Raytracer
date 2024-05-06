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

#include <iostream>
#include <iomanip>
#include <libconfig.h++>
#include <vector>
#include <tuple>

#include "Creation.hpp"
#include "../Utils/Exception/Exception.hpp"

using namespace std;
using namespace libconfig;

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

        // Getter
        std::vector<std::tuple<std::string, std::string>> getCameraInfo();
        std::vector<std::tuple<std::string, std::string>> getPrimitivesInfo();

        bool readFileConfig(Config& cfg);
        void parserInfoCamera(const Setting& root);
        void parserInfoPrimitives(const Setting& root);
        void printInfoFile() const ;
        std::vector<std::pair<std::string, std::string>> GetInfo(const Parser& parser);

    protected:

    private:
        std::string _filePath;            ///< The path to the file to be parsed.
        std::string _flag;                ///< Additional flag for parsing, if needed.
        std::vector<std::tuple<std::string, std::string>> _camerasInfo;
        std::vector<std::tuple<std::string, std::string>> _primitivesInfo;
};

#endif // !PARSER_HPP
