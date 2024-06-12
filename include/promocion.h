#ifndef PROMOCION_H
#define PROMOCION_H

#include <string>
#include <set>
#include <map>

#include "usuario.h"
#include "datatypes.h"
#include "observer.h"

using namespace std;

class Promocion 
{
private:
  string nombre;
  string descripcion;
  float descuento;
  DTFecha fechaVencimiento;
  set<Producto-Promocion> prod-proms;

public:
  Promocion(string nombre, string descripcion, float descuento, DTFecha fechaVencimiento);
  void agergarAPromocion(integer id);
  void getProdEnProm();
  string getNombre();
  string getDescripcion();
  float getDesc();
  DTFecha getFechaVen();
  set<Producto-Promocion> getProdProms();

  virtual ~Promocion();
};

#endif