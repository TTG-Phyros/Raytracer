/**
 * @file Core.cpp
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

#include "Core.hpp"
#include "Utils/Loader/Loader.hpp"
#include "Plugins/Primitives/IPrimitives.hpp"

Core::Core()
{
    Loader <IPrimitives> loader;

    loader.swapLib("./plugins/raytracer_sphere.so");

    loader.getNewInstance("loadSphere");
}

Core::~Core()
{
}
