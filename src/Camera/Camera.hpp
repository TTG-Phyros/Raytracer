/**
 * @file Camera.hpp
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

#ifndef CAMERA_HPP_
#define CAMERA_HPP_

#include "../Utils/Point/Point3D.hpp"
#include "../Utils/Ray/Ray.hpp"

class Camera {
    public:
        Camera();
        Camera(Math::Point3D origin, Math::Point3D screenCenter, int xSize, int ySize);
        void setXSize(int size);
        void setYSize(int size);
        int getXSize();
        int getYSize();
        void setOrigin(Math::Point3D origin);
        void setScreenCenter(Math::Point3D screenCenter);
        Math::Point3D getOrigin();
        Math::Point3D getScreenCenter();
        RayTracer::Ray generateRay(int x, int y);
        ~Camera();

    protected:
    private:
        Math::Point3D _origin;
        Math::Point3D _screenCenter;
        int _xSize;
        int _ySize;
};

#endif /* !CAMERA_HPP_ */
