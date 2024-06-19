#ifndef CVENTA_H
#define CVENTA_H

#include <string>
#include <set>
#include <map>

#include "datatypes.h"
#include "usuario.h"
#include "compra.h"
#include "IVenta.h"
#include "promocion.h"
#include "vendedor.h"
#include "producto.h"

using namespace std;

class ControladorVenta : public IVenta
{
private:
    static ControladorVenta *instancia;
    ControladorVenta();
    map<int, Compra *> compras;
    // aca es set o map porque no se identifican las notificaciones.
    set<Promocion> conjunto2;
    map<int, Producto *> productos;
    map<string, Promocion *> promociones;
    Usuario * memUsuario;
    Promocion * memPromocion;
    int contador;

public:
   static ControladorVenta *getInstanciaVen();
   void setContador();
   int getContador();
   void avanzarContador();

   Usuario * getMemUsuario();
   void setMemUsuario(Usuario * usuario);
   Promocion* getMemPromocion();
   void setMemPromocion(Promocion * prom);


   map<string, Promocion *> listadoPromociones();
   // Operaciones externas
   void crearProducto(Vendedor *nicknameV, string nombreP, string descripcionP, float precioP, int cantStockP, categoria cat);
   void crearPromocion(string nombre, string descripcion, float descuento, DTFecha fechaVencimiento);
 //  void setDP(string nombre, string descripcion, float descuento, DTFecha fechaVencimiento);
 //  set<DTProducto> listarProductosNoEnPromo(string nickname);
   void seleccionarProductoAProm(int prodId, int cantMinima);
   Producto *seleccionarProductoPorId(int productosid);
   void confirmarCrearPromocion();
 //  void crearCompra(string nickname);
   set<DTProducto> listadoProductos();
  //  void agregarACompra(int idproducto, int cantidad);
   // aca no pusimos datadetallecompra al final
   DTCompra detallesCompra();
 //  void confirmarCompra();
   // Operaciones internas (no se si el {} va o no)
    virtual ~ControladorVenta(){};
};

#endif
