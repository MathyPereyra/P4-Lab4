#include "../include/CNotificacion.h"
#include "../include/vendedor.h"

set<DTUsuario *> ControladorNotificacion::listarVendedoresNoSuscritos(string nicknameC)
{
    set<DTUsuario *> vendNoSuscritos;
    map<string, Usuario *> vendedores = ControladorUsuario::getInstance()->getMapaUsuarios("vendedor");
    map<string, Usuario *>::iterator it;
    for (it = vendedores.begin(); it != vendedores.end(); it++)
    {
        Vendedor *vendedor = dynamic_cast<Vendedor *>(it->second);
        if (!vendedor->estaSuscrito(nicknameC))
        {
            DTUsuario *dataVendedor = vendedor->getDatosUsuario();
            vendNoSuscritos.insert(dataVendedor);
        }
    }
    return vendNoSuscritos;
}

void ControladorNotificacion::suscribirAVendedor(string nicknameC, string nicknameV)
{
    map<string, Usuario *> listUsuarios = ControladorUsuario::getInstance()->getMapaUsuarios("");
    Usuario *obs = listUsuarios.find(nicknameC)->second;
    Usuario *ven = listUsuarios.find(nicknameV)->second;
    Vendedor *vendedor = dynamic_cast<Vendedor *>(ven);
    IObserver *observer = dynamic_cast<IObserver *>(obs);
    if (vendedor != NULL && observer != NULL)
    {
        vendedor->agregarSuscriptor(observer);
    }
}

set<DTNotificacion> ControladorNotificacion::mostrarNotificaciones(string nickname)
{
    Usuario *user = ControladorUsuario::getInstance()->obtenerUsuarioPorNickname(nickname);
    this->setMemUsuario(user);
    Cliente *cliente = dynamic_cast<Cliente *>(user);

    map<string, Notificacion *> mapNotis = cliente->getNotificaciones();
    set<DTNotificacion> retornoNotis;
    for (map<string, Notificacion *>::iterator it = mapNotis.begin(); it != mapNotis.end(); ++it)
    {
        set<DTProducto> dataProds;
        map<int, Producto *> mapProds = it->second->getProductos();
        for (map<int, Producto *>::iterator iter = mapProds.begin(); iter != mapProds.end(); ++iter)
        {
            DTProducto dataProd = iter->second->getDataProducto();
            dataProds.insert(dataProd);
        }
        DTNotificacion nuevo = DTNotificacion(it->second->getNicknameV(), it->second->getNombreProm(), dataProds);
        retornoNotis.insert(nuevo);
    }

    return retornoNotis;
}

void ControladorNotificacion::eliminarNotificacion()
{
    Cliente *cliente = dynamic_cast<Cliente *>(this->getMemUsuario());
    if (cliente == NULL)
    {
        return;
    }
    cliente->eliminarNotificaciones();
}

set<DTUsuario *> ControladorNotificacion::listarVendedoresSuscritos(string nicknameC)
{
    set<DTUsuario *> vendSuscritos;
    map<string, Usuario *> vendedores = ControladorUsuario::getInstance()->getMapaUsuarios("vendedor");
    map<string, Usuario *>::iterator it;
    for (it = vendedores.begin(); it != vendedores.end(); it++)
    {
        Vendedor *vendedor = dynamic_cast<Vendedor *>(it->second);
        if (vendedor->estaSuscrito(nicknameC))
        {
            DTUsuario *dataVendedor = vendedor->getDatosUsuario();
            vendSuscritos.insert(dataVendedor);
        }
    }
    return vendSuscritos;
}

void ControladorNotificacion::eliminarSuscripcion(string nicknameC, string nicknameV)
{
    map<string, Usuario *> listUsuarios = ControladorUsuario::getInstance()->getMapaUsuarios("");
    Usuario *obs = listUsuarios.find(nicknameC)->second;
    Usuario *ven = listUsuarios.find(nicknameV)->second;
    Vendedor *vendedor = dynamic_cast<Vendedor *>(ven);
    IObserver *observer = dynamic_cast<IObserver *>(obs);
    if (vendedor != NULL && observer != NULL)
    {
        vendedor->eliminarSuscriptor(observer);
    }
}

IUsuario *ControladorNotificacion::getControladorUsuario()
{
    return this->contUsuario;
}

void ControladorNotificacion::setControladorUsuario(IUsuario *contUsuario)
{
    this->contUsuario = contUsuario;
}

Usuario *ControladorNotificacion::getMemUsuario()
{
    return this->memUsuario;
}

void ControladorNotificacion::setMemUsuario(Usuario *usuario)
{
    this->memUsuario = usuario;
}

ControladorNotificacion::ControladorNotificacion(){};

ControladorNotificacion *ControladorNotificacion::instancia = nullptr;

ControladorNotificacion *ControladorNotificacion::getInstanciaN()
{
    if (instancia == nullptr)
        instancia = new ControladorNotificacion();
    return instancia;
};
