#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <string>
#include <set>
#include <map>

#include "datatypes.h"
#include "observer.h"
//#include "vendedor.h"
//#include "comentario.h"

using namespace std;

class Comentario;

class Producto
{
private:
  int id;
  categoria cat;
  string nombre;
  string descripcion;
  int cantStock;
  float precio;
  bool estaEnProm; // Al crearlo esta = false, si el producto es agregado a alguna promocion esta = true
  bool enCompra;
  map<int, Comentario *> comentarios;

  // Habria que agregar bidireccionalidad en la asociacion Producto --- Producto_Promocion para acceder al valor del descuento

public:
  Producto(int id, categoria cat, string nombre, string descripcion, int cantStock, float precio, bool estaEnProm, bool enCompra);
  
  
  bool estaEnPromo();
  bool estaEnCompra();
  
  float calcularDescuento();

  map<int, Comentario *> listadoComentarios();
  
  void agregarComentario(int id, Comentario *comentario);
  
  DTProducto getDataProducto();
  int getId();
  string getNombre();
  categoria getCat();
  string getDesc();
  int getCantStock();
  
  float getPrecio();
  void agregadoAPromo();
  void agregadoACompra();

  virtual ~Producto(){};
};

#endif
