#include "../include/cliente.h"

#include <string>

using namespace std;

Cliente::Cliente(string nickname, string contrasena, DTFecha fechaNac, string direccion, string ciudad)
    : Usuario(nickname, contrasena, fechaNac), direccion(direccion), ciudad(ciudad){}

// Cliente::~Cliente(){
//     delete compras;
// };

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
//
// set<DTNotificacion> Cliente::getNotificaciones()
//{
//  // return this->notificaciones; //esto estaba porque en el constructor pasabamos por parámetro el set DTNotificaciones, pero eso es incorrecto
//};
//
map<int, Compra*> Cliente::getCompras()
{
 return this->compras;
}

map<int, Comentario*> Cliente::getComentarios()
{
  return this->comentarios;
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

DTUsuario Cliente::getDatosUsuario()
{
  DTUsuario DC = DTCliente(this->nickname, this->contrasena, this->fechaNac, this->ciudad, this->direccion);
  return DC;
}

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

 