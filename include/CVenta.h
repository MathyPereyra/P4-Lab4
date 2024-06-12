#ifndef CVENTA_H
#define CVENTA_H

#include <string>
#include <set>

#include "datatypes.h"
#include "usuario.h"

using namespace std;

class ControladorVenta : public IVenta 
{
private:
    static ControladorVenta * instancia;
    ControladorVenta();
    map<integer, Compra *> compras;
    //aca es set o map porque no se identifican las notificaciones.
    set<Promocion> conjunto2;
 

public:
    static ControladorVenta * getInstancia();

// Operaciones externas

    void crearPromocion(string nombre, string descripcion, float descuento, DTFecha fechaVencimiento);
    DTPromocion setDP(string nombre, string descripcion, float descuento, DTFecha fechaVencimiento);
    set<DTProducto> listarProductosNoEnPromo(string nickname);
    void seleccionarProducto(set<integer> productosid, integer cantMinima);
    void confirmarCrearPromocion();
    void crearCompra(string nickname);
    set<DTProducto> listadoProductos();
    void agregarACompra(integer idproducto, integer cantidad);
    //aca no pusimos datadetallecompra al final
    DTCompra detalllesCompra();
    void confirmarCompra();

    // Operaciones internas (no se si el {} va o no)

    virtual ~ControladorVenta(){};
};

#endif