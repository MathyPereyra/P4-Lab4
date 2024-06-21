#ifndef CLIENTE_H
#define CLIENTE_H

#include <string>
#include <set>
#include <map>

#include "notificacion.h"
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
  map<int, Compra*> compras;
  map<string, Vendedor *> vendedoresSuscritos;
  map<string, Notificacion*> notificaciones;
  DTFecha ultimaConsulta;

public:
  Cliente(string nickname, string contrasena, DTFecha fechaNac, string dir, string ciud);

  void crearCompra(int); // le agregue el parámetro int porque en cliente.cpp le pasamos el id
  void agregarSuscripcion();
  void eliminarNotifiaciones();
  void notificar(string nVen, string nProm, set<DTProducto>);

  void setUltimaConsulta(DTFecha fecha);
  //DTFecha getUltimaConsul

  void crearCompra(Compra * compra);
  DTUsuario getDatosUsuario();
  string getNickname();
  string getContrasena(); //debería ir? solo lo agregué porque estaría faltando para usar en cliente.cpp
  DTFecha getFechaNac();
  string getDireccion();
  string getCiudad();
  map<string, Notificacion*> getNotificaciones();
  map<int, Comentario*> getComentarios();
  map<string, Vendedor *>  getVendedoresSuscritos();
  void agregarComentario(int id, Comentario * comentario);
  map<int, Compra*> getCompras();
  void notificar();


  ~Cliente(){};
};

#endif
