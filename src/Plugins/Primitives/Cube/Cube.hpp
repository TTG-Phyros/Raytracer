/**
 * @file Cube.hpp
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

#ifndef CUBE_HPP
#define CUBE_HPP

class Cube : public IPrimitives
{
    public:
        Cube();
        Cube(Math::Point3D origin, double side, Color color);
        ~Cube();

        bool hits(RayTracer::Ray &ray) override;

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
        double _side;
};

#endif // !CUBE_HPP
