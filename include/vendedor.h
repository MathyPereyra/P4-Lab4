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
  set<Producto> productos;
  set<Promocion> promociones;

public:
  Vendedor(string codRUT);
  getProductosNoEnPromo();
  seleccionarProductos(int id);
  agregarSuscriptor();
  eliminarSuscriptor();
  notificarSuscriptores();
  estaSuscrito(string nombre);
  DTVendedor getDatos();

  string getNickname();
  string getContrasena();
  DTFecha getFecha();
  set<Producto> getProductos();
  set<Promocion> getPromociones();
  set<Comentario> getComentarios();
  string getCodigoRut();
  
  virtual ~Vendedor();
};

#endif
