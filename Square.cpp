#include "Square.h"
#include <sstream>

// default object
Square::Square()
    : length(1), width(1), colour("black"), position_x(0), position_y(0) {}

// copy
Square::Square(int size, std::string &colour, int x, int y)
    : length(size), width(size), colour(colour), position_x(x), position_y(y) {}

Square::~Square() {}

Shape *Square::clone()
{
    return new Square(length, colour, position_x, position_y);
}

std::string Square::toString()
{
    std::ostringstream out;
    out << "Square (size=" << length
        << ", colour=" << colour
        << ", x=" << position_x
        << ", y=" << position_y << ")";
    return out.str();
}
void Square::moveSquare(int x, int y)
{
    position_x = x;
    position_y = y;
}

void Square::resizeSquare(int len, int w)
{
    length = len;
    width = w;
}

void Square::recolourSquare(std::string &col)
{
    colour = col;
}