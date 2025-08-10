#ifndef CANVAS_H
#define CANVAS_H
using namespace std;
#include "Shape.h"
#include "Memento.h"
#include "Storage.h"

class Shape;
class Memento;
class Storage;
class ExportCanvas;
class PNGExporter;
class PDFExporter;

class Canvas{
    public:
        Canvas();
        ~Canvas();
        Memento* captureCurrent();
        void undoAction(Memento* prev);
        void exportfile();
        void addShape(Shape* newShape);
        void print();
        void createExporter(const string& type);
        void exportThis();
        Shape* getShape(int index);
    private:
        
        Shape** shapes;
        int size;
        int capacity=0;
        ExportCanvas* exportCanvas;
};

#endif