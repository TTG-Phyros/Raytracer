/**
 * @file Directional.hpp
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

#include "../ILights.hpp"

#ifndef DIRECTIONAL_HPP
#define DIRECTIONAL_HPP

class DirectionalLight : public ILight {
    public:
        DirectionalLight();
        DirectionalLight(Math::Point3D origin, Math::Vector3D direction, Color color, double strengh);
        ~DirectionalLight();

        // SETTER
        void setType(std::string type) override;
        void setOrigin(Math::Point3D origin) override;
        void setDirection(Math::Vector3D direction) override;
        void setColor(Color color) override;
        void setStrengh(double strengh) override;

        // GETTER
        std::string getType() override;
        Math::Point3D getOrigin() override;
        Math::Vector3D getDirection() override;
        Color getColor() override;
        double getStrengh() override;
    protected:
    private:
        std::string _type;
        Math::Point3D _origin;
        Math::Vector3D _direction;
        Color _color;
        double _strengh;
};

#endif // !DIRECTIONAL_HPP
