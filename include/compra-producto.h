#ifndef PROMOCION_H
#define PROMOCION_H

#include <string>
#include <set>
#include <map>

#include "usuario.h"
#include "datatypes.h"
#include "observer.h"

using namespace std;

class Compra_Producto
{
private:
  bool envio;
  integer cantidad;
  set<Producto> productosEnCompra;

public:
  agregarProd(Producto prod);
  float sumaPrecios();
  DTProducto getDatosProductos();
  
  bool getEnvio();
  integer getCantidad();
  set<Producto> getProductos();

  virtual ~Compra();
};

#endif