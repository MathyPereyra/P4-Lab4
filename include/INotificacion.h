#ifndef INOTIFICACION_H
#define INOTIFICACION_H

#include <string>
#include <set>
#include <map>

#include "usuario.h"
#include "datatypes.h"
#include "observer.h"

using namespace std;

class INotificacion 
{
virtual set<DTVendedor> listarVendedoresNoSuscritos(string nickname);
virtual void suscribirAVendedor(string nickname, set<DTVendedor> suscritos);
virtual set<DTVendedor> mostrarSuscripciones(string nickname);
virtual void eliminarNotificacion();
virtual set<DTVendedor> listarVendedoresSuscritos(string nickname)
virtual void eliminarSuscripciones(string nickname, set<DTVendedor> vendedores);

virtual ~INotificacion(){};
};