#include "RectangleFactory.h"
using namespace std;

Shape* RectangleFactory::createShape(){
    return new Rectangle();
}

Shape* RectangleFactory::createShape(int length, int width, std::string &colour, int x, int y){
    return new Rectangle(length,width,colour,x,y);
};

Shape* RectangleFactory::copyshape(const Shape &other){
    const Rectangle* r= dynamic_cast<const Rectangle*>(&other);
    if(r)
        return new Rectangle(*r);
    return nullptr;
}
 void RectangleFactory::toString(){
    cout<<"A Rectangle has a length and a width wich are not the same distance and has 4 sides"<<endl;
 }