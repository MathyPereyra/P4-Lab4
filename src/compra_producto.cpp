#include "../include/compra_producto.h"


Compra_Producto::Compra_Producto(){}


Compra_Producto::Compra_Producto(int cantidad, bool envio) : cantidad(cantidad), envio(envio) {}


void Compra_Producto::agregarProducto(Producto * prod)
{
    int id = prod->getId();
    this->productosEnCompra = prod;
    prod->agregadoACompra();
}


float Compra_Producto::sumaPrecios()
{
    DTFecha fechaActual = DTFecha(9,9,9);
    float suma = 0;
    Producto * productos = this->getProductosEnCompra();
    if(productos->restaDeStock(this->getCantidad()))
    { 
        Promocion * promo = productos->getPromo();
        bool habilPromo = promo->habilPromo(productos, fechaActual, this->getCantidad());

        if(habilPromo)
        {
            return suma = (productos->getPrecio() * this->getCantidad()) * promo->getDescuento();
        }
        return suma = productos->getPrecio() * this->getCantidad(); // a priori falta la prom
    }
    else return -1;
}

Producto * Compra_Producto::getProductosEnCompra()
{
    return this->productosEnCompra;
}


int Compra_Producto::getCantidad()
{
    return this->cantidad;
}