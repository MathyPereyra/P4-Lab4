#include "../include/compra_producto.h"
#include "../include/promocion.h"

Compra_Producto::Compra_Producto() {}

Compra_Producto::Compra_Producto(int cantidad, bool envio) : cantidad(cantidad), envio(envio) {}

void Compra_Producto::agregarProducto(Producto *prod)
{
    int id = prod->getId();
    this->productosEnCompra = prod;
    prod->agregadoACompra(this);
}

float Compra_Producto::sumaPrecios(DTFecha fechaActual)
{
    float suma = 0;
    Producto *productos = this->getProductosEnCompra();
    bool cuestion = productos->getCantStock() >= this->getCantidad();
    productos->restaDeStock(this->getCantidad());
    bool habilPromo = false;
    if (cuestion)
    {
        if (productos->getPromo() != NULL)
        {
            Promocion *promo = productos->getPromo();
            bool habilPromo = promo->habilPromo(productos, fechaActual, this->getCantidad());
            if (habilPromo)
            {
                return suma = (productos->getPrecio() * this->getCantidad()) * (1 - promo->getDescuento() / 100);
            }
        }
        return suma = productos->getPrecio() * this->getCantidad(); // a priori falta la prom
    }
    else
    {
        cout << "wtf";
        return -1;
    }
}

Producto *Compra_Producto::getProductosEnCompra()
{
    return this->productosEnCompra;
}

int Compra_Producto::getCantidad()
{
    return this->cantidad;
}

bool Compra_Producto::getEnvio()
{
    return this->envio;
}

DTProducto Compra_Producto::getDatosProductos()
{
    return this->productosEnCompra->getDataProducto();
}
