#ifndef CLIENTE_H
#define CLIENTE_H

#include <string>
#include <set>
#include <map>

#include "usuario.h"
#include "datatypes.h"
#include "observer.h"
#include "producto.h"

using namespace std;

class Notificacion 
{
private:
  string nicknameV;
  string nombreProm;
  set<Producto> productos;

public:
  Notificacion(string nicknameV, string nombreProm, set<Producto> productos);
  string getNicknameV();
  string getNombreProm();
  set<Producto> getProductos();

  virtual ~Notificacion();
};

#endif