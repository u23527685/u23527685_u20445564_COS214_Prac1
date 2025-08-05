#ifndef RECTANGLE_FACTORY_H
#define RECTANGLE_FACTORY_H

#include"Shape.h"
#include"ShapeFactory.h"
#include"Rectangle.h"
#include <sstream>

class Shape;
class Rectangle;

class RectangleFactory:public ShapeFactory{
    public:
        Shape* createShape();
        Shape* createShape(int length, int width, std::string &colour, int x, int y);
        Shape* copyshape(Rectangle &other);
        void toString();
};

#endif