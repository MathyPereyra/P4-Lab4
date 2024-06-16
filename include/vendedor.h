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
#include "compra.h"

using namespace std;

class Vendedor : public Usuario
{
private:
  string codigoRUT;
  map<int, Producto *> productos;
  set<Promocion> promociones;
  // set<IObserver> suscriptores;

public:
  Vendedor(string nickname, string contrasena, DTFecha fechaNac, string codigoRUT);

  // set<DTIdNProducto> getProductosNoEnPromo();
  void seleccionarProducto(int id);

  void agregarProd(Producto *prod);
  void agregarSuscriptor();
  void eliminarSuscriptor();
  void notificarSuscriptores();
  bool estaSuscrito(string nombre);

  DTUsuario getDatosUsuario();
  set<DTComentario> listadoComentarioUsuario();
  string getNickname();
  string getContrasena();
  DTFecha getFecha();
  map<int, Producto *> getProductos();
  set<Promocion> getPromociones();
  map<int, Comentario *> getComentarios();
  // set<IObserver> getSuscriptores();
  string getCodigoRUT();

  virtual ~Vendedor(){};
};

#endif
