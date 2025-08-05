#include <string>
#include "Shape.h"

Shape::Shape() : length(0), width(0), colour("black"), position_x(0), position_y(0) {}

Shape::Shape(int length, int width, std::string &colour, int x, int y)
    : length(length), width(width), colour(colour), position_x(x), position_y(y) {}

Shape::~Shape() {}
