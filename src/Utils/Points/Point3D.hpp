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

#ifndef POINT3D_HPP_
#define POINT3D_HPP_

#include "../Vectors/Vector3D.hpp"

namespace Math {
    class Point3D {
        public:
            Point3D(double x = 0, double y = 0, double z = 0);
            ~Point3D();
            double _x;
            double _y;
            double _z;
            Math::Point3D operator+(Math::Vector3D &secondVector);
        protected:
        private:
    };
}
std::ostream &operator<<(std::ostream &cout, Math::Point3D &point);

#endif /* !POINT3D_HPP_ */
