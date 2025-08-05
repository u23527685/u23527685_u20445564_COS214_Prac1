#include <string>
#include <iostream>
#include "Shape.h"
#include "Rectangle.h"

class Rectangle : public Shape
{
private:
    std::string colour;
    int length;
    int position_y;
    int width;
    int position_x;

public:
    Rectangle(int len = 10, int w = 5, std::string &col = "blue", int x = 0, int y = 0)
        : Shape(len, w, col, x, y),
          colour(col), length(len), position_y(y), width(w), position_x(x) {}

    Rectangle(Rectangle &other)
        : Shape(0, 0, "", 0, 0),
          colour(other.colour), length(other.length), position_y(other.position_y),
          width(other.width), position_x(other.position_x) {}

    Shape *Rectangle::clone()
    {
        return new Rectangle(*this);
    }

    void draw()
    {
        std::cout << "Drawing Rectangle at (" << position_x << "," << position_y
                  << ") with dimensions " << length << "x" << width
                  << " in " << colour << " colour" << std::endl;
    }

    std::string toString()
    {
        return "Rectangle[" + std::to_string(length) + "x" + std::to_string(width) +
               ", " + colour + ", (" + std::to_string(position_x) + "," +
               std::to_string(position_y) + ")]";
    }

    void moveRectangle(int x, int y)
    {
        position_x = x;
        position_y = y;
    }

    void resizeRectangle(int len, int w)
    {
        length = len;
        width = w;
    }

    void recolourRectangle(std::string &col)
    {
        colour = col;
    }
};
