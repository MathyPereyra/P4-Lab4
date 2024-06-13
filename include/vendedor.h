#ifndef VENDEDOR_H
#define VENDEDOR_H

#include <string>
#include <set>
#include <map>

#include "usuario.h"
#include "datatypes.h"
#include "observer.h"
#include "producto.h"
#include "promocion.h"

using namespace std;

class Vendedor : public Usuario
{
private:
  string codigoRUT;
  set<Producto> *productos;
  set<Promocion> *promociones;
  set<IObserver> *suscriptores;

public:
  Vendedor(string nickname, string contrasena, DTFecha fechaNac, string codigoRUT);
  
  set<DTIdNProducto>  getProductosNoEnPromo();
  void seleccionarProducto(int id);

  void agregarSuscriptor();
  void eliminarSuscriptor();
  void notificarSuscriptores();
  bool estaSuscrito(string nombre);
  
  DTVendedor getDatos();
  string getNickname();
  string getContrasena();
  DTFecha getFecha();
  set<Producto> getProductos();
  set<Promocion> getPromociones();
  set<Comentario> getComentarios();
  set<IObserver> getSuscriptores();
  string getCodigoRUT();
  
  virtual ~Vendedor();
};

#endif
