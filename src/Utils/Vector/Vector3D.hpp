/**
 * @file Sphere.cpp
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

#ifndef RAYTRACER_HPP_
#define RAYTRACER_HPP_

#include "../Point/Point3D.hpp"
#include <iostream>
#include <math.h>
#include <string>

namespace Math {
    class Vector3D {
        public:
            Vector3D(double x = 0, double y = 0, double z = 0);
            Vector3D(Math::Point3D origin, Math::Point3D end);
            ~Vector3D();
            void Normalize();
            Math::Point3D _origin;
            Math::Point3D _end;
            double _x;
            double _y;
            double _z;
            double getLength();
            Math::Vector3D operator+(Math::Vector3D &secondVector);
            void operator+=(Math::Vector3D &secondVector);
            Math::Vector3D operator-(Math::Vector3D &secondVector);
            void operator-=(Math::Vector3D &secondVector);
            Math::Vector3D operator*(Math::Vector3D &secondVector);
            void operator*=(Math::Vector3D &secondVector);
            Math::Vector3D operator/(Math::Vector3D &secondVector);
            void operator/=(Math::Vector3D &secondVector);
            Math::Vector3D operator*(double nb);
            void operator*=(double nb);
            Math::Vector3D operator/(double nb);
            void operator/=(double nb);
            double dot(Math::Vector3D otherVector);
            double dot(Math::Point3D otherPoint);
            double Dot(const Vector3D &otherVector) const {
                return _x * otherVector._x + _y * otherVector._y + _z * otherVector._z;
            }
        protected:
        private:
    };
}
std::ostream &operator<<(std::ostream &cout, Math::Vector3D &vector);

#endif /* !RAYTRACER_HPP_ */
