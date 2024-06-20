#include "../include/CVenta.h"


void ControladorVenta::crearProducto(Vendedor *vendedor, string nombreP, string descripcionP, float precioP, int cantStockP, categoria cat)
{
    int id = this->getContador();
    this->avanzarContador();
    Producto *nuevo = new Producto(id, cat, nombreP, descripcionP, cantStockP, precioP, NULL, false);
    vendedor->agregarProd(nuevo);
    this->productos[id] = nuevo;
}

void ControladorVenta::setContador()
{
    this->contador = 1;
}

int ControladorVenta::getContador()
{
    return this->contador;
}

void ControladorVenta::avanzarContador()
{
    this->contador = this->contador + 1;
}


void ControladorVenta::setContadorCompra()
{
    this->contadorCompra = 1;
}

int ControladorVenta::getContadorCompra()
{
    return this->contadorCompra;
}

void ControladorVenta::avanzarContadorCompra()
{
    this->contadorCompra = this->contadorCompra + 1;
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


Compra * ControladorVenta::getMemCompra()
{
    return this->memCompra;
}


void ControladorVenta::setMemCompra(Compra * compra)
{
    this->memCompra = compra;
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
    map<int, Producto*>::iterator it = this->productos.find(productoId);
    if (it != this->productos.end()) {
        return it->second;
    }
    return nullptr;
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
    prod->agregadoAPromo(prom);

    //aca siguen las notis en un futuro
}


void ControladorVenta::confirmarCrearPromocion()
{
    delete this->memPromocion;
    delete this->memUsuario;
}


void ControladorVenta::crearCompra(Usuario * cliente)
{
    int id = this->getContadorCompra();
    this->avanzarContadorCompra();
    DTFecha fechaActual = DTFecha(0,0,0);

    Compra * compra = new Compra(fechaActual, 0, id);
    this->setMemCompra(compra);

    cliente->crearCompra(compra);
    this->compras[id] = compra;
}


bool ControladorVenta::agregarACompra(Producto * prod, int cantidad)
{
    Compra * compra = getMemCompra();
    if(prod->restaDeStock(cantidad))
    {
        compra->agregarACompra(prod, cantidad);
        cout << "andando agregar a compra ";
        return true;
    }
    return false;
}


DTCompra ControladorVenta::detallesCompra()
{
    set<DTProducto> dataProductos;
    DTFecha fechaActual = DTFecha(4,5,6);
    float sumaPrecios = 0;
    DTProducto  productos = DTProducto();
    Compra * compra = this->getMemCompra();
    for(Compra_Producto * it : compra->getCompProd())
    {
        sumaPrecios = it->sumaPrecios() + sumaPrecios;
        productos = it->getProductosEnCompra()->getDataProducto();
        dataProductos.insert(productos);
    }
    
    DTCompra dataCompra = DTCompra(sumaPrecios, fechaActual, dataProductos);
    return dataCompra;
}





ControladorVenta *ControladorVenta::instancia = nullptr;


ControladorVenta::ControladorVenta(){};


ControladorVenta *ControladorVenta::getInstanciaVen()
{
    if (instancia == nullptr)
        instancia = new ControladorVenta();
    return instancia;
};
