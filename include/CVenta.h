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

using namespace std;

class ControladorVenta : public IVenta 
{
private:
    static ControladorVenta * instancia;
    ControladorVenta();
    map<int, Compra *> compras;
    //aca es set o map porque no se identifican las notificaciones.
    set<Promocion> conjunto2;
 

public:
    static ControladorVenta * getInstancia();

// Operaciones externas

    void crearPromocion(string nombre, string descripcion, float descuento, DTFecha fechaVencimiento);
    DTPromocion setDP(string nombre, string descripcion, float descuento, DTFecha fechaVencimiento);
    set<DTProducto> listarProductosNoEnPromo(string nickname);
    void seleccionarProducto(set<int> productosid, int cantMinima);
    void confirmarCrearPromocion();
    void crearCompra(string nickname);
    set<DTProducto> listadoProductos();
    void agregarACompra(int idproducto, int cantidad);
    //aca no pusimos datadetallecompra al final
    DTCompra detalllesCompra();
    void confirmarCompra();

    // Operaciones internas (no se si el {} va o no)

    virtual ~ControladorVenta(){};
};

#endif