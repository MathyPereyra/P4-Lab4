#ifndef OBSERVER_H
#define OBSERVER_H

#include "notificacion.h"
#include <string>
#include <map>

using namespace std; 

class IObserver
{
    public:
        virtual void notificar(Notificacion * noti) = 0;
        virtual string getNickname() = 0;
        virtual ~IObserver(){};
};

#endif
