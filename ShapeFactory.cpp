#include "ShapeFactory.h"

ShapeFactory::~ShapeFactory()
{
    
}

Shape* ShapeFactory::work(){
            return createShape();
        }

Shape* ShapeFactory::work(int length, int width, std::string &colour, int x, int y){
    return createShape(length,width,colour,x,y);
}

Shape* ShapeFactory::work(const Shape &other){
    return copyshape(other);
}

void ShapeFactory::print(){
    toString();
}