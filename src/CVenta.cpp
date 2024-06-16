#include "../include/CVenta.h"


void ControladorVenta::crearProducto(Vendedor * vendedor, string nombreP, string descripcionP, float precioP, int cantStockP, categoria cat)
{
    int id = this->getContador();
    this->avanzarContador();
    Producto* nuevo = new Producto(id, cat, nombreP, descripcionP, cantStockP, precioP, false);
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

void ControladorVenta::seleccionarProductoPorId()
{
    this->productos = 
}

set<DTProducto> ControladorVenta::listadoProductos()
{
    set<DTProducto> dataProductos;
    map<string, Producto *>::iterator it;
    for (it = this->productos.begin(); it != this->productos.end(); ++it)
    {
            dataProductos.insert(it->second->getDataProducto());
    }

    return dataProductos;
}

Producto* obtenerDatosProductoPorId(const int & id)
{
    map<int, Producto*>::iterator it = this->productos.find(id);
    if (it != this->productos.end()) {
        return it->second;
    }
    throw std::runtime_error("Producto no encontrado");
};

ControladorVenta * ControladorVenta::getInstancia() 
{
    if (instancia == nullptr)
        instancia = new ControladorVenta();
    return instancia;
};

void ControladorVenta::seleccionarProductoPorId()
{
    this->productos = 
}
