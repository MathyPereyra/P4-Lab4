#include "../include/cliente.h"

#include <string>

using namespace std;

Cliente::Cliente(string nickname, string contrasena, DTFecha fechaNac, string direccion, string ciudad)
    : Usuario(nickname, contrasena, fechaNac), direccion(direccion), ciudad(ciudad){}


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

string Cliente::getDireccion()
{
  return this->direccion;
};

string Cliente::getCiudad()
{
  return this->ciudad;
};

 map<string, Notificacion*> Cliente::getNotificaciones()
{
   return this->notificaciones;
};


map<int, Compra*> Cliente::getCompras()
{
 return this->compras;
}


map<int, Comentario*> Cliente::getComentarios()
{
  return this->comentarios;
}

map<string, Vendedor *> Cliente::getVendedoresSuscritos()
{
  return this->vendedoresSuscritos;
}

void Cliente::agregarComentario(int id, Comentario * comen)
{
  this->comentarios[id] = comen;
}



 void Cliente::crearCompra( Compra * compra)
{
  int id = compra->getId();
  this->compras[id] = compra;
}


DTCliente * Cliente::getDatosCliente()
{
  return new DTCliente (this->nickname, this->contrasena, this->fechaNac, this->ciudad, this->direccion);
}



DTUsuario * Cliente::getDatosUsuario()
{

  DTUsuario *  DC = new DTCliente(this->nickname, this->contrasena, this->fechaNac, this->ciudad, this->direccion);
  return DC;
}


void Cliente::eliminarNotificaciones()
{
  map<string, Notificacion*> notis = this->getNotificaciones();
  map<string, Notificacion*>::iterator it;
  for(it = notis.begin(); it != notis.end(); it++)
  {
    delete it->second;
    it = notis.erase(it);
  }
}


void Cliente::notificar(Notificacion * noti)
{
  this->notificaciones[noti->getNombreProm()] = noti;
}

//void Cliente::setUltimaConsulta(DTFecha fecha)
//{
//  this->ultimaConsulta = fecha;
//};
//
//
//DTFecha Cliente::getUltimaConsulta()
//{
//  return this->ultimaConsulta;
//};

// set<DTComentario> Cliente::listadoComentarioCliente()
//{
//   set<DTComentario> listadoComens;
//   for (Comentario comen : *this->comentarios)
//   {
//     DTComentario dataComentario = DTComentario(comen.getText(), comen.getId(), comen.getFecha());
//     listadoComens.insert(dataComentario);
//   }
//   return listadoComens;
// }

