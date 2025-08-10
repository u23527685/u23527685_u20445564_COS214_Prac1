#include "TextboxFactory.h"
using namespace std;
#include <string>


Shape* TextboxFactory::createShape(){
    return new Textbox();
}
Shape* TextboxFactory::createShape(int length, int width, std::string &colour, int x, int y){
    return new Textbox(length,width,colour,x,y,*(new string ("Newey")));
};

Shape* TextboxFactory::copyshape(const Shape &other){
    const Textbox* t= dynamic_cast<const Textbox*>(&other);
    if(t)
        return new Textbox(*t);
    return nullptr;
}

void TextboxFactory::toString(){
    cout << "Textbox Factory" << endl;
}