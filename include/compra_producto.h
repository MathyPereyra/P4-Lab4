#ifndef COMPRA_PRODUCTO_H
#define COMPRA_PRODUCTO_H

#include "producto.h"
#include <string>
#include <set>
#include <map>



using namespace std;

class Compra_Producto
{
private:
  bool envio;
  int cantidad;
  Producto * productosEnCompra;

public:
  Compra_Producto();
  Compra_Producto(int cantidad, bool envio);

  void agregarProducto(Producto * prod);
  float sumaPrecios();
  DTProducto getDatosProductos();

  bool getEnvio();
  int getCantidad();
  Producto * getProductosEnCompra();

  virtual ~Compra_Producto(){};
};

#endif
