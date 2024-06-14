#include "../include/usuario.h"
#include <string>
#include <compra.h>

using namespace std;

Usuario::Cliente(string nickname, string contrasena, DTFecha fechaNac, string direccion, string ciudad, set<DataNotificacion> notificaciones)
    : nickname(nickname), contrasena(contrasena), fechaNac(fechaNac), direccion(direccion), ciudad(ciudad), notificaciones(notificaciones){};

string Cliente::getNickname()
{
  return this->nickname;
};

string Cliente::getContrasena()
{
  return this->contrasena;
};

DTFecha Cliente::getFechaNac()
{
  return this->fechaNac;
};

string Cliente::getCiudad()
{
  return this->ciudad;
};

string Cliente::getDireccion()
{
  return this->direccion;
};

string Cliente::getNotificaciones()
{
  return this->notificaciones;
};

set<Compra> Cliente::getCompras()
{
  return this->compras;
}

set<Comentario> Cliente::getComentarios()
{
  return this->comentarios;
}

void Cliente::crearCompra(int id)
{
  Compra d = Compra();
  d.setId(id);
  this->compras.insert(d);
}

DataCliente Cliente::getDatosCliente()
{
  DataCliente DC = DataCliente(this->nickname, this->fechaNac, this->ciudad, this->direccion);
  return DC;
}

set<DTComentario> Cliente::listadoComentarioCliente()
{
  set<DTComentario> listadoComens;
  for (Comentario comen : this->comentarios)
  {
    DTComentario dataComentario = DTComentario(comen.getText(), comen.getId(), comen.getFecha());
    listadoComens.insert(dataComentario);
  }
  return listadoComens;
}
