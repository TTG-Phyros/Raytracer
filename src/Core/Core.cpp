/**
 * @file Core.cpp
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

#include "Core.hpp"

Core::Core(Parser parser, std::string flag)
{
    _primitives = parser.getPrimitives();
    _camera = parser.getCamera();
    _display = parser.getDisplay();
    _lights = parser.getLights();
}

double getPercentageFromDistance(double minDistance, double maxDistance, double distance, std::string flags)
{
    if (distance >= maxDistance)
        return 1;
    if (flags == "--debug")
        std::cout << "Percentage distance : 1 - ((" << distance << " - " << minDistance << ") / (" << maxDistance << " - " << minDistance << ")) = " << 1 - ((distance - minDistance) / (maxDistance - minDistance)) << std::endl;
    return 1 - ((distance - minDistance) / (maxDistance - minDistance));
}

bool checkIfDirectionIsExactInverse(Math::Vector3D direction1, Math::Vector3D direction2)
{
    if (direction1._x == -(direction2._x)
        && direction1._x == -(direction2._x)
        && direction1._x == -(direction2._x))
        return true;
    return false;
}

bool Core::checkIfPrimitiveInTheWay(RayTracer::Ray primitiveToLight)
{
    for (int i = 0; i < _primitives.size(); i++) {
        double distance;
        if (_primitives[i]->hits(primitiveToLight, distance)) {
            return false;
        }
    }
    return true;
}

Color Core::processSingleLight(Math::Point3D PrimitiveHitPoint, ILight *light, std::string flags)
{
    RayTracer::Ray primitiveToLight = RayTracer::Ray(PrimitiveHitPoint, Math::Vector3D(PrimitiveHitPoint, light->getOrigin()));
    bool directLight = checkIfPrimitiveInTheWay(primitiveToLight);
    Color luminosity;

    if (directLight) {
        double angle = 0;
        double illumination = 0;
        if (!checkIfDirectionIsExactInverse(primitiveToLight._direction, light->getDirection())) {
            double dotProduct = (primitiveToLight._direction._x * light->getDirection()._x) + (primitiveToLight._direction._y * light->getDirection()._y) + (primitiveToLight._direction._z * light->getDirection()._z);
            double primitiveToLightMagnitude = primitiveToLight._direction.getLength();
            double lightMagnitude = light->getDirection().getLength();
            double angle = acos(dotProduct / (primitiveToLightMagnitude * lightMagnitude)) * 180 / M_PI;
            if (flags == "--debug") {
                std::cout << "Light direction : " << std::endl;
                Math::Vector3D temp = light->getDirection();
                std::cout << temp << std::endl;
                std::cout << "Primitive Ray To Light direction : " << std::endl;
                std::cout << primitiveToLight._direction << std::endl;
                std::cout << "Dot Product : " << dotProduct << std::endl;
                std::cout << "primitiveToLightMagnitude : " << primitiveToLightMagnitude << std::endl;
                std::cout << "lightMagnitude : " << lightMagnitude << std::endl;
                std::cout << "Angle of Lighting : " << angle << std::endl;
            }
            if (angle > 180 && angle <= 270) {
                illumination = ((angle - 180) / 90);
            } else if (angle <= 180 && angle >= 90) {
                illumination = ((angle - 90) / 90);
            }
        } else {
            illumination = 100;
        }
        if (flags == "--debug")
            std::cout << "Percentage of illumination : " << illumination << std::endl;
        luminosity.setRed(luminosity.getRed() + (light->getStrengh() * illumination));
        luminosity.setGreen(luminosity.getGreen() + (light->getStrengh() * illumination));
        luminosity.setBlue(luminosity.getBlue() + (light->getStrengh() * illumination));
    }
    return luminosity;
}

Color Core::processLights(Math::Point3D PrimitiveHitPoint, std::string flags)
{
    Color finalColor;
    for (int i = 0; i < _lights.size(); i++)
        finalColor += processSingleLight(PrimitiveHitPoint, _lights[i], flags);
    return finalColor;
}

void Core::processSinglePrimitive(std::vector<RayTracer::Ray> cameraRays, std::vector<Color> &pixelList, IPrimitives *primitive, std::vector<double> &minDistances, std::string flags)
{
    int x = 0;
    int y = 0;
    double offset = 0;
    double minDistance;
    double maxDistance;
    std::vector<double> distance = primitive->hits(cameraRays, minDistance, maxDistance);
    if (flags == "--debug") {
        std::cout << "Min distance : " << minDistance << " | Max distance : " << maxDistance << std::endl;
        std::cout << "Number of Rays generated : " << cameraRays.size() << std::endl;
    }
    for (int i = 0; i < cameraRays.size(); i++) {
        if (distance[i] != -1) {
            offset = getPercentageFromDistance(minDistance, maxDistance, distance[i], flags);
            Color currentColor = Color(primitive->getColor().getRed() * offset, primitive->getColor().getGreen() * offset, primitive->getColor().getBlue() * offset, 255);
            Math::Vector3D direction = (cameraRays[i]._direction * distance[i]);
            Math::Point3D pointOfHit = (cameraRays[i]._origin + direction);
            Color addedLight = processLights(pointOfHit, flags);
            currentColor += addedLight;
            if (flags == "--debug")
                std::cout << "Final pixel color : \n\tr = " << currentColor.getRed() << "\n\tg = " << currentColor.getGreen() << "\n\tb = " << currentColor.getBlue() << std::endl;
            if (distance[i] < minDistances[i]) {
                _display->setPixel(x, y, currentColor.getRed(), currentColor.getGreen(), currentColor.getBlue());
                pixelList[i] = currentColor;
                minDistances[i] = distance[i];
            }
        }
        x++;
        if (x == _camera->getXResolution()) {
            x = 0;
            y++;
        }
    }
}

std::vector<Color> Core::processFrame(std::string flags)
{
    std::vector<RayTracer::Ray> cameraRays = _camera->generateCameraRays();
    std::vector<Color> pixelList(cameraRays.size(), Color());
    std::vector<double> minDistances(cameraRays.size(), 99999);
    for (int i = 0; i < _primitives.size(); i++)
        processSinglePrimitive(cameraRays, pixelList, _primitives[i], minDistances, flags);
    return pixelList;
}

void Core::inRealTimeDisplay()
{
    while(_display->isOpen()) {
        _display->clear();
        _display->move(_camera);
        processFrame();
        _display->display();
    }
}

std::vector<Color> Core::displayOneFrame(std::string flags)
{
    if (flags == "--debug") {
        std::cout << "--------------------------------" << std::endl;
        std::cout << "|   Core : Display One Frame.  |" << std::endl;
        std::cout << "--------------------------------" << std::endl;
    }
    _display->close();
    return processFrame(flags);
}

Core::~Core()
{
}
