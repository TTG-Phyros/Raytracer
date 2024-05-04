/**
 * @file main.cpp
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

#include <iostream>
#include <algorithm>
#include <iterator>
#include <sstream>
#include <fstream>
#include <vector>
#include <iostream>
#include <utility>
#include <map>
#include <stdexcept>
#include <dlfcn.h>

#include "Loader/Loader.hpp"
#include "../Plugins/Primitives/IPrimitives.hpp"

int main(int ac, char **av)
{
    try {
        if (ac == 2) {
            Loader <IPrimitives> loader;

            loader.swapLib(av[1]);

            return 0;
        } else {
            throw std::invalid_argument("Error: invalid arguments value");
        }
    } catch(const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 84;
    }
}
