#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <libconfig.h++>

using namespace std;
using namespace libconfig;

int main(int argc, char **argv)
{
  (void)argc;
  (void)argv;

  Config cfg;

  try
  {
    cfg.readFile("example.cfg");
  }
  catch(const FileIOException &fioex)
  {
    std::cerr << "I/O error while reading file." << std::endl;
    return(EXIT_FAILURE);
  }
  catch(const ParseException &pex)
  {
    std::cerr << "Parse error at " << pex.getFile() << ":" << pex.getLine()
              << " - " << pex.getError() << std::endl;
    return(EXIT_FAILURE);
  }

  try
  {
    string name = cfg.lookup("name");
    cout << "Store name: " << name << endl << endl;
  }
  catch(const SettingNotFoundException &nfex)
  {
    cerr << "No 'name' setting in configuration file." << endl;
  }

  const Setting& root = cfg.getRoot();

  // Output a list of all camera in the inventory.
  try
  {
    const Setting &camera = root["inventory"]["camera"];
    int count = camera.getLength();

    cout << setw(30) << left << "width_resolution" << "  "
         << setw(30) << left << "height_resolution" << "  "
         << setw(30) << left << "color_r" << "   "
         << setw(30) << left << "color_g" << "   "
         << setw(30) << left << "color_b" << "   "
         << endl;

    for(int i = 0; i < count; ++i)
    {
      const Setting &book = camera[i];

      // Only output the record if all of the expected fields are present.
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
  }
  catch(const SettingNotFoundException &nfex)
  {
    // Ignore.
  }

  // Output a list of all books in the inventory.
  try
  {
    const Setting &primitive = root["inventory"]["primitive"];
    int count = primitive.getLength();

    cout << setw(30) << left << "forme" << "  "
         << setw(10) << left << "MEDIA" << "   "
         << endl;

    for(int i = 0; i < count; ++i)
    {
      const Setting &movie = primitive[i];

      // Only output the record if all of the expected fields are present.
      string forme, media;
      double price;
      int qty;

      if(!(movie.lookupValue("forme", forme)
           && movie.lookupValue("media", media)))
        continue;

      cout << setw(30) << left << forme << "  "
           << setw(10) << left << media << "  "
           << '$' << setw(6) << right << "  "
           << endl;
    }
    cout << endl;
  }
  catch(const SettingNotFoundException &nfex)
  {
    // Ignore.
  }

  return(EXIT_SUCCESS);
}

// eof