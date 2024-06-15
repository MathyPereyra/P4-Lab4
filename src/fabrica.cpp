#include "../include/fabrica.h"
#include "../include/IUsuario.h"
#include "../include/CUsuario.h"
//#include "../include/IVenta.h"
//#include "../include/CVenta.h"
//#include "../include/INotificacion.h"
//#include "../include/CNotificiacion.h"

Fabrica* Fabrica::getInstance()
{
    if (instancia == NULL)
        instancia = new Fabrica();
    return instancia;
};

IUsuario* Fabrica::getIUsuario()
{
    ControladorUsuario* controlador = ControladorUsuario::getInstancia();
    return controlador->getInstance();
};

//IVenta* Fabrica::getIVenta()
//{
//    ControladorVenta* controlador = ControladorVenta::getInstancia();
//    return controlador->getInstance();
//};
//
//IUsuario* Fabrica::getINotificacion()
//{
//    ControladorNotificacion* controlador = ControladorNotificacion::getInstancia();
//    return controlador->getInstance();
//};