#ifndef PROMOCION_H
#define PROMOCION_H

#include <string>
#include <set>
#include <map>

#include "usuario.h"
#include "datatypes.h"
#include "observer.h"
#include "compra-producto.h"
#include "producto.h"

using namespace std;

class Compra 
{
private:
  DTFecha fecha;
  float montoTotal;
  set<Compra_Producto> *com_Prods;
  int id;

public:
  Compra(DTFecha fecha, float montoTotal, set<Compra_Producto> com_Prod, int id);

  agregarACompra(Producto prod, int id);
  bool productoEnCompra();
  DTCompra infoCompra();
  
  //void setId(integer id);
  int getId();
  DTFecha getFecha();
  float getMontoTotal();
  set<Compra_Producto> getCompProd();

  virtual ~Compra();
};

#endif