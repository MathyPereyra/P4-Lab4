#ifndef INOTIFICACION_H
#define INOTIFICACION_H

#include <string>
#include <set>
#include <map>

#include "CUsuario.h"
#include "IUsuario.h"
#include "usuario.h"
#include "datatypes.h"
#include "observer.h"


using namespace std;

class INotificacion 
{
public:

    virtual set<DTVendedor> listarVendedoresNoSuscritos(string nickname) = 0;
    virtual void suscribirAVendedor(string nickname, set<DTVendedor> suscritos) = 0;
    virtual set<DTVendedor> mostrarSuscripciones(string nickname) = 0;
    virtual set<DTNotificacion> mostrarNotificaciones(string nickname, IUsuario * contUsuario) = 0;
    virtual void eliminarNotificacion() = 0;
    virtual set<DTVendedor> listarVendedoresSuscritos(string nickname) = 0;
    virtual void eliminarSuscripciones(string nickname, set<DTVendedor> vendedores) = 0;
    virtual Notificacion *obtenerNotificacion() = 0;

    virtual ~INotificacion(){};
};

#endif