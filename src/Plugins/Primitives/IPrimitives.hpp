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

#ifndef IPRIMITIVES_HPP
#define IPRIMITIVES_HPP

#include "../../Utils/Color/Color.hpp"
#include "../../Utils/Ray/Ray.hpp"
#include <vector>

class IPrimitives
{
    public:
        ~IPrimitives() = default;

        virtual bool hits(RayTracer::Ray &ray, double &distance) = 0;
        virtual std::vector<double> hits(std::vector<RayTracer::Ray> rays, double &minDistance, double &maxDistance) = 0;

        // SETTER
        virtual void setForm(std::string form) = 0;
        virtual void setOrigin(Math::Point3D origin) = 0;
        virtual void setColor(Color color) = 0;
        virtual void setSize(std::vector<double> size) = 0;

        // GETTER
        virtual std::string getForm() = 0;
        virtual Math::Point3D getOrigin() = 0;
        virtual Color getColor() = 0;
        virtual std::vector<double> getSize() = 0;
};

#endif // !IPRIMITIVES_HPP
