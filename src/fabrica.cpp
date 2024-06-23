#include "../include/fabrica.h"

// #include <cstddef>
#include "../include/IVenta.h"
#include "../include/CVenta.h"
#include "../include/INotificacion.h"
#include "../include/CNotificacion.h"
#include "../include/IFecha.h"
#include "../include/CFecha.h"

Fabrica *Fabrica::instancia = nullptr;

Fabrica::Fabrica(){};

Fabrica *Fabrica::getInstanceF()
{
    if (instancia == nullptr)
        instancia = new Fabrica();
    return instancia;
};

IUsuario *Fabrica::getIUsuario()
{
    return ControladorUsuario::getInstance();
};

IVenta *Fabrica::getIVenta()
{
    ControladorVenta *controlador = ControladorVenta::getInstanciaVen();
    return controlador->getInstanciaVen();
};

INotificacion *Fabrica::getINotificacion()
{
    ControladorNotificacion *controlador = ControladorNotificacion::getInstanciaN();
    return controlador->getInstanciaN();
};

IFecha *Fabrica::getIFecha()
{
    ControladorFecha *controlador = ControladorFecha::getInstanciaFecha();
    return controlador->getInstanciaFecha();
};
