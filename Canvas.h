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
        void operation();
    private:
        Shape* shapes;
        int size;
};

#endif