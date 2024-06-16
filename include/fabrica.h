#ifndef FABRICA_H
#define FABRICA_H

#include "IUsuario.h"
#include "CUsuario.h" // no se si va esto
//#include "INotificacion.h"
#include "IVenta.h"

class Fabrica
{
private:
    static Fabrica * instancia;
    Fabrica();
    
public:
    static Fabrica * getInstanceF();
    IUsuario* getIUsuario();
    IVenta* getIVenta();
//    INotificacion* getINotificacion();
};

#endif
