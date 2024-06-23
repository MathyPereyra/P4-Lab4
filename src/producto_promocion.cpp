#include "../include/producto_promocion.h"

Producto_Promocion::Producto_Promocion(int cantMinima) : cantidadMinima(cantMinima) {}

void Producto_Promocion::agregarProd(Producto *prod)
{
    this->producto = prod;
}

Producto *Producto_Promocion::getProducto()
{
    return this->producto;
}

int Producto_Promocion::getCantidadMinima()
{
    return this->cantidadMinima;
}
