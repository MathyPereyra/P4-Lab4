#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <string>
#include <set>
#include <map>

#include "datatypes.h"
//#include "vendedor.h"
//#include "comentario.h"

using namespace std;

class Comentario;
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
  Promocion * promo; 
  bool enCompra;  // Al crearlo esta = false, si el producto es agregado a alguna promocion esta = true
  map<int, Comentario *> comentarios;

  // Habria que agregar bidireccionalidad en la asociacion Producto --- Producto_Promocion para acceder al valor del descuento

public:
  Producto(int id, categoria cat, string nombre, string descripcion, int cantStock, float precio, Promocion * promo, bool enCompra);
  
  
  bool estaEnPromo();
  bool estaEnCompra();
  
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
  Promocion * getPromo();
  float getPrecio();
  
  void agregadoAPromo(Promocion * promo);
  void agregadoACompra();

  virtual ~Producto(){};
};

#endif
