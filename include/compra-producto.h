#ifndef PROMOCION_H
#define PROMOCION_H

#include <string>
#include <set>
#include <map>

#include "usuario.h"
#include "datatypes.h"
#include "observer.h"
#include "producto.h"

using namespace std;

class Compra_Producto
{
private:
  bool envio;
  int cantidad;
  set<Producto> productosEnCompra;

public:
  void agregarProd(Producto prod);
  float sumaPrecios();
  DTProducto getDatosProductos();
  
  bool getEnvio();
  int getCantidad();
  set<Producto> getProductos();

  virtual ~Compra_Producto();
};

#endif