#ifndef IVENTA_H
#define IVENTA_H

#include "promocion.h"
#include "usuario.h"
#include "IUsuario.h"

#include <string>
#include <set>
#include <map>

using namespace std;

class IVenta
{
public:
    virtual int getContador() = 0;
    virtual void avanzarContador() = 0;
    virtual void setContador() = 0;
    virtual int getContadorCompra() = 0;
    virtual void avanzarContadorCompra() = 0;
    virtual void setContadorCompra() = 0;
    virtual Usuario * getMemUsuario() = 0;
    virtual void setMemUsuario(string nickname) = 0;
    virtual Promocion * getMemPromocion() = 0;
    virtual void setMemPromocion(Promocion * prom) = 0;
    virtual Compra * getMemCompra() = 0;
    virtual void setMemCompra(Compra * compra) = 0;
    virtual map<int, Compra *> getCompra() = 0;



    virtual void crearProducto(string nicknameV, string nombreP, string descripcionP, float precioP, int cantStockP, categoria cat) = 0;
    virtual bool existeProducto(int id) = 0;
    virtual void crearPromocion(string nombre, string descripcion, float descuento, DTFecha fechaVencimiento) = 0;
    virtual void seleccionarProductoAProm(int prodId, int cantMinima) = 0;
    virtual Producto *seleccionarProductoPorId(int productosid) = 0;
    virtual set<DTProducto> listadoProductosNoEnPromo() = 0;
    virtual bool productoEnPromo(int id) = 0;
    virtual DTUsuario* infoPromocionVendedor (string nombre) = 0;
    virtual set<DTProducto> infoPromocionProductos(string nombre) = 0;
    virtual int cantidadMinimaPromo(string nombre, int id) = 0;
    virtual DTProducto dataDeProducto(Producto * prod) = 0;
    virtual string nombreVendedor(int id) = 0;
    //virtual enviarProducto()

    
    virtual void confirmarCrearPromocion(string nicknameV) = 0;

    virtual set<string> obtenerProdsPendEnvio(string nombreVendedor) = 0;
    virtual map<string, DTFecha> clientesConEnvioPend(string nombreProducto) = 0;

    virtual void crearCompra(string nickname) = 0;
    virtual set<DTProducto> listadoProductos() = 0;
    virtual set<DTPromocion> listadoPromociones() = 0;
    virtual bool productoEnCompra(int id) = 0;
    virtual bool cantidadValida(int id, int cantidad) = 0;
    virtual void agregarACompra(int id, int cantidad) = 0;
    virtual DTCompra detallesCompra() = 0;
    //virtual void confirmarCompra() = 0;


    virtual ~IVenta() {};
};

#endif
