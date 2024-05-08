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

void Core::processFrame()
{
    // Calculate the direction from the _camera origin to the screen center
    Math::Vector3D screenDirection = Math::Vector3D(_camera->getScreenCenter()._x - _camera->getOrigin()._x, _camera->getScreenCenter()._y - _camera->getOrigin()._y, _camera->getScreenCenter()._z - _camera->getOrigin()._z);

    // Normalize the screen direction vector
    float length = sqrt(screenDirection._x * screenDirection._x + screenDirection._y * screenDirection._y + screenDirection._z * screenDirection._z);
    screenDirection._x /= length;
    screenDirection._y /= length;
    screenDirection._z /= length;

    // Calculate the right and up vectors based on the screen direction
    Math::Vector3D right = Math::Vector3D(screenDirection._y, -screenDirection._x, 0); // Cross product with (0, 0, 1)
    Math::Vector3D up = Math::Vector3D(right._y * screenDirection._z - right._z * screenDirection._y, right._z * screenDirection._x - right._x * screenDirection._z, right._x * screenDirection._y - right._y * screenDirection._x);

    // Calculate the top left corner of the screen
    Math::Vector3D topLeft = Math::Vector3D(_camera->getScreenCenter()._x - (_camera->getXSize() / 2), _camera->getScreenCenter()._y + (_camera->getYSize() / 2), _camera->getScreenCenter()._z);

    // Generate rays for each pixel
    for (int y = 0; y < _camera->getYSize(); ++y) {
        for (int x = 0; x < _camera->getXSize(); ++x) {
            // Calculate the position of the current pixel
            Math::Vector3D pixelPosition = Math::Vector3D(topLeft._x + (x + 0.5) * 1, topLeft._y - (y + 0.5) * 1, topLeft._z);

            // Calculate the direction from the _camera origin to the current pixel
            Math::Vector3D direction = Math::Vector3D(pixelPosition._x - _camera->getOrigin()._x, pixelPosition._y - _camera->getOrigin()._y, pixelPosition._z - _camera->getOrigin()._z);

            // Normalize the direction vector
            length = sqrt(direction._x * direction._x + direction._y * direction._y + direction._z * direction._z);
            direction._x /= length;
            direction._y /= length;
            direction._z /= length;

            // Create a ray from the _camera origin to the current pixel
            RayTracer::Ray ray = RayTracer::Ray(_camera->getOrigin(), direction);
            for (int i = 0; _primitives[i]; i++) {
                if (_primitives[i]->hits(ray)) {
                    _display->setPixel(x, y, 255, 0, 0);
                }
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
