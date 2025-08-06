#include "TextboxFactory.h"
using namespace std;
#include <string>


Shape* TextboxFactory::createShape(){
    return new Textbox();
}
Shape* TextboxFactory::createShape(int length, int width, std::string &colour, int x, int y){
    return new Textbox(length,width,colour,x,y,*(new string ("Deafault")));
};

Shape* TextboxFactory::copyshape(Textbox &other){
    return new Textbox(other);
}

void TextboxFactory::toString(){
    cout << "Textbox Factory" << endl;
}