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

Memento:: ~Memento(){
    delete[]shapes;
}

Shape** Memento::getShapes(){
    return shapes;
}
