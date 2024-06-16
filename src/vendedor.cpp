#include "../include/vendedor.h"

//#include "../include/cliente.h"

#include <string>

using namespace std;

Vendedor::Vendedor(string nickname, string contrasena, DTFecha fechaNac, string codigoRUT)
    : Usuario(nickname, contrasena, fechaNac), codigoRUT(codigoRUT){}

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

map<int, Producto*> Vendedor::getProductos()
{
  return this->productos;
};

set<Promocion> Vendedor::getPromociones()
{
  return this->promociones;
};

set<Comentario>* Vendedor::getComentarios()
{
  return this->comentarios;
}

//set<DTIdNProducto> Vendedor::getProductosNoEnPromo()
//{
//  set<DTIdNProducto> setInfoProductos;
//  for (Producto p : this->productos)
//  {
//    if (!(p.estaEnPromo()))
//    {
//      int id = p.getId();
//      string nombre = p.getNombre(); // no existe en producto.h una operación llamada getNombre()
//      DTIdNProducto dp = DTIdNProducto(id, nombre);
//      setInfoProductos.insert(dp);
//    }
//  }
//  return setInfoProductos;
//}
//
//void Cliente::agregarSuscripcion()
//{
//}

void Vendedor::eliminarSuscriptor()
{
}

DTUsuario Vendedor::getDatosUsuario()
{
  DTUsuario DV = DTVendedor(this->nickname, this->contrasena, this->fechaNac, this->codigoRUT);
  return DV;
}

void Vendedor::agregarProd(Producto * prod)
{
  this->productos[prod->getId()] = prod;
}


//set<DTComentario> Vendedor::listadoComentarioVendedor()
//{
//  set<DTComentario> listadoComens;
//  for (Comentario comen : this->comentarios)
//  {
//    DTComentario dataComentario = DTComentario(comen.getText(), comen.getId(), comen.getFecha());
//    listadoComens.insert(dataComentario);
//  }
//  return listadoComens;
//}

