#ifndef PROMOCION_H
#define PROMOCION_H

#include <string>
#include <set>
#include <map>

#include "usuario.h"
#include "datatypes.h"
#include "observer.h"

using namespace std;

class Producto_Promocion 
{
private:
  integer cantidadMinima;
  set<Producto> productos;

public:
  agregarProd(Producto prod);
  set<DTProducto> getProdEnProm();
  integer getCantidadMinima();

  integer getCantidadMinima();
  set<Producto> getProductos();

  virtual ~Producto_Promocion();
};

#endif