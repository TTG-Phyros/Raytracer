#include <iostream>
#include <iomanip>
#include <libconfig.h++>

using namespace std;
using namespace libconfig;

bool lireFichierConfig(Config& cfg)
{
    try {
        cfg.readFile("example.cfg");
        return true;
    } catch(const FileIOException &fioex) {
        cerr << "Erreur d'E/S lors de la lecture du fichier." << endl;
        return false;
    } catch(const ParseException &pex) {
        cerr << "Erreur de parse à " << pex.getFile() << ":" << pex.getLine()
              << " - " << pex.getError() << endl;
        return false;
    }
}

void afficherCameras(const Setting& root)
{
    try {
        const Setting &camera = root["inventory"]["camera"];
        int count = camera.getLength();

        cout << setw(30) << left << "width_resolution" << "  "
             << setw(30) << left << "height_resolution" << "  "
             << setw(30) << left << "color_r" << "   "
             << setw(30) << left << "color_g" << "   "
             << setw(30) << left << "color_b" << "   "
             << endl;

        for(int i = 0; i < count; ++i) {
            const Setting &book = camera[i];

            string width_resolution, height_resolution, color_r, color_g, color_b;

            if(!(book.lookupValue("width_resolution", width_resolution)
                 && book.lookupValue("height_resolution", height_resolution)
                 && book.lookupValue("color_r", color_r)
                 && book.lookupValue("color_g", color_g)
                 && book.lookupValue("color_b", color_b)))
                continue;

            cout << setw(30) << left << width_resolution << "  "
                 << setw(30) << left << height_resolution << "  "
                 << setw(30) << left << color_r << "  "
                 << setw(30) << left << color_g << "  "
                 << setw(30) << left << color_b << "  "
                 << '$' << setw(6) << right << "  "
                 << endl;
        }
        cout << endl;
    } catch(const SettingNotFoundException &nfex) {
        // Ignorer
    }
}

void afficherPrimitives(const Setting& root)
{
    try {
        const Setting &primitive = root["inventory"]["primitive"];
        int count = primitive.getLength();

        cout << setw(30) << left << "forme" << "  "
             << setw(10) << left << "MEDIA" << "   "
             << endl;

        for(int i = 0; i < count; ++i) {
            const Setting &movie = primitive[i];

            string forme, media;

            if(!(movie.lookupValue("forme", forme)
                 && movie.lookupValue("media", media)))
                continue;

            cout << setw(30) << left << forme << "  "
                 << setw(10) << left << media << "  "
                 << '$' << setw(6) << right << "  "
                 << endl;
        }
        cout << endl;
    } catch(const SettingNotFoundException &nfex) {
        // Ignorer
    }
}

int main()
{
    Config cfg;
    if(!lireFichierConfig(cfg)) {
        return EXIT_FAILURE;
    }

    const Setting& root = cfg.getRoot();
    afficherCameras(root);
    afficherPrimitives(root);

    return EXIT_SUCCESS;
}
