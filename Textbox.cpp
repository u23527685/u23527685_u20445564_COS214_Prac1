#include "Textbox.h"
#include "Shape.h"
#include <sstream>

using namespace std;

Textbox::Textbox(const Textbox &other){}

Textbox::Textbox()
    : Shape(10,20,*(new string("black")),0,0){
        text="default";
    }

Textbox::Textbox(int l, int w, std::string &colour, int x, int y, std::string &txt)
    : Shape(l,w,colour,x,y), text(txt) {}

Textbox::~Textbox() {}

Shape* Textbox::clone()
{
    return new Textbox(*this);
}

std::string Textbox::toString()
{
    /*std::ostringstream out;
    out << "Textbox (length=" << length
        << ", width=" << width
        << ", colour=" << colour
        << ", x=" << position_x
        << ", y=" << position_y
        << ", text=\"" << text << "\")";
    return out.str();
    */
}

void Textbox::changeText(string txt){
    text=txt;
}