#ifndef TEXTBOX_H
#define TEXTBOX_H

#include "Shape.h"
#include <string>

class Textbox : public Shape
{
private:
    std::string text;
    /*int width;
    int position_x;
    std::string colour;
    int position_y;
    int length;
*/
public:
    Textbox();
    Textbox(const Textbox &other);
    Textbox(int l, int w, std::string &colour, int x, int y, std::string &text);
    ~Textbox();
    Shape *clone()override;
    std::string toString() override;
    void changeText(std::string txt);
};

#endif
