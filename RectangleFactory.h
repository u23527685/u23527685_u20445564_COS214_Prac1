#ifndef RECTANGLE_FACTORY_H
#define RECTANGLE_FACTORY_H

#include"Shape.h"
#include"ShapeFactory.h"

class Shape;

class RectangleFactory:public ShapeFactory{
    public:
        Shape* createShape();
        void toString();
};

#endif