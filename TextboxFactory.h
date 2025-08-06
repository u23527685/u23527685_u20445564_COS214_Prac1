#ifndef TEXTBOX_FACTORY_H
#define TEXTBOX_FACTORY_H

#include "Shape.h"
#include "ShapeFactory.h"
#include "Textbox.h"
class Shape;
class Textbox;

class TextboxFactory:public ShapeFactory{
    public:
        Shape* createShape();
        Shape* createShape(int length, int width, std::string &colour, int x, int y)override;
        Shape* copyshape(Textbox &other);
        void toString();
};

#endif