#ifndef TEXTBOX_FACTORY_H
#define TEXTBOX_FACTORY_H

#include"Shape.h"
#include"ShapeFactory.h"

class Shape;

class TextboxFactory:public ShapeFactory{
    public:
        Shape* createShape();
        void toString();
};

#endif