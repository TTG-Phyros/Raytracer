/*
** EPITECH PROJECT, 2024
** BootStrap
** File description:
** Ray
*/

#ifndef RAY_HPP_
#define RAY_HPP_

#include "Point3D.hpp"
#include "Vector3D.hpp"

namespace RayTracer {
    class Ray {
        public:
            Ray(Math::Point3D origin = Math::Point3D(), Math::Vector3D direction = Math::Vector3D());
            ~Ray();
            Math::Point3D _origin;
            Math::Vector3D _direction;

        protected:
        private:
    };
}
std::ostream &operator<<(std::ostream &cout, RayTracer::Ray &ray);

#endif /* !RAY_HPP_ */
