#include <string>
#include "Shape.h"

Shape::Shape() : length(0), width(0), colour("black"), position_x(0), position_y(0) {}

Shape::Shape(int length, int width, std::string &colour, int x, int y)
    : length(length), width(width), colour(colour), position_x(x), position_y(y) {}

Shape::Shape(const Shape &other)
{
    this->length = other.length;
    this->width = other.width;
    this->colour = other.colour;
    this->position_x = other.position_x;
    this->position_y = other.position_y;
}

Shape::~Shape() {}

int Shape::getLength() const
{
    return this->length;
}

int Shape::getWidth() const
{
    return this->width;
}

std::string Shape::getColour() const
{
    return this->colour;
}

int Shape::getPosition_x() const
{
    return this->position_x;
}

int Shape::getPosition_y() const
{
    return this->position_y;
}

void Shape::setLength(int length)
{
    this->length = length;

}

void Shape::setWidth(int width)
{
    this->width = width;
}

void Shape::setColour(const std::string &colour)
{
    this->colour = colour;
}

void Shape::setPosition_x(int x)
{
    position_x = x;
}

void Shape::setPosition_y(int y)
{
    position_y = y;
}

void Shape::moveShape(int x, int y)
{
    position_x = x;
    position_y = y;
}

void Shape::resizeShape(int len, int w)
{
    length = len;
    width = w;
}

void Shape::recolourShape(std::string &col)
{
    colour = col;
}
