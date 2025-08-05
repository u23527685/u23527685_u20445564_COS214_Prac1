#include <string>
#include <iostream>
#include "Shape.h"
#include "Rectangle.h"

using namespace std;

Rectangle::Rectangle():Shape(10,5, *(new string("blue")),0,0){
}

Rectangle::Rectangle(const Rectangle &other){

}

Rectangle::Rectangle(int l, int w, std::string &colour, int x, int y)
{
}

Rectangle::~Rectangle()
{
}

Shape *Rectangle::clone(){
    return new Rectangle(*this);
}
