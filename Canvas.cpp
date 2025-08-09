using namespace std;
#include "Canvas.h"
#include "Memento.h"
#include "Memento.cpp"
#include "ExportCanvas.h"
#include "PDFExporter.h"
#include "PNGExporter.h"
#include<iostream>

class Memento;

Canvas::~Canvas(){
    for(int i=0;i<size;i++){
        delete shapes[i];
        shapes[i]=nullptr;
    }
    delete[]shapes;
    shapes=nullptr;
    if (exportCanvas){
        delete exportCanvas;
        exportCanvas = nullptr;
    }
    
}

Canvas::Canvas(){
    size=10;
    shapes= new Shape*[size];
    for(int i=0;i<size;i++){
        shapes[i] = nullptr;
    }
    exportCanvas = nullptr;
}

Memento* Canvas:: captureCurrent(){
    return new Memento(shapes,capacity);
}

void Canvas:: undoAction(Memento* prev){
    if(prev==nullptr){
        return;
    }
    for(int i=0;i<capacity;i++){
        delete shapes[i];
        shapes[i]=nullptr;
    }
    delete[]shapes;
    size=prev->capacity;
    capacity=prev->capacity;
    shapes=new Shape*[size];
    Shape** o=prev->getShapes();
    for(int i=0;i<size;i++){
        shapes[i]=o[i]->clone();
    }
}

// void Canvas::exportfile()
// {
    
// }

void Canvas:: addShape(Shape* newShape){
    if(newShape==nullptr){
        return ;
    }
    if(capacity>=size){
        Shape** temp=new Shape*[size];
        int os=capacity;
        for(int i=0;i<size;i++){
            temp[i]=shapes[i]->clone();
        }
        while(size<=capacity){
            size=size*2;
        }
        shapes= new Shape*[size];
        for(int i=0;i<size;i++){
            shapes[i] = nullptr;
        }
        for(int i=0;i<os;i++){
            shapes[i]=temp[i];
        }
        shapes[capacity]=newShape;
        capacity++;
        delete[] temp;
    }else{
        shapes[capacity]=newShape;
        capacity++;
    }
}

void Canvas::print(){
    for(int i=0;i<capacity;i++){
        if(shapes[i]!=nullptr)
            cout<<shapes[i]->toString()<<endl;
    }
}

void Canvas::createExporter(const string &type)
{
    delete exportCanvas;
    exportCanvas = nullptr;
    if (type == "PNG") {
        exportCanvas = new PNGExporter(this);
    } 
    else if (type == "PDF") {
        exportCanvas = new PDFExporter(this);
    } 
    else {
        exportCanvas = nullptr;
    }
}
