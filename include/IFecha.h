#ifndef IFECHA_H
#define IFECHA_H


#include "datatypes.h"

using namespace std;

class IFecha
{
public:

    virtual DTFecha getFecha() = 0;
    virtual void setFecha(int dia, int mes, int anio) = 0;
    virtual ~IFecha(){};
    
};

#endif
