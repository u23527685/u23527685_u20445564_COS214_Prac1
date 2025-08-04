#include "Memento.h"
class Shape;

using namespace std;

Memento::Memento(Shape* elements,int size){
    this->size=size;
    shapes= new Shape [size];
    for(int i=0;i<size;i++){
        shapes[i]=Shape(elements[i]);
    }
}

Memento::Memento(){
    size=0;
    shapes=nullptr;
}

bool Memento::isNULL(){
    return shapes==nullptr;
}

Memento::Memento(const Memento &other){
    size=other.size;
    shapes= new Shape [size];
    for(int i=0;i<size;i++){
        shapes[i]=other.shapes[i];
    }
}
