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
    cout<<"6 shapes"<<endl;
    for(int i=0;i<6;i++){
        c.createShape(factory[i%3]);
        s.saveMemento(c.captureCurrent());
    }
    c.print();
    c.createExporter("PNG");
    c.exportThis();

    c.undoAction(s.getMemento());
    cout<<"5 shapes"<<endl;
    c.print();
    for(int i=0;i<3;i++){
        factory[i]->print();
    }
    s.saveMemento(c.captureCurrent());
    Canvas d= Canvas();
    cout<<"6 shapes"<<endl;
    for(int i=0;i<20;i++){
        d.createShape(factory[i%3]);
    }
    d.createExporter("PDF");
    d.print();
    d.exportThis();
    for(int i=0;i<6;i++){
        d.getShape(i)->resizeShape(i,i);
        d.getShape(i)->moveShape(i,i);
        d.getShape(i)->setColour("changey");
    }
    cout<<"6 shapes changed"<<endl;
    d.print();
    for(int i=0;i<3;i++){
        d.createShape(factory[i],i*20,i*20,*(new string("newey")),i*20,i*20);
    }

    Textbox text= Textbox();
    text.changeText("Setty");
    cout<<"Textbox sett"<<endl;
    cout<<text.toString()<<endl;
    cout<<"9 shapes"<<endl;
    d.print();
    for(int i=0;i<3;i++){
        factory[i]->print();
    }
    d.createShape(factory[2],text);
    cout<<"10 shapes"<<endl;
    d.print();
    

    for(int i=0;i<3;i++){
        delete factory[i];
        factory[i]=nullptr;
    }
    delete[] factory;
    factory= nullptr;

}