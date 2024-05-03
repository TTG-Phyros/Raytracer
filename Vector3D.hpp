/*
** EPITECH PROJECT, 2024
** BootStrap
** File description:
** RayTracer
*/

#ifndef RAYTRACER_HPP_
#define RAYTRACER_HPP_

#include <string>
#include <iostream>

namespace Math {
    class Vector3D {
        public:
            Vector3D(double x = 0, double y = 0, double z = 0);
            ~Vector3D();
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
            double dot();

        protected:
        private:
    };
}
std::ostream &operator<<(std::ostream &cout, Math::Vector3D &vector);

#endif /* !RAYTRACER_HPP_ */
