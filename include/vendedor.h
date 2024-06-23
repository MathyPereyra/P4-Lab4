#ifndef VENDEDOR_H
#define VENDEDOR_H

#include "datatypes.h"
#include "notificacion.h"
#include "observer.h"
// #include "producto.h"
#include "usuario.h"
#include <string>
#include <set>
#include <map>

using namespace std;

class Producto;
class Notificacion;

class Vendedor : public Usuario
{
private:
  string codigoRUT;
  map<int, Producto *> productos;
  map<string, Promocion *> promociones;
  map<string, IObserver *> suscriptores;
  void notificarSuscriptores(Notificacion *noti);

  // set<IObserver> suscriptores;

public:
  Vendedor(string nickname, string contrasena, DTFecha fechaNac, string codigoRUT);

  // set<DTIdNProducto> getProductosNoEnPromo();
  void seleccionarProducto(int id);

  void agregarProd(Producto *prod);
  // tal vez tendria q ser clietne no usuario
  void agregarSuscriptor(IObserver *o);
  void eliminarSuscriptor(IObserver *usuario);
  bool estaSuscrito(string nickname);
  void promoCreada(Notificacion *noti);

  DTVendedor *getDatosVendedor();
  DTUsuario *getDatosUsuario();
  set<DTComentario> listadoComentarioUsuario();
  string getNickname();
  string getContrasena();
  DTFecha getFecha();
  map<int, Producto *> getProductos();
  map<string, Promocion *> getPromociones();
  void agregarProm(Promocion *prom);
  void agregarProdAProm();
  void crearCompra(Compra *compra);

  map<int, Comentario *> getComentarios();
  void agregarComentario(int id, Comentario *comentario);
  // set<IObserver> getSuscriptores();
  string getCodigoRUT();

  virtual ~Vendedor(){};
};

#endif
