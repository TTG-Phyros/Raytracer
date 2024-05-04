/**
 * @file Loader.hpp
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

#ifndef _HPP
#define _HPP

#include <dirent.h>
#include <vector>
#include <iostream>
#include <dlfcn.h>

template<typename ClassContainer>
class Loader {
    public:

        Loader() : _loadedLib(nullptr), _path(pathLib()), _lib(0) {}

        Loader(const std::string& fn) : _loadedLib(dlopen(fn.c_str(), RTLD_LAZY)), _path(pathLib()) {
            _lib = currLib(fn);
        }

        ~Loader() {
            (_loadedLib != nullptr) ? dlclose(_loadedLib) : 0;
        }

        ClassContainer* currInst(const std::string& param) {
            ClassContainer* layer = nullptr;

            if (_loadedLib != nullptr) {
                typedef ClassContainer* (*create_t)();
                create_t create = reinterpret_cast<create_t>(dlsym(_loadedLib, param.c_str()));
                if (create != nullptr) {
                    layer = create();
                } else {
                    std::cerr << "Failed to find " << param << " in library\n";
                }
            } else {
                std::cerr << "Failed to load library\n" << dlerror() << std::endl;
            }
            return layer;
        }

        void swapLib(const char* fn) {
            if (_loadedLib != nullptr) {
                dlclose(_loadedLib);
            }

            _loadedLib = dlopen(fn, RTLD_LAZY);
        }

        std::vector<std::string> pathLib() {
            DIR *Directory;
            struct dirent *ent;
            std::vector<std::string> location;

            if ((Directory = opendir ("./plugins")) != NULL) {
                for (struct dirent* ent = readdir(Directory); ent != NULL; ent = readdir(Directory)) {
                    if (ent->d_name[0] == '.') {
                        continue;
                    } else {
                        std::string tmp = "./plugins/" + std::string(ent->d_name);
                        location.push_back(tmp);
                    }
                }
                closedir (Directory);
            } else {
                std::cerr << "Failed to open directory" << std::endl;
            }
            return location;
        }

        int currLib(std::string lib) {
            int i = 0;
            while (i < _path.size()) {
                if (_path[i] == lib) {
                    return i;
                }
                i++;
            }
            return 0;
        }

    public:
        void *_loadedLib; /**< Pointer to the loaded library. */

        std::vector<std::string> _path; /**< Vector containing paths to available libraries. */
        int _lib; /**< Index of the current library in the path vector. */
};

#endif // !COORDINATES_HPP
