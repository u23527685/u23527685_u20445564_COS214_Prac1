#ifndef CANVAS_H
#define CANVAS_H
using namespace std;
#include "Shape.h"
#include "Memento.h"
#include "Storage.h"
#include "ShapeFactory.h"

class Shape;
class Memento;
class Storage;
class ExportCanvas;
class PNGExporter;
class PDFExporter;
class ShapeFactory;

class Canvas{
    public:
        Canvas();
        ~Canvas();
        Memento* captureCurrent();
        void undoAction(Memento* prev);
        void print();
        void createShape(ShapeFactory* factory);
        void createShape(ShapeFactory* factory,const Shape &other);
        void createShape(ShapeFactory* factory,int l, int w, string &colour, int x, int y);
        void createExporter(const string& type);
        void exportThis();
        Shape* getShape(int index);
    private:
        
        Shape** shapes;
        int size;
        int capacity=0;
        ExportCanvas* exportCanvas;
        void addShape(Shape* newShape);
};

#endif