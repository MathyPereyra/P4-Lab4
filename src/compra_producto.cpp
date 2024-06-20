#include "../include/compra_producto.h"


Compra_Producto::Compra_Producto(){}


Compra_Producto::Compra_Producto(int cantidad, bool envio) : cantidad(cantidad), envio(envio) {}


void Compra_Producto::agregarProducto(Producto * prod)
{
    int id = prod->getId();
    this->productosEnCompra[id] = prod;
    prod->agregadoACompra();
}


float Compra_Producto::sumaPrecios()
{
    float suma = 0;
    map<int, Producto*> productos = this->getProductosEnCompra();
    for(map<int, Producto*>::iterator iter = productos.begin(); iter != productos.end(); iter++)
    {
        suma = suma + iter->second->getPrecio();
    }    
}

map<int, Producto*> Compra_Producto::getProductosEnCompra()
{
    return this->productosEnCompra;
}


int Compra_Producto::getCantidad()
{
    return this->cantidad;
}