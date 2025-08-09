#include"SquareFactory.h"
#include "Square.h"
#include "ShapeFactory.h"
#include "Shape.h"
#include "RectangleFactory.h"
#include "Canvas.h"
#include "TextboxFactory.h"
#include "Textbox.h"
#include "Storage.h"
#include "Memento.h"

using namespace std;
int main(){
    Canvas c= Canvas();
    Storage s= Storage();
    ShapeFactory** factory=new ShapeFactory*[3]; 
    factory[0]=new SquareFactory();
    factory[1]= new RectangleFactory();
    factory[2]= new TextboxFactory();
    cout<<"20 shapes"<<endl;
    for(int i=0;i<20;i++){
        c.addShape(factory[i%3]->work());
    }
    c.print();

    s.saveMemento(c.captureCurrent());

    cout<<"40 shapes"<<endl;
    for(int i=0;i<20;i++){
        c.addShape(factory[i%3]->work());
    }
    c.print();
    c.undoAction(s.getMemento());
    cout<<"20 shapes"<<endl;
    c.print();
    for(int i=0;i<5;i++){
        c.addShape(factory[i%3]->work());
    }
    cout<<"25 shapes"<<endl;
    c.print();

    for(int i=0;i<3;i++){
        delete factory[i];
        factory[i]=nullptr;
    }
    delete[] factory;
    factory= nullptr;
}