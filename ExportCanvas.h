#ifndef EXPORTCANVAS_H
#define EXPORTCANVAS_H
#include "Canvas.h"

using namespace std;
class ExportCanvas{
    private:
        Canvas* canvas;
        void prepareCanvas();
        void renderElements();
        virtual void saveToFile();
    public:
        void exportToFile();
        ExportCanvas(Canvas* canvas);
        ~ExportCanvas();   
};

#endif