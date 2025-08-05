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
    ShapeFactory* factory=new ShapeFactory[3]; 
    factory[0]= SquareFactory();
    factory[1]= RectangleFactory();
    factory[2]= TextboxFactory();
    for(int i=0;i<20;i++){
        c.addShape(factory[i%3].work());
    }
    c.print();
}