#ifndef OBSERVER_H
#define OBSERVER_H

class IObserver
{
    public:
        virtual void notificar() = 0;
};

#endif
