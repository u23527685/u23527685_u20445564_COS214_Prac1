#include "Textbox.h"
#include "Shape.h"
#include <sstream>

Textbox::Textbox()
    : length(1), width(3), colour("black"), position_x(0), position_y(0), text("Default") {}

Textbox::Textbox(int l, int w, std::string &colour, int x, int y, std::string &txt)
    : length(l), width(w), colour(colour), position_x(x), position_y(y), text(txt) {}

Textbox::~Textbox() {}

Shape* Textbox::clone()
{
    return new Textbox(length, width, colour, position_x, position_y, text);
}

std::string Textbox::toString()
{
    std::ostringstream out;
    out << "Textbox (length=" << length
        << ", width=" << width
        << ", colour=" << colour
        << ", x=" << position_x
        << ", y=" << position_y
        << ", text=\"" << text << "\")";
    return out.str();
}
void moveTextbox(int x, int y)
    {
        position_x = x;
        position_y = y;
    }

void resizeTextbox(int len, int w)
{
    length = len;
    width = w;
}

void recolourTextbox(std::string &col)
{
    colour = col;
}