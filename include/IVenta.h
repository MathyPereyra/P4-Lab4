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
    virtual void crearPromocion(string nombre, string descripcion, float descuento, DTFecha fechaVencimiento) = 0;
    virtual void setDP(string nombre, string descripcion, float descuento, DTFecha fechaVencimiento) = 0;
    virtual set<DTProducto> listarProductosNoEnPromo(string nickname) = 0;
    virtual void seleccionarProducto(set<int> productosid, int cantMinima) = 0;
    virtual void confirmarCrearPromocion() = 0;
    virtual void crearCompra(string nickname) = 0;
    virtual set<DTProducto> listadoProductos() = 0;
    virtual void agregarACompra(int idproducto, int cantidad) = 0;
    //aca no pusimos datadetallecompra al final
    virtual DTCompra detalllesCompra() = 0;
    virtual void confirmarCompra() = 0;

    virtual ~IVenta(){};
};

#endif