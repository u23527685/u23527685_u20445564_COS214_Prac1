#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"
#include <string>

class Rectangle : public Shape
{
/*private:
    std::string colour;
    int width;
    int position_y;
    int length;
    int position_x;
*/
public:
    Rectangle();
    Rectangle(const Rectangle &other);
    Rectangle(int l, int w, std::string &colour, int x, int y);
    ~Rectangle();

    Shape *clone() override;
    std::string toString() override;
};

#endif
