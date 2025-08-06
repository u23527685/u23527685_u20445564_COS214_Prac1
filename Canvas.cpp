using namespace std;
#include "Canvas.h"
#include "Memento.h"
#include "Memento.cpp"
#include<iostream>

class Memento;

Canvas::~Canvas(){
    delete[]shapes;
    shapes=nullptr;
}

Canvas::Canvas(){
    size=10;
    shapes= new Shape*[size];
}

Memento* Canvas:: captureCurrent(){
    return new Memento(*shapes,size);
}

void Canvas:: undoAction(Memento* prev){
    if(prev==nullptr){
        return;
    }
    for(int i=0;i<size;i++){
        delete shapes[i];
    }
    size=prev->size;
    delete[]shapes;
    shapes= new Shape*[size];
    for(int i=0;i<size;i++){
        shapes[i]=prev->shapes[i];
    }
}

void Canvas:: addShape(Shape* newShape){
    if(newShape==nullptr){
        return ;
    }
    if(capacity==size){
        Shape** temp=new Shape*[size];
        int os=size;
        for(int i=0;i<size;i++){
            temp[i]=shapes[i];
        }
        size*=2;
        shapes= new Shape*[size];
        for(int i=0;i<os;i++){
            shapes[i]=temp[i];
        }
        shapes[capacity]=newShape;
        delete[] temp;
        capacity++;
    }else{
        shapes[capacity]=newShape;
        capacity++;
    }
}

void Canvas::print(){
    for(int i=0;i<capacity;i++){
        cout<<shapes[i]->toString()<<endl;
    }
}