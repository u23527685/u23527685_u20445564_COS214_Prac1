#ifndef EXPORTCANVAS_H
#define EXPORTCANVAS_H
#include "Canvas.h"

using namespace std;
class ExportCanvas{
    private:
        Canvas* canvas;
    public:
        virtual void exportToFile() =0;
        virtual void prepareCanvas() = 0;
        virtual void renderElements() = 0;
        virtual void saveToFile() =0;
        ExportCanvas(Canvas* canvas) : canvas(canvas){}
        virtual ~ExportCanvas();   
        void printCanvas();
};

#endif