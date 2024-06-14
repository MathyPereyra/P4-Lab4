#ifndef PROMOCION_H
#define PROMOCION_H

#include <string>
#include <set>
#include <map>

#include "datatypes.h"
#include "producto_promocion.h"
#include "observer.h"

using namespace std;

class Promocion 
{
private:
  string nombre;
  string descripcion;
  float descuento;
  DTFecha fechaVencimiento;
  set<Producto_Promocion> *prodProms;

public:
  Promocion(string nombre, string descripcion, float descuento, DTFecha fechaVencimiento);
  void agregarAPromocion(int id);
  set<DTProducto> getProdEnProm();
  
  string getNombre();
  string getDescripcion();
  float getDesc();
  DTFecha getFechaVen();
  set<Producto_Promocion> getProdProms();

  virtual ~Promocion();
};

#endif