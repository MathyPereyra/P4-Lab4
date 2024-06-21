#ifndef COMPRA_H
#define COMPRA_H

#include <string>
#include <set>
#include <map>

#include "usuario.h"
#include "datatypes.h"
#include "compra_producto.h"
#include "producto.h"

using namespace std;

class Compra
{
private:
  DTFecha fecha;
  float montoTotal;
  set<Compra_Producto*> com_Prods;
  int id;

public:
  Compra();
  Compra(DTFecha fecha, float montoTotal, int id);

  void agregarACompra(Producto * prod, int id);
  bool productoEnCompra();
  DTCompra infoCompra();

  // void setId(integer id);
  int getId();
  DTFecha getFecha();
  float getMontoTotal();
  set<Compra_Producto*> getCompProd();
  void setId(int);

  virtual ~Compra(){};
};

#endif
