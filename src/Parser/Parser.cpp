/**
 * @file Parser.cpp
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

#include "Parser.hpp"

using namespace std;
using namespace libconfig;

Parser::Parser(const std::string &filepath, const std::string &flag)
    : _filePath(filepath), _flag(flag)
{
    if (!_flag.empty()) {
        std::cout << "--------------------------------" << std::endl;
        std::cout << "| Parser : Debug Informations. |" << std::endl;
        std::cout << "--------------------------------" << std::endl;
    }
    try
    {
        if (!_filePath.empty() && _filePath.length() <= 4 || _filePath.substr(_filePath.length() - 4, 4) != ".cfg") {
            throw Exception("Error: invalid file extension, see --help for more information");
        }
        Config cfg;
        if(!readFileConfig(cfg)) {
            throw Exception("Error: unable to read file");
        }
        const Setting &root = cfg.getRoot();
        getInfoCamera(root);
        getInfoPrimitives(root);
        printInfoFile();

    } catch(Exception &e) {
        std::cerr << e.what() << std::endl;
        exit(84);
    }
}

Parser::~Parser()
{
}

bool Parser::readFileConfig(Config& cfg)
{
    try {
        cfg.readFile(_filePath.c_str());
        return true;
    } catch(const FileIOException &fioex) {
        cerr << "Erreur d'E/S lors de la lecture du fichier." << endl;
        return false;
    } catch(const ParseException &pex) {
        cerr << "Erreur de parser " << pex.getFile() << ":" << pex.getLine()
            << " - " << pex.getError() << endl;
        return false;
    }
}

void Parser::getInfoCamera(const Setting& root)
{
    try {
        const Setting &camera = root["inventory"]["camera"];
        int count = camera.getLength();

        for(int i = 0; i < count; ++i) {
            const Setting &book = camera[i];

            string width_resolution, height_resolution, color_r, color_g, color_b;

            if(!(book.lookupValue("width_resolution", width_resolution)
                && book.lookupValue("height_resolution", height_resolution)
                && book.lookupValue("color_r", color_r)
                && book.lookupValue("color_g", color_g)
                && book.lookupValue("color_b", color_b)))
                continue;

            camerasInfo.push_back(std::make_tuple(width_resolution, height_resolution, color_r, color_g, color_b));
        }
    } catch(const SettingNotFoundException &nfex) {
        // Ignorer
    }
}

void Parser::getInfoPrimitives(const Setting& root)
{
    try {
        const Setting &primitive = root["inventory"]["primitive"];
        int count = primitive.getLength();

        for(int i = 0; i < count; ++i) {
            const Setting &movie = primitive[i];

            string forme, media;

            if(!(movie.lookupValue("forme", forme)
                && movie.lookupValue("media", media)))
                continue;

            primitivesInfo.push_back(std::make_tuple(forme, media));
        }
    } catch(const SettingNotFoundException &nfex) {
        // Ignorer
    }
}

void Parser::printInfoFile()
{
    std::cout << "cameras :" << std::endl;
    for (const auto& camera : camerasInfo) {
        std::cout << "Width Resolution: " << std::get<0>(camera) << std::endl;
        std::cout << "Height Resolution: " << std::get<1>(camera) << std::endl;
        std::cout << "Color R: " << std::get<2>(camera) << std::endl;
        std::cout << "Color G: " << std::get<3>(camera) << std::endl;
        std::cout << "Color B: " << std::get<4>(camera) << std::endl;
        std::cout << std::endl;
    }

    std::cout << "primitives :" << std::endl;
    for (const auto& primitive : primitivesInfo) {
        std::cout << "Forme: " << std::get<0>(primitive);
        std::cout << std::endl;
    }
}
