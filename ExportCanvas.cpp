#include "ExportCanvas.h"


ExportCanvas::~ExportCanvas()
{
    canvas=nullptr;
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



