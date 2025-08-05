#include "Square.h"
#include <sstream>
using namespace std;

// default object
Square::Square():Shape(10,10,*(new string("black")),0,0){}

// copy

Square::Square(const Square &other){
    
}
Square::Square(int length, int width, std::string &colour, int x, int y)
    : Shape(length,width,colour,x,y) {}

Square::~Square() {}

Shape *Square::clone()
{
    return new Square(*this);
}

std::string Square::toString()
{
    /*std::ostringstream out;
    out << "Square (size=" << length
        << ", colour=" << colour
        << ", x=" << position_x
        << ", y=" << position_y << ")";
    return out.str();*/
}

