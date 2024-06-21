#include "../include/CNotificacion.h"




set<DTNotificacion> ControladorNotificacion::mostrarNotificaciones(string nickname, IUsuario * contUsuario)
{
    map<string, Usuario *> clientes = contUsuario->listadoUsuarios("cliente");
    Usuario* user = clientes.find(nickname)->second;
    Cliente * cliente = dynamic_cast<Cliente *>(user);
    map<string, Notificacion*> mapNotis = cliente->getNotificaciones();
    set<DTNotificacion> retornoNotis;

    for (map<string, Notificacion*>::iterator it = mapNotis.begin(); it != mapNotis.end(); ++it)
    {
        DTNotificacion nuevo = DTNotificacion(it->second->getNicknameV(), it->second->getNombreProm(), it->second->getProductos());
        retornoNotis.insert(nuevo);
    }

    return retornoNotis;
}

set<DTVendedor> ControladorNotificacion::listarVendedoresSuscritos(string nickname){
    set<DTVendedor> vendedoresSuscritos;
    map<string, Usuario *> clientes = contUsuario->listadoUsuarios("cliente");
    Usuario* user = clientes.find(nickname)->second;
    Cliente * cliente = dynamic_cast<Cliente *>(user);
    map<string, Vendedor *> mapVendedoresSuscritos = cliente->getVendedoresSuscritos();
    DTVendedor aux;
    for (map<string, Vendedor*>::iterator it = mapVendedoresSuscritos.begin(); it != mapVendedoresSuscritos.end(); ++it)
    {
        aux = DTVendedor(it->second->getNickname(),it->second->getContrasena(),it->second->getFechaNac(),it->second->getCodigoRUT());
        vendedoresSuscritos.insert(aux);
    }
    return vendedoresSuscritos;
}

IUsuario * ControladorNotificacion::getControladorUsuario()
{
    return this->contUsuario;
}

void ControladorNotificacion::setControladorUsuario(IUsuario * contUsuario)
{
    this->contUsuario = contUsuario;
}

Usuario * ControladorNotificacion::getMemUsuario()
{
    return this->memUsuario;
}

void ControladorNotificacion::setMemUsuario(Usuario * usuario)
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
