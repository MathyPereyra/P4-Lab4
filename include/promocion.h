#ifndef PROMOCION_H
#define PROMOCION_H

#include "datatypes.h"
#include "producto_promocion.h"
#include "vendedor.h"

#include <string>
#include <set>
#include <map>

using namespace std;

class Promocion
{
private:
  string nombre;
  string descripcion;
  float descuento;
  DTFecha fechaVencimiento;
  set<Producto_Promocion *> prodProms;
  Vendedor *vendedor;

public:
  Promocion();
  Promocion(string nombre, string descripcion, float descuento, DTFecha fechaVencimiento, Vendedor *vendedor);

  void agregarAPromocion(int id);
  set<DTProducto> getProdEnProm();

  string getNombre();
  string getDescripcion();
  float getDescuento();
  Vendedor *getVendedor();
  DTFecha getFechaVen();
  set<Producto_Promocion *> getProdProms();
  DTPromocion getDatosPromocion();

  bool habilPromo(Producto *producto, DTFecha fechaActual, int cantidadCompra);
  void agregarProdProm(Producto_Promocion *prodProm);

  virtual ~Promocion(){};
};

#endif
