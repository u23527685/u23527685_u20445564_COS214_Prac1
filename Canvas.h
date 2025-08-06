#ifndef CANVAS_H
#define CANVAS_H
using namespace std;
#include "Shape.h"
#include "Memento.h"
#include "Storage.h"

class Shape;
class Memento;
class Storage;

class Canvas{
    public:
        Canvas();
        ~Canvas();
        Memento* captureCurrent();
        void undoAction(Memento* prev);
        void exPortfile(){};
        void addShape(Shape* newShape);
        void print();
    private:
        Shape** shapes;
        int size;
        int capacity=0;
};

#endif