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


void Promocion::agregarProdProm(Producto_Promocion * prodProm)
{
    this->prodProms.insert(prodProm);
}
