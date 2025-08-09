#include "ExportCanvas.h"


ExportCanvas::~ExportCanvas()
{
<<<<<<< HEAD
    canvas = nullptr;
=======
    canvas=nullptr;
>>>>>>> 47b843a (exportcanvas segfault 1 fix)
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
<<<<<<< HEAD
=======
}

ExportCanvas::ExportCanvas(){
    canvas=nullptr;
>>>>>>> 47b843a (exportcanvas segfault 1 fix)
}



