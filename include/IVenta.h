#ifndef IVENTA_H
#define IVENTA_H

#include <string>
#include <set>
#include <map>

#include "usuario.h"
#include "datatypes.h"
#include "observer.h"

using namespace std;

class IVenta 
{
public:
    virtual void crearPromocion(string nombre, string descripcion, float descuento, DTFecha fechaVencimiento);
    virtual DTPromocion setDP(string nombre, string descripcion, float descuento, DTFecha fechaVencimiento);
    virtual set<DTProducto> listarProductosNoEnPromo(string nickname);
    virtual void seleccionarProducto(set<integer> productosid, integer cantMinima);
    virtual void confirmarCrearPromocion();
    virtual void crearCompra(string nickname);
    virtual set<DTProducto> listadoProductos();
    virtual void agregarACompra(integer idproducto, integer cantidad);
    //aca no pusimos datadetallecompra al final
    virtual DTCompra detalllesCompra();
    virtual void confirmarCompra();

    virtual ~Venta(){};
};