#include "TextboxFactory.h"
using namespace std;



Shape* TextboxFactory::createShape(){
    return new Textbox();
}
Shape* TextboxFactory::createShape(int length, int width, std::string &colour, int x, int y,string &text){
    return new Textbox(length,width,colour,x,y,text);
};

Shape* TextboxFactory::copyshape(Textbox &other){
    return new Textbox(other);
}
// void TextboxFactory::toString(){
//     cout << "Textbox Factory" << endl;
// }