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

double getPercentageFromDistance(double minDistance, double maxDistance, double distance)
{
    if (distance >= maxDistance)
        return 1;
    // std::cout << "Percentage distance : 1 - ((" << distance << " - " << minDistance << ") / (" << maxDistance << " - " << minDistance << ")) = " << 1 - ((distance - minDistance) / (maxDistance - minDistance)) << std::endl;
    return 1 - ((distance - minDistance) / (maxDistance - minDistance));
}

void Core::processFrame()
{
    std::vector<RayTracer::Ray> cameraRays = _camera->generateCameraRays();
    double minDistance = 99999999;
    double maxDistance = -1;
    int x = 0;
    int y = 0;
    double offset = 0;
    for (int i = 0; _primitives[i]; i++) {
        std::vector<double> distance = _primitives[i]->hits(cameraRays, minDistance, maxDistance);
        for (int j = 0; j < distance.size(); j++) {
            if (distance[j] != -1) {
                offset = getPercentageFromDistance(minDistance, maxDistance, distance[j]);
                _display->setPixel(x, y, _primitives[i]->getColor().getRed() * offset, _primitives[i]->getColor().getGreen() * offset, _primitives[i]->getColor().getBlue() * offset);
            }
            x++;
            if (x == _camera->getXResolution()) {
                x = 0;
                y++;
            }
        }
    }
}

void Core::inRealTimeDisplay()
{
    while(1) {
        _display->clear();
        processFrame();
        _display->display();
    }
}

void Core::displayOneFrame()
{
    _display->clear();
    processFrame();
    _display->display();
}

Core::~Core()
{
}
