#include "fstream"

int main ()
{
    std::ofstream image;
    image.open("image.ppm");

    if (image.is_open()) {
        image << "p3" << std::endl;
        image << "les coordonnées de la window" << std::endl;
        image << "les rgb" << std::endl;

        for (int y = 0; y < 250; y++) {
            for (int x = 0; x < 250; x++) {
                image << x << " " << x << " " << x << std::endl;
            }
        }
    }
}
