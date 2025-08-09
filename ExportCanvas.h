#ifndef EXPORTCANVAS_H
#define EXPORTCANVAS_H
#include "Canvas.h"

using namespace std;
class ExportCanvas{
    private:
        Canvas* canvas;
        virtual void prepareCanvas() = 0;
        virtual void renderElements() = 0;
        virtual void saveToFile() =0;
    public:
        void exportToFile();
        ExportCanvas(Canvas* canvas) : canvas(canvas){}
        ExportCanvas();
        virtual ~ExportCanvas();   
        void printCanvas();
};

#endif