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
    virtual set<DTUsuario *> listarVendedoresNoSuscritos(string nickname) = 0;
    virtual void suscribirAVendedor(string nicknameC, string nicknameV) = 0;
    virtual set<DTNotificacion> mostrarNotificaciones(string nickname) = 0;
    virtual void eliminarNotificacion() = 0;
    virtual set<DTUsuario *> listarVendedoresSuscritos(string nickname) = 0;
    virtual void eliminarSuscripcion(string nicknameC, string nicknameV) = 0;

    virtual ~INotificacion(){};
};

#endif
