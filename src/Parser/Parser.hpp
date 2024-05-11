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

#include "../Utils/Exception/Exception.hpp"
#include "Factory/PrimitiveFactory.hpp"
#include "Factory/LightFactory.hpp"
#include "../Camera/Camera.hpp"
#include "../Plugins/Display/IDisplay.hpp"
#include "../Plugins/Display/SFML/Sfml.hpp"

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
        std::vector<IPrimitives *> getPrimitives();
        Camera *getCamera();
        IDisplay *getDisplay();
        std::vector<ILight *> getLights();

        bool readFileConfig(Config& cfg);
        void parserInfoCamera(const Setting& root);
        void ParseOnePrimitive(const Setting &primitive);
        void parserInfoPrimitives(const Setting &root);
        void parserInfoLight(const Setting &root, std::string flags = "");
        void printInfoFile() const ;

    protected:

    private:
        std::string _filePath; ///< The path to the input file.
        std::string _flag; ///< Additional flag for additional information, if needed.
        
        Camera *_camera;
        std::vector<IPrimitives *> _primitives;
        IDisplay *_display;
        std::vector<ILight *> _lights;
};

#endif // !PARSER_HPP
