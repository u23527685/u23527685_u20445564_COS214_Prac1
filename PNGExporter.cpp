#include "PNGExporter.h"
#include <iostream>
#include <fstream>
using namespace std;
//mock PNG file

void PNGExporter::saveToFile() {
    cout << "Saving canvas to PNG file..." << endl;
    string filename ="canvas_export.png";
    ofstream file(filename);
    if (file.is_open()) {
        // Writing the PNG metadata as text
        file << "PNG Export File\n";
        file << "Format: Portable Network Graphics\n";
        file << "Type: Raster Image\n";
        file << "Canvas Data:\n";
        file << "  Width: 800\n";
        file << "  Height: 600\n";
        file << "  Color Depth: 24-bit RGB\n";
        file << "  Compression: Lossless\n";
        file << "Exported Elements:\n";
        printCanvas();  //outputing the shapes to console
        file << "  [Shape data converted to pixel format - see console output]\n";
        file.close();
        cout << "PNG saved as: " << filename <<endl;
    } else {
        cerr << "Error: Could not create PNG file" << endl;
    }
}

void PNGExporter::exportToFile()
{
    cout << "Starting PNG export..." << endl;
    
    prepareCanvas();
    renderElements();
    saveToFile();
    
    cout << "PNG export completed!" << endl;
}

void PNGExporter::prepareCanvas()
{
    //canvas information and export environment
    cout <<"Preparing canvas for PNG Export...\n";
    cout << "Setting up raster graphics parameters:" << endl;
    cout << "  - Image dimensions: 800x600 pixels" << endl;
    cout << "  - Color mode: RGB (24-bit)" << endl;
    cout << "  - Background: White" << endl;
    cout << "  - Resolution: 300 DPI" << endl;
    cout << "  - Anti-aliasing: Enabled" << endl;
    cout << "  - Bitmap buffer initialized" << endl;
    cout << "Analyzing canvas content..." << endl;
    // int shapeCount = 0;
    cout << "  - Shapes ready for rasterization" << endl;
    cout << "Canvas prepared for raster graphics" << endl;
}

void PNGExporter::renderElements()
{
    cout << "Rendering elements to PNG bitmap..." << endl;
    cout << "Canvas shapes to be rasterized:" << endl;
    printCanvas();
    cout << "All elements rendered to bitmap" << endl;
}
