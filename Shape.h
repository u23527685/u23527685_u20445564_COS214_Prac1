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
    Shape(const Shape &other);
    virtual ~Shape()=0;
    int getLength() const;
    int getWidth() const;
    std::string getColour() const;
    int getPosition_x() const;
    int getPosition_y() const;
    
    void setLength(int length);
    void setWidth(int width);
    void setColour(const std::string &colour);
    void setPosition_x(int x);  
    void setPosition_y(int y);

    virtual void moveShape(int x, int y) = 0;
    virtual void resizeShape(int len, int w) = 0;
    virtual void recolourShape(std::string &col) = 0;

    virtual Shape *clone() = 0;
    virtual std::string toString() = 0;
};

#endif