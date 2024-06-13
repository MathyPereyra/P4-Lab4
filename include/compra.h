#ifndef PROMOCION_H
#define PROMOCION_H

#include <string>
#include <set>
#include <map>

#include "usuario.h"
#include "datatypes.h"
#include "observer.h"

using namespace std;

class Compra 
{
private:
  DTFecha fecha;
  float montoTotal;
  set<Compra_Producto> com_Prods;
  integer id;

public:
  Compra(DTFecha fecha, float montoTotal, set<Compra_Producto> com_Prod, integer id);
  agregarACompra(Producto prod, integer id);
  bool productoEnCompra();
  DTCompra infoCompra();
  
  //void setId(integer id);
  integer getId();
  DTFecha getFecha();
  float getMontoTotal();
  set<Compra_Producto> getCompProd();
  virtual ~Compra();
};

#endif