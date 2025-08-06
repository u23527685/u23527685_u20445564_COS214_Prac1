#ifndef SQUARE_FACTORY_H
#define SQUARE_FACTORY_H

#include"Shape.h"
#include"ShapeFactory.h"
#include"Square.h"
#include <sstream>

class Shape;
class Square;

class SquareFactory:public ShapeFactory{
    public:
        Shape* createShape();
        Shape* createShape(int length, int width, std::string &colour, int x, int y);
        Shape* copyshape(Square &other);
        void toString();
        
};

#endif