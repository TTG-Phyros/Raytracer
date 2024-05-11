/**
 * @file Plane.hpp
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

#include "../IPrimitives.hpp"
#include <vector>

#ifndef Plane_HPP
#define Plane_HPP

class Plane : public IPrimitives
{
    public:
        Plane();
        Plane(Math::Point3D origin, Color color);
        ~Plane();

        bool hits(RayTracer::Ray &ray, double &distance) override;

        // SETTER
        void setForm(std::string form) override;
        void setOrigin(Math::Point3D origin) override;
        void setColor(Color color) override;

        // GETTER
        std::string getForm() override;
        Math::Point3D getOrigin() override;
        Color getColor() override;

    protected:

    private:
        std::string _form;
        Color _color;
        Math::Point3D _origin;
};

#endif // !Plane_HPP
