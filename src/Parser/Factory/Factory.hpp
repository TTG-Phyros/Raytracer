/**
 * @file Factory.hpp
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

#ifndef FACTORY_HPP
#define FACTORY_HPP

#include "../../Utils/Loader/Loader.hpp"
#include "../../Plugins/Primitives/IPrimitives.hpp"
#include "../../Utils/Exception/Exception.hpp"

#include <memory>

class Factory
{
    public:
        IPrimitives *createPrimitives(const std::string &form, Loader <IPrimitives> loader) const {
            if (form == "sphere" || form == "Sphere") {
                loader.swapLib("./plugins/raytracer_sphere.so");
                return (createSphere(loader));
            } else if (form == "cube" || form == "Cube") {
                loader.swapLib("./plugins/raytracer_cube.so");
                return (createCube(loader));
            } else if (form == "plane" || form == "Plane") {
                loader.swapLib("./plugins/raytracer_plane.so");
                return (createPlane(loader));
            } else {
                throw Exception("Factory: invalid primitive form");
            }
        }

    protected:

    private:
        IPrimitives *createSphere(Loader <IPrimitives> loader) const noexcept { return loader.getNewInstance("loadSphere"); }
        IPrimitives *createCube(Loader <IPrimitives> loader) const noexcept { return loader.getNewInstance("loadCube"); }
        IPrimitives *createPlane(Loader <IPrimitives> loader) const noexcept { return loader.getNewInstance("loadPlane"); }
};

#endif /* !FACTORY_HPP */
