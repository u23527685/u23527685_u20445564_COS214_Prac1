#include "Memento.h"
#include "Shape.h"
class Shape;

using namespace std;

Memento::Memento(Shape** elements,int cap){
    capacity=cap;
    shapes= new Shape*[cap];
    for(int i=0;i<cap;i++){
        shapes[i]=elements[i]->clone();
    }
}

Memento::Memento(){
    capacity=0;
    shapes=nullptr;
}

bool Memento::isNULL(){
    return shapes==nullptr;
}

Memento::Memento(const Memento &other){
    capacity=other.capacity;
    shapes=new Shape*[capacity];
    for(int i=0;i<capacity;i++){
        shapes[i]=other.shapes[i]->clone();
    }
}

Memento:: ~Memento(){
    delete[]shapes;
}

Shape** Memento::getShapes(){
    return shapes;
}
