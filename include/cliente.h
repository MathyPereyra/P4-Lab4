#ifndef CLIENTE_H
#define CLIENTE_H

#include <string>
#include <set>
#include <map>

#include "usuario.h"
#include "datatypes.h"
#include "observer.h"

using namespace std;

class Cliente : public Usuario, public IObserver
{
private:
  string direccion;
  string ciudad;
  set<DTNotificacion> notificaciones;

public:
  Cliente(string dir, string ciud);
  crearCompra();
  agregarSuscripcion();
  eliminarNotifiaciones();
  notificar(String nVen, String nProm, set <DTProducto>);
  DTUsuario getDatos();
  string getDir();
  string getCiudad();
  set<DTNotificacion> getNotificaciones();

  virtual ~Cliente();
};

#endif