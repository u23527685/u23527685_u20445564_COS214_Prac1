#ifndef SQUARE_H
#define SQUARE_H

#include "Shape.h"
#include <string>

class Square : public Shape
{
private:
    int length;
    int width;
    std::string colour;
    int position_x;
    int position_y;

public:
    Square();
    Square(int size, std::string &colour, int x, int y);
    ~Square();
    void moveSquare();

    Shape *clone();
    std::string toString();
};

#endif
