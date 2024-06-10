#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <string>
#include <set>
#include <map>

#include "usuario.h"
#include "datatypes.h"
#include "observer.h"

using namespace std;

class Producto : 
{
private:
  integer id;
  categoria cat;
  string descripcion;
  integer cantStock;
  float precio;
public:
  Producto(integer id, categoria cat, string desc, integer cantStock, float precio);
  bool estaEnPromo();
  float calcularDescuento();

  DTProducto getDataProducto();
  integer getId();
  categoria getCat();
  string getDesc();
  integer getCantStock();
  float getPrecio();

  virtual ~Producto();
};

#endif