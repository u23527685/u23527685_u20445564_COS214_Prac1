#include"SquareFactory.h"
using namespace std;

Shape* SquareFactory::createShape(){
    return new Square();
}

Shape* SquareFactory::createShape(int length, int width, std::string &colour, int x, int y){
    return new Square(length,width,colour,x,y);
};

Shape* SquareFactory::copyshape(const Shape &other){
    const Square* square=dynamic_cast<const Square*>(&other);
    if(square)
        return new Square(*square);
    return nullptr;
}

void SquareFactory::toString(){
    cout<<"A Square has a length and a width wich are the same and has 4 sides"<<endl;
 }