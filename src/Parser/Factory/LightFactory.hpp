/**
 * @file LightFactory.hpp
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

#ifndef LIGHT_FACTORY_HPP
#define LIGHT_FACTORY_HPP

#include "../../Utils/Loader/Loader.hpp"
#include "../../Plugins/Lights/ILights.hpp"
#include "../../Utils/Exception/Exception.hpp"

#include <memory>

class LightFactory
{
    public:
        ILight *createLights(const std::string &form, Loader <ILight> loader) const {
            if (form == "directional" || form == "Directional") {
                loader.swapLib("./plugins/raytracer_directional_light.so");
                return (createDirectionalLight(loader));
            // } else if (form == "cube" || form == "Cube") {
            //     loader.swapLib("./plugins/raytracer_cube.so");
            //     return (createCube(loader));
            // } else if (form == "plane" || form == "Plane") {
            //     loader.swapLib("./plugins/raytracer_plane.so");
            //     return (createPlane(loader));
            } else {
                throw Exception("LightFactory: invalid primitive form");
            }
        }

    protected:

    private:
        ILight *createDirectionalLight(Loader <ILight> loader) const noexcept { return loader.getNewInstance("loadDirectionalLight"); }
        // ILight *createCube(Loader <ILight> loader) const noexcept { return loader.getNewInstance("loadCube"); }
        // ILight *createPlane(Loader <ILight> loader) const noexcept { return loader.getNewInstance("loadPlane"); }
};

#endif /* !LIGHT_FACTORY_HPP */
