#include "../include/CVenta.h"


void ControladorVenta::crearProducto(Vendedor *vendedor, string nombreP, string descripcionP, float precioP, int cantStockP, categoria cat)
{
    int id = this->getContador();
    this->avanzarContador();
    Producto *nuevo = new Producto(id, cat, nombreP, descripcionP, cantStockP, precioP, false);
    vendedor->agregarProd(nuevo);
    this->productos[id] = nuevo;
}

void ControladorVenta::setContador()
{
    this->contador = 0;
}

int ControladorVenta::getContador()
{
    return this->contador;
}

void ControladorVenta::avanzarContador()
{
    this->contador = this->contador + 1;
}


Usuario * ControladorVenta::getMemUsuario()
{
    return this->memUsuario;
}


void ControladorVenta::setMemUsuario(Usuario * usuario)
{
    this->memUsuario = usuario;
}


Promocion * ControladorVenta::getMemPromocion()
{
    return this->memPromocion;
}


void ControladorVenta::setMemPromocion(Promocion * prom)
{
    this->memPromocion = prom;
}




map<string, Promocion *> ControladorVenta::listadoPromociones()
{
    return this->promociones;
}


set<DTProducto> ControladorVenta::listadoProductos()
{
    set<DTProducto> dataProductos;
    map<int, Producto *>::iterator it;
    for (it = this->productos.begin(); it != this->productos.end(); ++it)
    {
        dataProductos.insert(it->second->getDataProducto());
    }

    return dataProductos;
}

Producto *ControladorVenta::seleccionarProductoPorId(int productoId)
{
    auto it = this->productos.find(productoId);
    if (it != this->productos.end())
    {
        return it->second;
    }
    return NULL;
}


void ControladorVenta::crearPromocion(string nombre, string descripcion, float descuento, DTFecha fechaVen)
{
    
    Usuario * usuario = getMemUsuario();
    Vendedor *vendedor = dynamic_cast<Vendedor *>(usuario);    
    
    Promocion * prom = new Promocion(nombre, descripcion, descuento, fechaVen, vendedor);


    vendedor->agregarProm(prom);
    this->promociones[nombre] = prom;

    this->setMemPromocion(prom);
}


void ControladorVenta::seleccionarProductoAProm(int id, int cantMinima)
{
    Promocion * prom = getMemPromocion();
    Producto_Promocion * prodProm = new Producto_Promocion(cantMinima);

    Producto * prod = this->seleccionarProductoPorId(id);

    prom->agregarProdProm(prodProm);
    prodProm->agregarProd(prod);
    prod->agregadoAPromo();

    //aca siguen las notis en un futuro
}


void ControladorVenta::confirmarCrearPromocion()
{
    delete this->memPromocion;
    delete this->memUsuario;
}



ControladorVenta *ControladorVenta::instancia = nullptr;


ControladorVenta::ControladorVenta(){};


ControladorVenta *ControladorVenta::getInstanciaVen()
{
    if (instancia == nullptr)
        instancia = new ControladorVenta();
    return instancia;
};
