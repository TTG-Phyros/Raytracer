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
#include <tuple>

#include "../Parser/Factory/Factory.hpp"
#include "../Parser/Parser.hpp"
#include "../Camera/Camera.hpp"
#include "../Plugins/Display/SFML/Sfml.hpp"

class Core
{
    public:
        Core(Parser parser, std::string flag = "");
        std::vector<Color> processFrame();
        void inRealTimeDisplay();
        std::vector<Color> displayOneFrame();
        ~Core();

    protected:

    private:
        std::string _flag; ///< Additional flag for additional information, if needed.
        
        std::vector<IPrimitives *> _primitives;
        Camera *_camera;
        IDisplay *_display;
        // std::vector<std::tuple<std::string, std::string>> _camera;
        // std::vector<std::tuple<std::string, std::string>> _primitives;
        std::vector<std::tuple<std::string, std::string>> _lightInfo;
};

#endif // !CORE_HPP
