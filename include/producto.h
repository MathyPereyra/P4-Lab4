#ifndef PRODUCTO_H
#define PRODUCTO_H

#include "datatypes.h"
// #include "promocion.h"

#include <string>
#include <set>
#include <map>

using namespace std;

class Comentario;
class Compra_Producto;
class Promocion;

class Producto
{
private:
  int id;
  categoria cat;
  string nombre;
  string descripcion;
  int cantStock;
  float precio;
  Promocion *promo;
  Compra_Producto *compProd;
  map<int, Comentario *> comentarios;

  // Habria que agregar bidireccionalidad en la asociacion Producto --- Producto_Promocion para acceder al valor del descuento

public:
  Producto(int id, categoria cat, string nombre, string descripcion, int cantStock, float precio, Promocion *promo, Compra_Producto *compProd);

  bool estaEnPromo();
  bool estaEnCompra();
  Compra_Producto *getCompProd();

  float calcularDescuento();

  map<int, Comentario *> listadoComentarios();

  void agregarComentario(int id, Comentario *comentario);

  void restaDeStock(int cantidad);
  DTProducto getDataProducto();
  int getId();
  string getNombre();
  categoria getCat();
  string getDesc();
  int getCantStock();
  Promocion *getPromo();
  float getPrecio();

  void agregadoAPromo(Promocion *promo);
  void agregadoACompra(Compra_Producto *compProd);

  virtual ~Producto(){};
};

#endif
