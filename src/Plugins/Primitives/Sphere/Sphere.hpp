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
#include <vector>

#ifndef SPHERE_HPP
#define SPHERE_HPP

class Sphere : public IPrimitives
{
    public:
        Sphere();
        Sphere(Math::Point3D origin, double radius, Color color);
        ~Sphere();

        bool pointing(RayTracer::Ray &ray);
        bool hits(RayTracer::Ray &ray, double &distance) override;
        std::vector<double> hits(std::vector<RayTracer::Ray> rays, double &minDistance, double &maxDistance) override;

        // SETTER
        void setForm(std::string form) override;
        void setOrigin(Math::Point3D origin) override;
        void setColor(Color color) override;
        void setSize(std::vector<double> size) override;

        // GETTER
        std::string getForm() override;
        Math::Point3D getOrigin() override;
        Color getColor() override;
        std::vector<double> getSize() override;

    protected:

    private:
        std::string _form;
        Color _color;
        Math::Point3D _origin;
        double _radius;
};

#endif // !SPHERE_HPP
