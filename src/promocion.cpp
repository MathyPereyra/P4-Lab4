#include "../include/promocion.h"


Promocion::Promocion(string nombre, string descripcion, float descuento, DTFecha fechaVencimiento, Vendedor * vendedor)
 : nombre(nombre), descripcion(descripcion), descuento(descuento), fechaVencimiento(fechaVencimiento), vendedor(vendedor) {}


string Promocion::getNombre()
{
    return this->nombre;
};


string Promocion::getDescripcion()
{
    return this->descripcion;
};
  

float Promocion::getDescuento()
{
    return this->descuento;
};
  

Vendedor * Promocion::getVendedor()
{
    return this->vendedor;
};


DTFecha Promocion::getFechaVen()
{
    return this->fechaVencimiento;
};
  

set<Producto_Promocion*> Promocion::getProdProms()
{
    return this->prodProms;
};


bool Promocion::habilPromo(Producto * producto, DTFecha fechaActual, int cantidadCompra)
{
    bool cantidadValida = false;
    bool expirado = fechaActual >= this->getFechaVen();
    for (Producto_Promocion * prodProm : this->getProdProms())
    {
        if(prodProm->getProducto() == producto)
        {
            cantidadValida = prodProm->getCantidadMinima() < cantidadCompra;
            break;
        }
    }
    if (!expirado && cantidadValida)
    {
        return true;
    }
    return false;
}


void Promocion::agregarProdProm(Producto_Promocion * prodProm)
{
    this->prodProms.insert(prodProm);
}
