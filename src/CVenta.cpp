#include "../include/CVenta.h"
#include "../include/compra_producto.h"

void ControladorVenta::crearProducto(string nicknameV, string nombreP, string descripcionP, float precioP, int cantStockP, categoria cat)
{
    Usuario * vend = ControladorUsuario::getInstance()->obtenerUsuarioPorNickname(nicknameV);
    Vendedor* vendedor = dynamic_cast<Vendedor*>(vend);
    if (vendedor != NULL)
    {
        int id = this->getContador();
        this->avanzarContador();
        Producto *nuevo = new Producto(id, cat, nombreP, descripcionP, cantStockP, precioP, NULL, NULL);
        vendedor->agregarProd(nuevo);
        this->productos[id] = nuevo;
    }
}


bool ControladorVenta::existeProducto(int id)
{  
    Producto * prod = seleccionarProductoPorId(id);
    return prod != NULL;
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


void ControladorVenta::setMemUsuario(string nickname)
{   
    Usuario * usuario = ControladorUsuario::getInstance()->obtenerUsuarioPorNickname(nickname);
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

map<int, Compra *> ControladorVenta::getCompra()
{
    return this->compras;
}

set<DTPromocion> ControladorVenta::listadoPromociones()
{
    DTPromocion dataPromo;
    set<DTPromocion> dataPromos;
    map<string, Promocion *> promociones = this->promociones;
    for (map<string, Promocion*>::iterator it = promociones.begin(); it != promociones.end(); it++)
    {
        dataPromo = it->second->getDatosPromocion();
        dataPromos.insert(dataPromo);
    }
    return dataPromos;
}


set<DTProducto> ControladorVenta::listadoProductosNoEnPromo()
{
    Usuario * elfran = getMemUsuario();
    Vendedor * vendedor = dynamic_cast<Vendedor*>(elfran);

    set<DTProducto> productosNoEnPromo;
    map<int, Producto *> dataProductos = vendedor->getProductos();
    for (map<int, Producto *>::iterator it = dataProductos.begin(); it != dataProductos.end(); it++)
    {
        if (!it->second->estaEnPromo())
        {
            productosNoEnPromo.insert(it->second->getDataProducto());
        }
    }      
    return productosNoEnPromo;
}


int ControladorVenta::cantidadMinimaPromo(string nombre, int id)
{
    set<Producto_Promocion*> prodProms = this->promociones.find(nombre)->second->getProdProms();
    for(set<Producto_Promocion*>::iterator it = prodProms.begin(); it != prodProms.end(); ++it)
    {
        if ((*it)->getProducto()->getId() == id)
        {
            return (*it)->getCantidadMinima();
        }
    }

    return 001;
}


bool ControladorVenta::productoEnPromo(int id)
{
    set<DTProducto> productosNoEnPromo = this->listadoProductosNoEnPromo();
    for(set<DTProducto>::iterator iter = productosNoEnPromo.begin(); iter != productosNoEnPromo.end(); iter++)
    {
        if(iter->getId() == id) 
        {
            return true;
        }
        else 
        {
            return false;
        }
    }    
    return false;
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
    Producto * prod = this->seleccionarProductoPorId(id);

    Promocion * prom = getMemPromocion();

    Producto_Promocion * prodProm = new Producto_Promocion(cantMinima);


    prom->agregarProdProm(prodProm);
    prodProm->agregarProd(prod);
    prod->agregadoAPromo(prom);

    //aca siguen las notis en un futuro
}

DTProducto ControladorVenta::dataDeProducto(Producto * prod)
{
    DTProducto pe = DTProducto(prod->getId(), prod->getCat(), prod->getNombre(), prod->getDesc(), prod->getCantStock(), prod->getPrecio());
    return pe;
}

string ControladorVenta::nombreVendedor(int idProducto)
{
    string nicknameV;
    Producto * productoConsultado = this->seleccionarProductoPorId(idProducto);
    map<string, Usuario *> usuarios = ControladorUsuario::getInstance()->getMapaUsuarios("");
    map<string, Usuario *>::iterator it;
    for (it = usuarios.begin(); it != usuarios.end(); it++)
    {
        Vendedor *vendedor = dynamic_cast<Vendedor *>(it->second);
        if (vendedor == nullptr)
        {
            continue;
        }
        if (vendedor->getProductos().find(idProducto) != vendedor->getProductos().end() && vendedor->getProductos().find(idProducto)->second == productoConsultado)
        {
            nicknameV = vendedor->getNickname();
            break;
        }
    }
    return nicknameV;

}   

void ControladorVenta::confirmarCrearPromocion()
{

}


DTUsuario ControladorVenta::infoPromocionVendedor(string opcion)
{
    Promocion * promo = this->promociones.find(opcion)->second;
    return promo->getVendedor()->getDatosUsuario();
}


set<DTProducto> ControladorVenta::infoPromocionProductos(string opcion)
{
    Promocion * promo = this->promociones.find(opcion)->second;
    set<Producto_Promocion*> prodProms = promo->getProdProms();
    set<DTProducto> retorno;
    for (set<Producto_Promocion*>::iterator iter = prodProms.begin();  iter != prodProms.end(); iter++)
    {
        DTProducto dataProd = (*iter)->getProducto()->getDataProducto();
        retorno.insert(dataProd);
    }
    return retorno;
}




void ControladorVenta::crearCompra(string nickname)
{
    Usuario * client = ControladorUsuario::getInstance()->obtenerUsuarioPorNickname(nickname);
    Cliente * cliente = dynamic_cast<Cliente*>(client);
    int id = this->getContadorCompra();
    this->avanzarContadorCompra();
    DTFecha fechaActual = DTFecha(0,0,0);

    Compra * compra = new Compra(fechaActual, 0, id);
    this->setMemCompra(compra);

    cliente->crearCompra(compra);
    this->compras[id] = compra;
}


bool ControladorVenta::productoEnCompra(int id)
{
    Producto * prod = this->seleccionarProductoPorId(id);
    if (prod->getCompProd() == NULL || prod->getCompProd()->getProductosEnCompra() == prod)
        return true;
    else return false;
}


void ControladorVenta::agregarACompra(int id, int cantidad)
{
    Producto * prod = seleccionarProductoPorId(id);
    Compra * compra = getMemCompra();
    if(prod->getCantStock() >= cantidad)
    {
        compra->agregarACompra(prod, cantidad);
    }

}


bool ControladorVenta::cantidadValida(int id, int cantidad)
{
    Producto * prod = seleccionarProductoPorId(id);
    return prod->getCantStock() >= cantidad;
}


DTCompra ControladorVenta::detallesCompra()
{
    set<DTProducto> dataProductos;
    DTFecha fechaActual = DTFecha(4,5,6);
    float sumaPrecios = 0;
    DTProducto productos = DTProducto();
    Compra * compra = this->getMemCompra();
    
    for(Compra_Producto * it : compra->getCompProd())
    {
        sumaPrecios += it->sumaPrecios();
        productos = it->getProductosEnCompra()->getDataProducto();
        dataProductos.insert(productos);
    }
    
    DTCompra dataCompra = DTCompra(sumaPrecios, fechaActual, dataProductos);
    return dataCompra;
}


//set<string> ControladorVenta::obtenerProdsPendEnvio(string nombreVendedor)
//{   
//    Usuario *vendSelect = ControladorUsuario::getInstance()->obtenerUsuarioPorNickname(nombreVendedor);
//    Vendedor *vendedorSelect = dynamic_cast<Vendedor *>(vendSelect);
//    map<int, Producto*> prods = vendedorSelect->getProductos();    
//    set<string> productosPorEnviar;  
//    map<int, Compra *> compras = getCompra();
//    for(map<int, Compra*>::iterator itCompra = compras.begin(); itCompra != compras.end(); ++itCompra)
//    {
//        set<Compra_Producto*> products = itCompra->second->getCompProd();
//        for(set<Compra_Producto*>::iterator itProd = products.begin(); itProd != products.end(); ++itProd)
//        {
//            if(!(*itProd)->getEnvio() && (prods.find((*itProd)->getDatosProductos().getId()) != prods.end() ))
//            {
//                productosPorEnviar.insert((*itProd)->getDatosProductos().getNombre());
//            }
//        }
//    }
//    return productosPorEnviar;
//}
//
//map<string, DTFecha> ControladorVenta::clientesConEnvioPend(string nombreProducto)
//{
//    map<string, DTFecha> clientes;
//    map<string, Usuario *> usuarios = ControladorUsuario::getInstance()->getMapaUsuarios();
//    for(map<string, Usuario *>::iterator it = usuarios.begin(); it != usuarios.end(); ++it)
//    {
//        Cliente *cliente = dynamic_cast<Cliente *>(it->second);
//        if((cliente!=nullptr))
//        {
//            map<int, Compra*> comprasCli = cliente->getCompras();
//            for(map<int, Compra *>::iterator iter = comprasCli.begin(); iter != comprasCli.end(); ++iter)
//            {
//                set<Compra_Producto*> compras = iter->second->getCompProd();
//                    for(set<Compra_Producto *>::iterator iter3 = compras.begin(); iter3 != compras.end(); ++iter3){
//                        if(!(*iter3)->getEnvio())
//                        {
//                            clientes.insert({cliente->getNickname(), (*iter)->getFecha()});      
//                        }   
//                    }
//            }
//        }
//    }
//    return clientes;
//}

ControladorVenta *ControladorVenta::instancia = nullptr;


ControladorVenta::ControladorVenta(){};


ControladorVenta *ControladorVenta::getInstanciaVen()
{
    if (instancia == nullptr)
        instancia = new ControladorVenta();
    return instancia;
};
