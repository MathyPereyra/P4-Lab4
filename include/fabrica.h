#ifndef FABRICA_H
#define FABRICA_H

#include "IUsuario.h"
#include "INotificacion.h"
#include "IVenta.h"

class Fabrica
{
private:
    Fabrica* instancia;
public:
    IUsuario getIUsuario();
    IVenta getIVenta();
    INotificacion getINotificacion();
    Fabrica* getInstance();
};

#endif