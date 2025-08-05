#ifndef TEXTBOX_H
#define TEXTBOX_H

#include "Shape.h"
#include <string>

class Textbox : public Shape
{
private:
    int width;
    std::string text;
    int position_x;
    std::string colour;
    int position_y;
    int length;

public:
    Textbox();
    Textbox(int l, int w, std::string &colour, int x, int y, std::string &text);
    ~Textbox();

    Shape *clone();
    std::string toString();
};

#endif
