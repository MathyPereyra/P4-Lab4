#ifndef OBSERVER_H
#define OBSERVER_H

#include <string>
#include <map>

using namespace std; 

class IObserver
{
    public:
        virtual void notificar() = 0;
        virtual string getNickname() = 0;
        virtual ~IObserver(){};
};

#endif
