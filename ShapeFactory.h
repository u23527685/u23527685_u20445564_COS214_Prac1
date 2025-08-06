#ifndef SHAPE_FACTORY_H
#define SHAPE_FACTORY_H

#include"Shape.h"
#include<iostream>
using namespace std;

class Shape;

class ShapeFactory{
    protected:
        virtual Shape* createShape()=0;
        virtual Shape* createShape(int length, int width, std::string &colour, int x, int y)=0;
        virtual Shape* copyshape(Shape &other){return this->copyshape(other);};
        virtual void toString(){};
    public:
        virtual ~ShapeFactory();
        Shape* work(){
            return createShape();
        }
};

#endif