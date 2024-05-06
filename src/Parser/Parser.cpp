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
        parserInfoCamera(root);
        parserInfoPrimitives(root);
        if (!_flag.empty())
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

void Parser::parserInfoCamera(const Setting& root)
{
    try {
        const Setting &camera = root["inventory"]["camera"];
        int count = camera.getLength();

        for(int i = 0; i < count; ++i) {
            const Setting &book = camera[i];

            string width_resolution, height_resolution, position_x, position_y, position_z,
            rotation_x, rotation_y, rotation_z, fov;

            if(!(book.lookupValue("width_resolution", width_resolution)
                && book.lookupValue("height_resolution", height_resolution)
                && book.lookupValue("position_x", position_x)
                && book.lookupValue("position_y", position_y)
                && book.lookupValue("position_z", position_z)
                && book.lookupValue("rotation_x", rotation_x)
                && book.lookupValue("rotation_y", rotation_y)
                && book.lookupValue("rotation_z", rotation_z)
                && book.lookupValue("fov", fov)))
                continue;

            _camerasInfo.push_back((std::make_tuple("width_resolution", width_resolution)));
            _camerasInfo.push_back((std::make_tuple("height_resolution", height_resolution)));
            _camerasInfo.push_back((std::make_tuple("position_x", position_x)));
            _camerasInfo.push_back((std::make_tuple("position_y", position_y)));
            _camerasInfo.push_back((std::make_tuple("position_z", position_z)));
            _camerasInfo.push_back((std::make_tuple("rotation_x", rotation_x)));
            _camerasInfo.push_back((std::make_tuple("rotation_y", rotation_y)));
            _camerasInfo.push_back((std::make_tuple("rotation_z", rotation_z)));
            _camerasInfo.push_back((std::make_tuple("fov", fov)));
        }
    } catch(const SettingNotFoundException &nfex) {
        // Ignorer
    }
}

void Parser::parserInfoPrimitives(const Setting& root)
{
    try {
        const Setting &primitive = root["inventory"]["primitive"];
        int count = primitive.getLength();

        for(int i = 0; i < count; ++i) {
            const Setting &movie = primitive[i];

            string forme, color_r, color_g, color_b;

            if(!(movie.lookupValue("forme", forme)
                && movie.lookupValue("color_r", color_r)
                && movie.lookupValue("color_g", color_g)
                && movie.lookupValue("color_b", color_b)))
                continue;

            _primitivesInfo.push_back(std::make_tuple("forme", forme));
            _primitivesInfo.push_back(std::make_tuple("color_r", color_r));
            _primitivesInfo.push_back(std::make_tuple("color_g", color_r));
            _primitivesInfo.push_back(std::make_tuple("color_b", color_r));
        }
    } catch(const SettingNotFoundException &nfex) {
        // Ignorer
    }
}

std::vector<std::pair<std::string, std::string>> Parser::GetInfo(const Parser& parser)
{
    std::vector<std::pair<std::string, std::string>> allInfo;

    // Récupérer les informations des caméras
    for (const auto& cameraInfo : parser._camerasInfo) {
        allInfo.emplace_back(std::get<0>(cameraInfo), std::get<1>(cameraInfo));
    }

    // Récupérer les informations des primitives
    for (const auto& primitiveInfo : parser._primitivesInfo) {
        allInfo.emplace_back(std::get<0>(primitiveInfo), std::get<1>(primitiveInfo));
    }

    return allInfo;
}

void Parser::printInfoFile() const
{
    // Affichage des informations sur les caméras
    std::cout << "Informations sur les caméras :" << std::endl;
    for (const auto& cameraInfo : _camerasInfo) {
        std::cout << std::get<0>(cameraInfo) << ": " << std::get<1>(cameraInfo) << std::endl;
    }

    // Affichage des informations sur les primitives
    std::cout << "\nInformations sur les primitives :" << std::endl;
    for (const auto& primitiveInfo : _primitivesInfo) {
        std::cout << std::get<0>(primitiveInfo) << ": " << std::get<1>(primitiveInfo) << std::endl;
    }
}

std::vector<std::tuple<std::string, std::string>> Parser::getCameraInfo()
{
    return _camerasInfo;
}

std::vector<std::tuple<std::string, std::string>> Parser::getPrimitivesInfo()
{
    return _primitivesInfo;
}
