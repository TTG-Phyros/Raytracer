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

            string width_resolution, height_resolution, pos_x, pos_y, pos_z,
            rotation_x, rotation_y, rotation_z, fov;

            if(!(book.lookupValue("width_resolution", width_resolution)
                && book.lookupValue("height_resolution", height_resolution)
                && book.lookupValue("pos_x", pos_x)
                && book.lookupValue("pos_y", pos_y)
                && book.lookupValue("pos_z", pos_z)
                && book.lookupValue("rotation_x", rotation_x)
                && book.lookupValue("rotation_y", rotation_y)
                && book.lookupValue("rotation_z", rotation_z)
                && book.lookupValue("fov", fov)))
                continue;

            Math::Point3D origin = Math::Point3D(atof(pos_x.c_str()), atof(pos_y.c_str()), atof(pos_z.c_str()));
            _camera = new Camera(origin, Math::Point3D(0, 0, ((atoi (fov.c_str())) / 45)), atoi(width_resolution.c_str()), atoi(height_resolution.c_str()));
            _display = new Sfml(atoi(width_resolution.c_str()), atoi(height_resolution.c_str()));
        }
    } catch(const SettingNotFoundException &nfex) {
        // Ignorer
    }
}

void Parser::ParseOnePrimitive(const Setting &primitive)
{
    IPrimitives *current_Form;

    Factory factory;
    Loader <IPrimitives> loader;
    std::vector<double> size_list;

    string forme, color_r, color_g, color_b, pos_x, pos_y, pos_z, size, current_size;

    if (!(primitive.lookupValue("forme", forme)
        && primitive.lookupValue("color_r", color_r)
        && primitive.lookupValue("color_g", color_g)
        && primitive.lookupValue("color_b", color_b)
        && primitive.lookupValue("pos_x", pos_x)
        && primitive.lookupValue("pos_y", pos_y)
        && primitive.lookupValue("pos_z", pos_z)
        && primitive.lookupValue("size", size)))
        return;

    current_Form = factory.createPrimitives(forme, loader);
    current_Form->setOrigin(Math::Point3D(atof(pos_x.c_str()), atof(pos_y.c_str()), atof(pos_z.c_str())));
    current_Form->setColor(Color(atoi(color_r.c_str()), atoi(color_g.c_str()), atoi(color_b.c_str()), 255));

    std::istringstream iss(size);
    while (std::getline(iss, current_size, '/'))
        size_list.push_back(atof(current_size.c_str()));
    current_Form->setSize(size_list);

    _primitives.push_back(current_Form);
}

void Parser::parserInfoPrimitives(const Setting& root)
{
    try {
        const Setting &primitive = root["inventory"]["primitive"];
        int count = primitive.getLength();

        for(int i = 0; i < count; ++i) {
            ParseOnePrimitive(primitive[i]);
        }
    } catch(const SettingNotFoundException &nfex) {
        // Ignorer
    }
}

void Parser::printInfoFile() const
{
    std::cout << "Informations sur les cameras :" << std::endl;
    std::cout << _camera->getXSize() << " / " << _camera->getYSize() << std::endl;

    std::cout << "\nInformations sur les primitives :" << std::endl;
    for (const auto& primitiveInfo : _primitives) {
        std::cout << primitiveInfo->getForm() << std::endl;
    }
}

Camera *Parser::getCamera()
{
    return _camera;
}

IDisplay *Parser::getDisplay()
{
    return _display;
}

std::vector<IPrimitives *> Parser::getPrimitives()
{
    return _primitives;
}

std::vector<std::tuple<std::string, std::string>> Parser::getLightInfo()
{
    return _lightInfo;
}
