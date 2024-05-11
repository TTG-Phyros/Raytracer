/**
 * @file ILights.hpp
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

#include "../../Utils/Color/Color.hpp"
#include "../../Utils/Ray/Ray.hpp"

#ifndef ILIGHTS_HPP
#define ILIGHTS_HPP

class ILight
{
    public:
        ~ILight() = default;

        // virtual bool hits(RayTracer::Ray &ray, double &distance) = 0;
        // virtual std::vector<double> hits(std::vector<RayTracer::Ray> rays, double &minDistance, double &maxDistance) = 0;

        // SETTER
        virtual void setType(std::string type) = 0;
        virtual void setOrigin(Math::Point3D origin) = 0;
        virtual void setDirection(Math::Vector3D direction) = 0;
        virtual void setColor(Color color) = 0;
        virtual void setStrengh(double strengh) = 0;

        // GETTER
        virtual std::string getType() = 0;
        virtual Math::Point3D getOrigin() = 0;
        virtual Math::Vector3D getDirection() = 0;
        virtual Color getColor() = 0;
        virtual double getStrengh() = 0;
};

#endif // !DIRECTIONAL_HPP