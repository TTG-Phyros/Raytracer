/**
 * @file DisplayFactory.hpp
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

#ifndef DISPLAY_FACTORY_HPP
#define DISPLAY_FACTORY_HPP

#include "../../Utils/Loader/Loader.hpp"
#include "../../Plugins/Display/IDisplay.hpp"
#include "../../Utils/Exception/Exception.hpp"

#include <memory>

class DisplayFactory
{
    public:
        IDisplay *createDisplay(const std::string &form, Loader <IDisplay> loader) const {
            if (form == "SFML" || form == "sfml") {
                loader.swapLib("./plugins/raytracer_sfml.so");
                return (createDirectionalLight(loader));
            } else {
                throw Exception("DisplayFactory: invalid primitive form");
            }
        }

    protected:

    private:
        IDisplay *createDirectionalLight(Loader <IDisplay> loader) const noexcept { return loader.getNewInstance("loadSFML"); }
};

#endif /* !DISPLAY_FACTORY_HPP */
