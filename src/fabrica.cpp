#include "../include/fabrica.h"

//#include <cstddef>
#include "../include/IVenta.h"
#include "../include/CVenta.h"
//#include "../include/INotificacion.h"
//#include "../include/CNotificiacion.h"

Fabrica * Fabrica::instancia = nullptr;

Fabrica::Fabrica(){};

Fabrica* Fabrica::getInstanceF()
{
    if (instancia == nullptr)
        instancia = new Fabrica();
    return instancia;
};

IUsuario* Fabrica::getIUsuario()
{
    return ControladorUsuario::getInstance();
};

IVenta* Fabrica::getIVenta()
{
    ControladorVenta* controlador = ControladorVenta::getInstancia();
    return controlador->getInstancia();
};

//IUsuario* Fabrica::getINotificacion()
//{
//    ControladorNotificacion* controlador = ControladorNotificacion::getInstancia();
//    return controlador->getInstance();
//};