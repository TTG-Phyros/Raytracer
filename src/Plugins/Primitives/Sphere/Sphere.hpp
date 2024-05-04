/**
 * @file Sphere.hpp
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

#ifndef SPHERE_HPP
#define SPHERE_HPP

class Sphere : public IPrimitives
{
    public:

        Sphere();
        Sphere(Coordinates origin, double radius, Color color);
        ~Sphere();

        bool hits(Coordinates vectorOrigin, Coordinates vectorDirection) override;

        // SETTER
        void setColor(Color color) override;
        void setOrigin(Coordinates origin) override;

        // GETTER
        std::string getForm() override;
        Coordinates getOrigin() override;
        Color getColor() override;
        double getRadius() override;

    protected:

    private:
        std::string _form;
        Color _color;
        Coordinates _origin;
        double _radius;
};

#endif // !SPHERE_HPP
