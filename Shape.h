#ifndef SHAPE_H
#define SHAPE_H
#include "Shape.h"
#include <string>

class Shape
{
private:
    int length;
    int width;
    std::string colour;
    int position_x;
    int position_y;

public:
    Shape();
    Shape(int length, int width, std::string &colour, int x, int y);
    ~Shape();
    virtual Shape *clone() = 0;
    virtual std::string toString() = 0;
};

#endif