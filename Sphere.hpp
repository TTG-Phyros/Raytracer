/*
** EPITECH PROJECT, 2024
** BootStrap
** File description:
** Sphere
*/

#ifndef SPHERE_HPP_
#define SPHERE_HPP_

#include "Point3D.hpp"
#include "Ray.hpp"

namespace RayTracer {
    class Sphere {
        public:
            Sphere(Math::Point3D origin = Math::Point3D(), double radius = 0);
            ~Sphere();
            Math::Point3D _origin;
            double _radius;
            bool hits(RayTracer::Ray &ray);

        protected:
        private:
    };
}
std::ostream &operator<<(std::ostream &cout, RayTracer::Sphere &sphere);

#endif /* !SPHERE_HPP_ */
