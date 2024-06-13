#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <string>
#include <set>
#include <map>

#include "datatypes.h"
#include "observer.h"
#include "usuario.h"

using namespace std;

class Producto 
{
private:
  int id;
  categoria cat;
  string descripcion;
  int cantStock;
  float precio;

  //Al crearlo esta = false, si el producto es agregado a alguna promocion esta = true
  bool esta;
public:
  Producto(int id, categoria cat, string descripcion, int cantStock, float precio, bool esta);
  bool estaEnPromo();
  float calcularDescuento();

  DTProducto getDataProducto();
  int getId();
  categoria getCat();
  string getDesc();
  int getCantStock();
  float getPrecio();

  virtual ~Producto();
};

#endif