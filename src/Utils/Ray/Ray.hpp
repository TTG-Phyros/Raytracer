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

#ifndef RAY_HPP_
#define RAY_HPP_

#include "../Points/Point3D.hpp"
#include "../Vector/Vector3D.hpp"

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
