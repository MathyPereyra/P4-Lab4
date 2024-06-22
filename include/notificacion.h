#ifndef NOTIFICACION_H
#define NOTIFICACION_H

#include "producto.h"

#include <string>
#include <set>
#include <map>

using namespace std;

class Notificacion 
{
private:
  string nicknameV;
  string nombreProm;
  map<int, Producto*> productos;

public:
  Notificacion();
  Notificacion(string nicknameV, string nombreProm, map<int, Producto*> productos);
  
  string getNicknameV();
  string getNombreProm();
  map<int, Producto*> getProductos();

  virtual ~Notificacion(){};
};

#endif