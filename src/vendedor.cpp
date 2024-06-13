#include "../include/usuario.h" //este creo que no es necesario incluirlo, ya viene a traves de vendedor.h
#include "../include/vendedor.h"
#include "../include/producto.h"
#include "../include/promocion.h"
#include "../include/datatypes.h"
#include "../include/cliente.h"

#include <string>

using namespace std;

Vendedor::Vendedor(string nickname, string contrasena, DTFecha fechaNac, string codigoRUT)
    : Usuario(nickname, contrasena, fechaNac, tipo::vendedor), codigoRUT(codigoRUT) {}



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
            int id = p.getId();
            string nombre = p.getNombre(); // no existe en producto.h una operación llamada getNombre()
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


DTVendedor Vendedor::getDatos()
{
  DTVendedor DV = DTVendedor(this->nickname, this->contrasena, this->fechaNac, this->codigoRUT);
  return DV;
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


