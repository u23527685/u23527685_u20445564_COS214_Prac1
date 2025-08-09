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
    canvas = nullptr;
}
void ExportCanvas::printCanvas()
{
    if (!canvas) return;
    canvas->print();
}
void ExportCanvas::exportToFile()
{
    prepareCanvas();
    renderElements();
    saveToFile();
}



