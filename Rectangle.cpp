#include <string>
#include <iostream>
#include "Shape.h"
#include "Rectangle.h"
#include <sstream>

using namespace std;

Rectangle::Rectangle():Shape(10,5, *(new string("blue")),0,0){
}

Rectangle::Rectangle(const Rectangle &other):Shape(other){
}

Rectangle::Rectangle(int l, int w, std::string &colour, int x, int y):Shape(l,w,colour,x,y)
{
}

Rectangle::~Rectangle()
{
}

Shape *Rectangle::clone(){
    return new Rectangle(*this);
}

string Rectangle::toString()
{
    std::ostringstream out;
    out << "Rectangle (length=" << getLength()
        <<", width="<<getWidth()
        << ", colour=" << getColour()
        << ", x=" << getPosition_x()
        << ", y=" << getPosition_y() << ")";
    return out.str();
}

