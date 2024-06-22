#ifndef FABRICA_H
#define FABRICA_H

#include "INotificacion.h"
#include "IUsuario.h"
#include "IVenta.h"
#include "IFecha.h"

class Fabrica
{
private:
    static Fabrica * instancia;
    Fabrica();
    
public:
    static Fabrica * getInstanceF();
    IUsuario* getIUsuario();
    IVenta* getIVenta();
    INotificacion* getINotificacion();
    IFecha* getIFecha();
};

#endif
