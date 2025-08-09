#ifndef MEMENTO_H
#define MEMENTO_H

using namespace std;

#include "Shape.h"
class Shape;
class Canvas;

class Memento{
    friend class Canvas;
    public:
        Memento();
        Memento(const Memento &other);
        Memento(Shape** elements,int cap);
        bool isNULL();
        ~Memento();
        Shape** getShapes();
    private:
        Shape** shapes;
        int capacity;
};



#endif