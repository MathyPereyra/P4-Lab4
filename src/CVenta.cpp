#include "../include/CVenta.h"
#include "../include/compra_producto.h"
#include "../include/CFecha.h"
#include <cstddef>

void ControladorVenta::crearProducto(string nicknameV, string nombreP, string descripcionP, float precioP, int cantStockP, categoria cat)
{
    Usuario *vend = ControladorUsuario::getInstance()->obtenerUsuarioPorNickname(nicknameV);
    Vendedor *vendedor = dynamic_cast<Vendedor *>(vend);
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
    Producto *prod = seleccionarProductoPorId(id);
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

Usuario *ControladorVenta::getMemUsuario()
{
    return this->memUsuario;
}

void ControladorVenta::setMemUsuario(string nickname)
{
    Usuario *usuario = ControladorUsuario::getInstance()->obtenerUsuarioPorNickname(nickname);
    this->memUsuario = usuario;
}

Promocion *ControladorVenta::getMemPromocion()
{
    return this->memPromocion;
}

void ControladorVenta::setMemPromocion(Promocion *prom)
{
    this->memPromocion = prom;
}

Compra *ControladorVenta::getMemCompra()
{
    return this->memCompra;
}

void ControladorVenta::setMemCompra(Compra *compra)
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
    for (map<string, Promocion *>::iterator it = promociones.begin(); it != promociones.end(); it++)
    {
        dataPromo = it->second->getDatosPromocion();
        dataPromos.insert(dataPromo);
    }
    return dataPromos;
}

set<DTProducto> ControladorVenta::listadoProductosNoEnPromo()
{
    Usuario *elfran = getMemUsuario();
    Vendedor *vendedor = dynamic_cast<Vendedor *>(elfran);

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
    set<Producto_Promocion *> prodProms = this->promociones.find(nombre)->second->getProdProms();
    for (set<Producto_Promocion *>::iterator it = prodProms.begin(); it != prodProms.end(); ++it)
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
    for (set<DTProducto>::iterator iter = productosNoEnPromo.begin(); iter != productosNoEnPromo.end(); iter++)
    {
        if (iter->getId() == id)
        {
            return false;
            break;
        }
    }
    return true;
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
    map<int, Producto *>::iterator it = this->productos.find(productoId);
    if (it != this->productos.end())
    {
        return it->second;
    }
    return nullptr;
}

void ControladorVenta::crearPromocion(string nombre, string descripcion, float descuento, DTFecha fechaVen)
{

    Usuario *usuario = getMemUsuario();
    Vendedor *vendedor = dynamic_cast<Vendedor *>(usuario);

    Promocion *prom = new Promocion(nombre, descripcion, descuento, fechaVen, vendedor);

    vendedor->agregarProm(prom);
    this->promociones[nombre] = prom;

    this->setMemPromocion(prom);
}

void ControladorVenta::seleccionarProductoAProm(int id, int cantMinima)
{
    Producto *prod = this->seleccionarProductoPorId(id);

    Promocion *prom = getMemPromocion();

    Producto_Promocion *prodProm = new Producto_Promocion(cantMinima);

    prom->agregarProdProm(prodProm);
    prodProm->agregarProd(prod);
    prod->agregadoAPromo(prom);

    // aca siguen las notis en un futuro
}

void ControladorVenta::confirmarCrearPromocion(string nicknameV)
{
    Promocion *prom = this->getMemPromocion();
    string nombreProm = prom->getNombre();

    map<int, Producto *> prods;
    set<Producto_Promocion *>::iterator it;
    set<Producto_Promocion *> prodProms = prom->getProdProms();
    for (it = prodProms.begin(); it != prodProms.end(); ++it)
    {
        if (*it == NULL)
        {
            cout << "it null";
            continue;
        }
        if ((*it)->getProducto() == NULL)
            cout << "producto null";
        prods[(*it)->getProducto()->getId()] = (*it)->getProducto();
    }

    Notificacion *noti = new Notificacion(nicknameV, nombreProm, prods);

    Usuario *vededor = ControladorUsuario::getInstance()->obtenerUsuarioPorNickname(nicknameV);
    Vendedor *vendedor = dynamic_cast<Vendedor *>(vededor);
    vendedor->promoCreada(noti);
}

DTProducto ControladorVenta::dataDeProducto(Producto *prod)
{
    DTProducto pe = DTProducto(prod->getId(), prod->getCat(), prod->getNombre(), prod->getDesc(), prod->getCantStock(), prod->getPrecio());
    return pe;
}

set<DTProducto> ControladorVenta::getDatosProductosVendedor(string nicknameV)
{
    Usuario *user = ControladorUsuario::getInstance()->obtenerUsuarioPorNickname(nicknameV);
    Vendedor *vendedor = dynamic_cast<Vendedor *>(user);
    set<DTProducto> dataProds;
    map<int, Producto*> mapProds= vendedor->getProductos();
    for (map<int, Producto *>::iterator it = mapProds.begin(); it != mapProds.end(); it++)
    {
        DTProducto dataProd = it->second->getDataProducto();
        dataProds.insert(dataProd);
    }
    return dataProds;
}

set<DTCompra> ControladorVenta::getDatosCompraRealizadaCliente(string nicknameC)
{
    Usuario *user = ControladorUsuario::getInstance()->obtenerUsuarioPorNickname(nicknameC);
    Cliente *cliente = dynamic_cast<Cliente *>(user);
    set<DTCompra> dataCompras;
    map<int, Compra *> compras = cliente->getCompras();

    for (map<int, Compra *>::iterator it = compras.begin(); it != compras.end(); it++)
    {
        DTCompra dataCompra = it->second->infoCompra();
        dataCompras.insert(dataCompra);
    }
    return dataCompras;
}

set<DTPromocion> ControladorVenta::getDatosPromocionVigentesVendedor(string nicknameV)
{
    Usuario *user = ControladorUsuario::getInstance()->obtenerUsuarioPorNickname(nicknameV);
    Vendedor *vendedor = dynamic_cast<Vendedor *>(user);
    set<DTPromocion> dataPromos;
    DTFecha fechaActual = ControladorFecha::getInstanciaFecha()->getFecha();
    map<string,Promocion*> mapPromos =  vendedor->getPromociones();
    for (map<string, Promocion *>::iterator it = mapPromos.begin(); it != mapPromos.end(); it++)
    {
        if (fechaActual >= it->second->getFechaVen())
        {

            DTPromocion dataPromo = it->second->getDatosPromocion();
            dataPromos.insert(dataPromo);
        }
    }
    return dataPromos;
}

string ControladorVenta::nombreVendedor(int idProducto)
{
    string nicknameV;
    Producto *productoConsultado = this->seleccionarProductoPorId(idProducto);
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

DTUsuario *ControladorVenta::infoPromocionVendedor(string opcion)
{
    Promocion *promo = this->promociones.find(opcion)->second;
    return promo->getVendedor()->getDatosUsuario();
}

set<DTProducto> ControladorVenta::infoPromocionProductos(string opcion)
{
    Promocion *promo = this->promociones.find(opcion)->second;
    set<Producto_Promocion *> prodProms = promo->getProdProms();
    set<DTProducto> retorno;
    for (set<Producto_Promocion *>::iterator iter = prodProms.begin(); iter != prodProms.end(); iter++)
    {
        DTProducto dataProd = (*iter)->getProducto()->getDataProducto();
        retorno.insert(dataProd);
    }
    return retorno;
}

void ControladorVenta::crearCompra(string nickname, DTFecha fechaActual)
{
    Usuario *client = ControladorUsuario::getInstance()->obtenerUsuarioPorNickname(nickname);
    Cliente *cliente = dynamic_cast<Cliente *>(client);
    int id = this->getContadorCompra();
    this->avanzarContadorCompra();

    Compra *compra = new Compra(fechaActual, 0, id);
    this->setMemCompra(compra);

    cliente->crearCompra(compra);
    this->compras[id] = compra;
}

bool ControladorVenta::productoEnCompra(int id)
{
    Producto *prod = this->seleccionarProductoPorId(id);
    if (prod->getCompProd() == NULL || prod->getCompProd()->getProductosEnCompra() == prod)
        return false;
    else
        return true;
}

void ControladorVenta::agregarACompra(int id, int cantidad)
{
    Producto *prod = seleccionarProductoPorId(id);
    Compra *compra = getMemCompra();
    if (prod->getCantStock() >= cantidad)
    {
        compra->agregarACompra(prod, cantidad);
    }
}

bool ControladorVenta::cantidadValida(int id, int cantidad)
{
    Producto *prod = seleccionarProductoPorId(id);
    return prod->getCantStock() >= cantidad;
}

DTCompra ControladorVenta::detallesCompra()
{
    set<DTProducto> dataProductos;
    DTFecha fechaActual = ControladorFecha::getInstanciaFecha()->getFecha();
    float sumaPrecios = 0;
    int id = this->getMemCompra()->getId(); // Asegúrate de tener un método getId en Compra

    Compra *compra = this->getMemCompra();

    for (Compra_Producto *it : compra->getCompProd())
    {
        sumaPrecios += it->sumaPrecios(fechaActual);
        DTProducto producto = it->getProductosEnCompra()->getDataProducto();
        dataProductos.insert(producto);
    }
    compra->setMontoTotal(sumaPrecios);
    DTCompra dataCompra(sumaPrecios, fechaActual, dataProductos, id); // Usar el constructor con 4 parámetros
    return dataCompra;
}

set<string> ControladorVenta::obtenerProdsPendEnvio(string nombreVendedor)
{
    Usuario *vendSelect = ControladorUsuario::getInstance()->obtenerUsuarioPorNickname(nombreVendedor);
    Vendedor *vendedorSelect = dynamic_cast<Vendedor *>(vendSelect);
    map<int, Producto *> prods = vendedorSelect->getProductos();
    set<string> productosPorEnviar;
    map<int, Compra *> compras = getCompra();
    for (map<int, Compra *>::iterator itCompra = compras.begin(); itCompra != compras.end(); ++itCompra)
    {
        set<Compra_Producto *> products = itCompra->second->getCompProd();
        for (set<Compra_Producto *>::iterator itProd = products.begin(); itProd != products.end(); ++itProd)
        {
            if (!(*itProd)->getEnvio() && (prods.find((*itProd)->getDatosProductos().getId()) != prods.end()))
            {
                productosPorEnviar.insert((*itProd)->getDatosProductos().getNombre());
            }
        }
    }
    return productosPorEnviar;
}

set<DTCompra2> ControladorVenta::clientesConEnvioPend(string nombreProducto)
{
    set<DTCompra2> dataCompras;
    map<string, Usuario *> usuarios = ControladorUsuario::getInstance()->getMapaUsuarios("");
    for (map<string, Usuario *>::iterator it = usuarios.begin(); it != usuarios.end(); ++it)
    {
        Cliente *cliente = dynamic_cast<Cliente *>(it->second);
        if ((cliente != nullptr))
        {
            map<int, Compra *> comprasCli = cliente->getCompras();
            for (map<int, Compra *>::iterator iter = comprasCli.begin(); iter != comprasCli.end(); ++iter)
            {
                set<Compra_Producto *> compras = iter->second->getCompProd();
                for (set<Compra_Producto *>::iterator iter3 = compras.begin(); iter3 != compras.end(); ++iter3)
                {
                    if (!(*iter3)->getEnvio())
                    {
                        DTCompra2 dtCompra = DTCompra2(cliente->getNickname(), iter->second->getFecha(), iter->second->getId());
                        dataCompras.insert(dtCompra);
                    }
                }
            }
        }
    }
    return dataCompras;
}

void ControladorVenta::enviarProducto(int idP, string nombreCliente)
{
    map<int, Compra *> compras = this->compras;
    set<Compra_Producto *> productosEnCompra;

    for(map<int, Compra*>::iterator itCompras = compras.begin(); itCompras != compras.end(); itCompras++)
    {
        productosEnCompra = itCompras->second->getCompProd();
        for (set<Compra_Producto *>::iterator itCompra = productosEnCompra.begin(); itCompra != productosEnCompra.end(); ++itCompra)
        {
            if ((*itCompra)->getDatosProductos().getId() == idP)
            {
                (*itCompra)->setEnvio();
            }
        }
    }

}

ControladorVenta *ControladorVenta::instancia = nullptr;

ControladorVenta::ControladorVenta(){};

ControladorVenta *ControladorVenta::getInstanciaVen()
{
    if (instancia == nullptr)
        instancia = new ControladorVenta();
    return instancia;
};
