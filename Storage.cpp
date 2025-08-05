#include "Storage.h"

using namespace std; 

Storage::~Storage(){
    for (list<Memento*>::iterator it=mementos.begin();it!=mementos.end();it++){
        delete *it;
    }
    mementos.clear();
}

void Storage::saveMemento(Memento* recent){
   mementos.push_front(recent);
}

Memento* Storage::getMemento(){
    if (mementos.empty()) {
        return nullptr;
    }
    Memento* recent = mementos.front();
    mementos.pop_front();
    return recent;
}

Storage::Storage()
{
}
