#ifndef PRODUCTO_PROMOCION_H
#define PRODUCTO_PROMOCION_H

// #include "producto.h"

#include <string>
#include <set>
#include <map>

using namespace std;

class Producto;

class Producto_Promocion 
{
private:
  int cantidadMinima;
  Producto* producto;

public:

  Producto_Promocion();
  Producto_Promocion(int cantMin);

  void agregarProd(Producto * prod);
  set<Producto> getProdEnProm();

  int getCantidadMinima();
  Producto* getProducto();

  virtual ~Producto_Promocion(){};
};

#endif