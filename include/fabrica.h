#ifndef FABRICA_H
#define FABRICA_H

#include "IUsuario.h"
#include "INotificacion.h"
#include "IVenta.h"

class Fabrica
{
private:
    static Fabrica *instancia;
    Fabrica();
public:
    IUsuario* getIUsuario();
    IVenta* getIVenta();
    INotificacion* getINotificacion();
    static Fabrica* getInstance();
};

#endif