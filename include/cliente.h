#ifndef CLIENTE_H
#define CLIENTE_H

#include <string>
#include <set>
#include <map>

#include "usuario.h"
#include "datatypes.h"
#include "observer.h"
#include "compra.h"

using namespace std;

class Cliente : public Usuario, public IObserver
{
private:
  string direccion;
  string ciudad;
  set<DTNotificacion> *notificaciones;
  set<Compra> *compras;

public:
  Cliente(string nickname, string contrasena, DTFecha fechaNac, string dir, string ciud);

  void crearCompra();
  void agregarSuscripcion();
  void eliminarNotifiaciones();
  void notificar(string nVen, string nProm, set<DTProducto>);
  void listadoComentarioCliente();

  DTCliente getDatosCliente();
  string getNickname();
  DTFecha getFecha();
  string getDireccion();
  string getCiudad();
  set<DTNotificacion> getNotificaciones();
  set<Comentario> getComentarios();
  set<Compra> getCompras();

  virtual ~Cliente();
};

#endif
