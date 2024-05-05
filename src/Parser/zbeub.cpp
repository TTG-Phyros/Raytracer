#include <iostream>
#include <iomanip>
#include <libconfig.h++>
#include <vector>
#include <tuple>

using namespace std;
using namespace libconfig;


class Configuration {
public:
    bool lireFichierConfig(Config& cfg);
    void afficherCameras(const Setting& root);
    void afficherPrimitives(const Setting& root);
    void afficherContenuVecteurs() const;

private:
    std::vector<std::tuple<std::string, std::string, std::string, std::string, std::string>> camerasInfo;
    std::vector<std::tuple<std::string, std::string>> primitivesInfo;
};


bool Configuration::lireFichierConfig(Config& cfg)
{
    try {
        cfg.readFile("example.cfg");
        return true;
    } catch(const FileIOException &fioex) {
        cerr << "Erreur d'E/S lors de la lecture du fichier." << endl;
        return false;
    } catch(const ParseException &pex) {
        cerr << "Erreur de parse Ã  " << pex.getFile() << ":" << pex.getLine()
            << " - " << pex.getError() << endl;
        return false;
    }
}

void Configuration::afficherCameras(const Setting& root)
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

void Configuration::afficherPrimitives(const Setting& root)
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

void Configuration::afficherContenuVecteurs() const
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

int main()
{
    Config cfg;
    Configuration config;

    if(!config.lireFichierConfig(cfg)) {
        return EXIT_FAILURE;
    }

    const Setting& root = cfg.getRoot();
    config.afficherCameras(root);
    config.afficherPrimitives(root);

    config.afficherContenuVecteurs();

    return EXIT_SUCCESS;
}
