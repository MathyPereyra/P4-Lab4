#ifndef PRODUCTO_PROMOCION_H
#define PRODUCTO_PROMOCION_H

#include <string>
#include <set>
#include <map>

#include "usuario.h"
#include "datatypes.h"
#include "observer.h"
#include "producto.h"

using namespace std;

class Producto_Promocion 
{
private:
  int cantidadMinima;
  Producto* producto;

public:

  Producto_Promocion();
  Producto_Promocion(int cantMin);

  void agregarProd(Producto * prod);
  set<DTProducto> getProdEnProm();

  int getCantidadMinima();
  Producto* getProducto();

  virtual ~Producto_Promocion(){};
};

#endif