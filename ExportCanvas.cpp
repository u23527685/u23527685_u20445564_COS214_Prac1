#include "ExportCanvas.h"

void ExportCanvas::prepareCanvas()
{
}

void ExportCanvas::renderElements()
{
}

void ExportCanvas::saveToFile()
{
}

ExportCanvas::~ExportCanvas()
{
    delete canvas;
}
void ExportCanvas::printCanvas()
{
    if (!canvas) return;
    canvas->print();
}
void ExportCanvas::exportToFile()
{
    // prepareCanvas();
    // renderElements();
    // saveToFile();
}



