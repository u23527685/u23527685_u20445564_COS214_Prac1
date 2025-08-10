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
        Shape* createShape()override;
        Shape* createShape(int length, int width, std::string &colour, int x, int y)override;
        Shape* copyshape(const Shape &other);
        void toString();
};

#endif