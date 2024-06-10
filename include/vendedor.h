#ifndef VENDEDOR_H
#define VENDEDOR_H

#include <string>
#include <set>
#include <map>

#include "usuario.h"
#include "datatypes.h"
#include "observer.h"

using namespace std;

class Vendedor : public Usuario
{
private:
  string codigoRUT;
  set<producto> productos;

public:
  Vendedor(string codRUT);
  getProductosNoEnPromo();
  seleccionarProductos(Integer id);
  agregarSuscriptor();
  eliminarSuscriptor();
  notificarSuscriptores();
  estaSuscrito(String nombre);
  DTUsuario getDatos();
  set<producto> getProductos();
  string getCodigoRut();
  
  virtual ~Vendedor();
};

#endif
