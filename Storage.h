#ifndef STORAGE_H
#define STORAGE_H
using namespace std;

#include"Memento.h"
#include <list>
class Memento;

class Storage{
    public:
        void saveMemento( Memento* recent);
        Memento* getMemento();
        Storage();
        ~Storage();
    private:
        list<Memento*> mementos;
};
#endif