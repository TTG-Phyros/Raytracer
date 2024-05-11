/**
 * @file IDisplay.hpp
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

#ifndef IDISPLAY_HPP
#define IDISPLAY_HPP

#include "../../Utils/Color/Color.hpp"
#include "../../Utils/Ray/Ray.hpp"
#include "../../Plugins/Primitives/IPrimitives.hpp"
#include "../../Camera/Camera.hpp"

class IDisplay
{
    public:
        ~IDisplay() = default;

        virtual void setPixel(int x, int y, double red, double green, double blue) = 0;
        virtual void display() = 0;
        virtual void clear() = 0;
        virtual void close() = 0;
        virtual bool isOpen() = 0;
        virtual void move(Camera *camera) = 0;
        virtual void setResolution(int xSize, int ySize) = 0;
};

#endif // !IDISPLAY_HPP
