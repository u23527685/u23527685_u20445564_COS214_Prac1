#ifndef SQUARE_FACTORY_H
#define SQUARE_FACTORY_H

#include"Shape.h"
#include"ShapeFactory.h"

class Shape;

class SquareFactory:public ShapeFactory{
    public:
        Shape* createShape();
        void toString();
};

#endif