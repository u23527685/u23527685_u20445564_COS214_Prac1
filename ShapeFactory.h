#ifndef SHAPE_FACTORY_H
#define SHAPE_FACTORY_H

#include"Shape.h"
#include<iostream>
using namespace std;

class Shape;

class ShapeFactory{
    protected:
        virtual Shape* createShape(){cout<<"implement Creation in subclasses"<<endl;};
        virtual void toString(){{cout<<"implement toString in subclasses"<<endl;}};
        virtual ~ShapeFactory();
};

#endif