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
        Camera(Math::Point3D origin, Math::Point3D distance, double resWidth, double resHeight);
        void setXSize(double size);
        void setYSize(double size);
        void setXResolution(double resolution);
        void setYResolution(double resolution);
        double getXSize();
        double getYSize();
        double getXResolution();
        double getYResolution();
        void setOrigin(Math::Point3D origin);
        void setScreenDistance(Math::Point3D distance);
        Math::Point3D getOrigin();
        Math::Point3D getScreenDistance();
        Math::Point3D getScreenCenter();
        ~Camera();

    protected:
    private:
        Math::Point3D _origin;
        Math::Point3D _distance;
        Math::Point3D _screenCenter;
        double _xSize;
        double _ySize;
        double _xResolution;
        double _yResolution;
};

#endif /* !CAMERA_HPP_ */
