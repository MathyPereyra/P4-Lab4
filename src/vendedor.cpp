#include "../include/vendedor.h"

#include "../include/cliente.h"
#include "../include/promocion.h"
#include <string>

using namespace std;

Vendedor::Vendedor(string nickname, string contrasena, DTFecha fechaNac, string codigoRUT)
    : Usuario(nickname, contrasena, fechaNac), codigoRUT(codigoRUT) {}

string Vendedor::getNickname()
{
  return this->nickname; // no podemos acceder directo a nickname para que funcione le puse visibildiad protected a nickname en usuario.h
};

string Vendedor::getContrasena()
{
  return this->contrasena; // no podemos acceder directo a nickname para que funcione le puse visibildiad protected a nickname en usuario.h
};

string Vendedor::getCodigoRUT()
{
  return this->codigoRUT;
};

map<int, Producto *> Vendedor::getProductos()
{
  return this->productos;
};

map<string, Promocion *> Vendedor::getPromociones()
{
  return this->promociones;
};

void Vendedor::agregarProm(Promocion *prom)
{
  this->promociones[prom->getNombre()] = prom;
}

bool Vendedor::estaSuscrito(string nicknameC)
{
  bool esta = false;
  if (this->suscriptores.find(nicknameC) != this->suscriptores.end())
  {
    esta = true;
  }

  return esta;
};

map<int, Comentario *> Vendedor::getComentarios()
{
  return this->comentarios;
};

void Vendedor::agregarComentario(int id, Comentario *comen)
{
  this->comentarios[id] = comen;
}

void Vendedor::agregarSuscriptor(IObserver *usuario)
{
  this->suscriptores[usuario->getNickname()] = usuario;
}

void Vendedor::eliminarSuscriptor(IObserver *usuario)
{
  Cliente *cliente = dynamic_cast<Cliente *>(usuario);
  cliente->eliminarNotificaciones();
  this->suscriptores.erase(usuario->getNickname());
}

void Vendedor::crearCompra(Compra *compra) {}

DTUsuario *Vendedor::getDatosUsuario()
{
  DTUsuario *DV = new DTVendedor(this->nickname, this->contrasena, this->fechaNac, this->codigoRUT);
  return DV;
}

DTVendedor *Vendedor::getDatosVendedor()
{
  DTVendedor *DV = new DTVendedor(this->nickname, this->contrasena, this->fechaNac, this->codigoRUT);
  return DV;
}

void Vendedor::promoCreada(Notificacion *noti)
{
  this->notificarSuscriptores(noti);
}

void Vendedor::notificarSuscriptores(Notificacion *noti)
{
  map<string, IObserver *>::iterator it;
  for (it = this->suscriptores.begin(); it != this->suscriptores.end(); it++)
  {
    it->second->notificar(noti);
  }
}

void Vendedor::agregarProd(Producto *prod)
{
  this->productos[prod->getId()] = prod;
}

// set<DTComentario> Vendedor::listadoComentarioVendedor()
//{
//   set<DTComentario> listadoComens;
//   for (Comentario comen : this->comentarios)
//   {
//     DTComentario dataComentario = DTComentario(comen.getText(), comen.getId(), comen.getFecha());
//     listadoComens.insert(dataComentario);
//   }
//   return listadoComens;
// }
