#ifndef OBSERVER_H
#define OBSERVER_H

#include <string>
#include <map>

using namespace std; 

class Notificacion;

class IObserver
{
    public:
        virtual void notificar() = 0;
        virtual ~IObserver(){};
};

#endif
