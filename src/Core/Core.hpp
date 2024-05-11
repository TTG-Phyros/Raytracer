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

#include "../Parser/Factory/PrimitiveFactory.hpp"
#include "../Parser/Factory/LightFactory.hpp"
#include "../Parser/Parser.hpp"
#include "../Camera/Camera.hpp"
#include "../Plugins/Display/SFML/Sfml.hpp"

class Core
{
    public:
        Core(Parser parser, std::string flag = "");
        bool checkIfPrimitiveInTheWay(RayTracer::Ray PrimitiveToLight);
        Color processSingleLight(Math::Point3D PrimitiveHitPoint, ILight *light, std::string flags);
        Color processLights(Math::Point3D PrimitiveHitPoint, std::string flags = "");
        void processSinglePrimitive(std::vector<RayTracer::Ray> cameraRays, std::vector<Color> &pixelList, IPrimitives *primitive, std::vector<double> &minDistances, std::string flags = "");
        std::vector<Color> processFrame(std::string flags = "");
        void inRealTimeDisplay();
        std::vector<Color> displayOneFrame(std::string flags = "");
        ~Core();

    protected:

    private:
        std::string _flag; ///< Additional flag for additional information, if needed.
        
        std::vector<IPrimitives *> _primitives;
        Camera *_camera;
        IDisplay *_display;
        std::vector<ILight *> _lights;
};

#endif // !CORE_HPP
