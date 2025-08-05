#include "RectangleFactory.h"
using namespace std;

Shape* RectangleFactory::createShape(){
    return new Rectangle();
}

Shape* RectangleFactory::createShape(int length, int width, std::string &colour, int x, int y){
    return new Rectangle(length,width,colour,x,y);
};

Shape* RectangleFactory::copyshape(Rectangle &other){
    return new Rectangle(other);
}
 void RectangleFactory::toString(){
    cout<<"A Rectangle has a length and a width wich are not the same distance and has 4 sides"<<endl;
 }