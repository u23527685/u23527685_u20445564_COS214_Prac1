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
    virtual ~Shape();
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

    void moveShape(int x, int y);
    void resizeShape(int len, int w);
    void recolourShape(std::string &col);

    virtual Shape *clone();
    virtual std::string toString();
};

#endif