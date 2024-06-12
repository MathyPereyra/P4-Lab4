#include "../include/usuario.h"
#include <string>

using namespace std;

Usuario::Vendedor(string nickname, string contrasena, DTFecha fechaNac, string codigoRUT, set<Producto> productos)
    : nickname(nickname), contrasena(contrasena), fechaNac(fechaNac), codigoRUT(codigoRUT), productos(productos){};

string Vendedor::getNickname()
{
  return this->nickname;
};

string Vendedor::getContrasena()
{
  return this->contrasena;
};

string Vendedor::getCodigoRUT() 
{
  return this->codigoRUT;
};

set<Producto> Vendedor::getProductos() 
{
  return this->productos;
};

set<Promocion> Vendedor::getPromociones() 
{
  return this->promociones;
};

set<Comentario> Vendedor::getComentarios()
{
  return this->comentarios;
}


set<DTIdNProducto> Vendedor::getProductosNoEnPromo() 
{
  set<DTIdNProducto> setInfoProductos;
  for (Producto p : this->productos)
  {
    if (!(p.estaEnPromo()))
        {
            integer id = p.getId();
            string nombre = p.getNombre();
            DTIdNProducto dp = DTIdNProducto(id, nombre);
            setInfoProductos.insert(dp);
        }
  }
  return setInfoProductos;
}

void Cliente::agregarSuscripcion()
{
}

void Vendedor::eliminarSuscriptor()
{
}


DataCliente Cliente::getDatos()
{
  DataCliente DC = DataCliente(this->nickname, this->fechaNac, this->ciudad, this->direccion);
  return DC;
}

set<DTComentario> Vendedor::listadoComentario() 
{
  set<DTComentario> listadoComens;
  for (Comentario comen : this->comentarios)
  {
    DTComentario dataComentario = DTComentario(comen.getText(), comen.getId(), comen.getFecha());
    listadoComens.insert(dataComentario);
  }
  return listadoComens;
}
