#include "../include/compra.h"
#include "../include/compra_producto.h"
using namespace std;

Compra::Compra() {}

Compra::Compra(DTFecha fechaCompra, float montoTotal, int id)
    : fecha(fechaCompra), montoTotal(montoTotal), id(id){};

void Compra::agregarACompra(Producto *prod, int cantidad)
{
    Compra_Producto *nuevoCP = new Compra_Producto(cantidad, false);
    nuevoCP->agregarProducto(prod);
    this->com_Prods.insert(nuevoCP);
};

//bool Compra::productoEnCompra(int id_prod)
//{
//    bool enCompra = false;
//    for (Compra_Producto * cp : this->com_Prods)
//    {
//        Producto *prod = cp->getProductosEnCompra();
//        enCompra = setProductos.count(id_prod) || enCompra;
//    }
//    return enCompra;
//};

int Compra::getId()
{
    return this->id;
};

DTFecha Compra::getFecha()
{
    return this->fecha;
};

float Compra::getMontoTotal()
{
    return this->montoTotal;
};

set<Compra_Producto *> Compra::getCompProd()
{
    return this->com_Prods;
}

void Compra::setId(int id)
{
    this->id = id;
};

DTCompra Compra::infoCompra()
{
    set<DTProducto> prods;
    set<Compra_Producto*> compProds = this->getCompProd();
    for (set<Compra_Producto*>::iterator it = compProds.begin(); it != compProds.end(); ++it)
    {
        DTProducto producto = (*it)->getProductosEnCompra()->getDataProducto();
        prods.insert(producto);
    }
    return DTCompra(this->getMontoTotal(), this->getFecha(), prods, this->getId());
}

void Compra::setMontoTotal(float monto)
{
    this->montoTotal = monto;
}
