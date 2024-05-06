/**
 * @file IPrimitives.hpp
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

#ifndef IPRIMITIVESphereS_HPP
#define IPRIMITIVES_HPP

#include "../../Utils/Coordinates/Coordinates.hpp"
#include "../../Utils/Color/Color.hpp"

class IPrimitives
{
    public:
        ~IPrimitives() = default;

        virtual bool hits(Coordinates vectorOrigin, Coordinates vectorDirection) = 0;

        virtual void setForm(std::string form) = 0;
        virtual void setOrigin(Coordinates origin) = 0;
        virtual void setColor(Color color) = 0;
        virtual void setRadius(double radius) = 0;

        virtual std::string getForm() = 0;
        virtual Coordinates getOrigin() = 0;
        virtual Color getColor() = 0;
        virtual double getRadius() = 0;
};

#endif // !IPRIMITIVES_HPP