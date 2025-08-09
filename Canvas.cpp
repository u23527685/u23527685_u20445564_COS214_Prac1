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
        if (shapes[i] != nullptr){
            delete shapes[i];
            shapes[i]=nullptr;
        }
    }
    delete[]shapes;
    shapes=nullptr;
    if (exportCanvas!=nullptr){
        delete exportCanvas;
        exportCanvas = nullptr;
    }
    
}

Canvas::Canvas(){
    capacity=0;
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
        if(shapes[i]!=nullptr)
            delete shapes[i];
        shapes[i]=nullptr;
    }
    delete[]shapes;
    capacity=prev->capacity;
    if(capacity > size) {
        while(size<=capacity){
            size=size*2;
        }
        delete[] shapes;
        size = capacity * 2;  // Give some extra space
        shapes = new Shape*[size];
    }
    for(int i=0;i<size;i++){
        shapes[i] = nullptr;
    }
    Shape** o=prev->getShapes();
    for(int i=0;i<capacity;i++){
        if(o[i]!=nullptr)
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
        Shape** temp=shapes;
        int os=capacity;
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
