using namespace std;
#include "Canvas.h";

Canvas::~Canvas(){
    delete[]shapes;
    shapes=nullptr;
}

Canvas::Canvas(){
    size=0;
    shapes= new Shape[size];
}

Memento* Canvas:: captureCurrent(){
    return new Memento(shapes,size);
}

void Canvas:: undoAction(Memento* prev){
    size=prev->size;
    delete[]shapes;
    shapes= new Shape[size];
    for(int i=0;i<size;i++){
        shapes[i]=prev->shapes[i];
    }
}

void Canvas::operation()
{
}
