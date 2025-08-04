#ifndef MEMENTO_H
#define MEMENTO_H

using namespace std;

#include "Shape.h";
class Shape;
class Canvas;

class Memento{
    friend class Canvas;
    public:
        Memento();
        Memento(const Memento &other);
        Memento(Shape* elements,int size);
        bool isNULL();
    private:
        Shape* shapes;
        int size;
};



#endif