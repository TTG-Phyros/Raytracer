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
}

// void Core::processFrame()
// {
//     // parser.getPrimitives();
//     for (int x = 0; x < _camera->getXSize(); x++) {
//         for (int y = 0; y < _camera->getYSize(); y++) {
//             // double red = (static_cast<double>(x) / static_cast<double>(_camera->getXSize())) * 255;
//             // double green = (static_cast<double>(y) / static_cast<double>(_camera->getYSize())) * 255;
//             // std::cout << "Pixel at " << x << " : " << y << "has the color --> " << red << " / " << green << " / 0" << std::endl;
//             // _display->setPixel(x, y, red, green, 0);
//             RayTracer::Ray ray = _camera->generateRay(x, y);
//             for (int i = 0; _primitives[i]; i++) {
//                 if (_primitives[i]->hits(ray)) {
//                     _display->setPixel(x, y, 255, 0, 0);
//                 }
//             }
//         }
//     }
// }

// void Core::processFrame()
// {
//     // Calculate the direction from the _camera origin to the screen center
//     Math::Vector3D screenDirection = Math::Vector3D(_camera->getOrigin(), _camera->getScreenCenter());

//     // Normalize the screen direction vector
//     float length = sqrt(screenDirection._x * screenDirection._x + screenDirection._y * screenDirection._y + screenDirection._z * screenDirection._z);
//     screenDirection._x /= length;
//     screenDirection._y /= length;
//     screenDirection._z /= length;

//     // Calculate the right and up vectors based on the screen direction
//     Math::Point3D right = Math::Point3D(screenDirection._y, -screenDirection._x, 0); // Cross product with (0, 0, 1)
//     Math::Point3D up = Math::Point3D(right._y * screenDirection._z - right._z * screenDirection._y, right._z * screenDirection._x - right._x * screenDirection._z, right._x * screenDirection._y - right._y * screenDirection._x);

//     // Calculate the top left corner of the screen
//     Math::Point3D topLeft = Math::Point3D(_camera->getScreenCenter()._x - (_camera->getXSize() / 2), _camera->getScreenCenter()._y + (_camera->getYSize() / 2), _camera->getScreenCenter()._z);

//     // Generate rays for each pixel
//     for (int y = 0; y < _camera->getYSize(); ++y) {
//         for (int x = 0; x < _camera->getXSize(); ++x) {
//             // Calculate the position of the current pixel
//             Math::Point3D pixelPosition = Math::Point3D(topLeft._x + (x + 0.5) * 1, topLeft._y - (y + 0.5) * 1, topLeft._z);

//             // Calculate the direction from the _camera origin to the current pixel
//             Math::Vector3D direction = Math::Vector3D(_camera->getOrigin(), pixelPosition);

//             // Normalize the direction vector
//             length = sqrt(direction._x * direction._x + direction._y * direction._y + direction._z * direction._z);
//             direction._x /= length;
//             direction._y /= length;
//             direction._z /= length;

//             // Create a ray from the _camera origin to the current pixel
//             RayTracer::Ray ray = RayTracer::Ray(_camera->getOrigin(), direction);
//             for (int i = 0; _primitives[i]; i++) {
//                 if (_primitives[i]->hits(ray)) {
//                     _display->setPixel(x, y, 255, 0, 0);
//                 }
//             }
//         }
//     }
// }

double getPercentageFromDistance(double minDistance, double maxDistance, double distance, std::string flags)
{
    if (distance >= maxDistance)
        return 1;
    if (flags == "--debug")
        std::cout << "Percentage distance : 1 - ((" << distance << " - " << minDistance << ") / (" << maxDistance << " - " << minDistance << ")) = " << 1 - ((distance - minDistance) / (maxDistance - minDistance)) << std::endl;
    return 1 - ((distance - minDistance) / (maxDistance - minDistance));
}

void Core::processSinglePrimitive(std::vector<RayTracer::Ray> cameraRays, std::vector<Color> &pixelList, IPrimitives *primitive, std::string flags)
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
            _display->setPixel(x, y, currentColor.getRed(), currentColor.getGreen(), currentColor.getBlue());
            pixelList[i] = currentColor;
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
    for (int i = 0; _primitives[i]; i++)
        processSinglePrimitive(cameraRays, pixelList, _primitives[i], flags);
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
