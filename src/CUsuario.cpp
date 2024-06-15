#include "../include/CUsuario.h"
#include "../include/datatypes.h"
#include "../include/usuario.h"
#include "../include/cliente.h"
#include "cliente.cpp"
#include "../include/vendedor.h"
#include <cstddef>

string ControladorUsuario::getmemNickname()
{
    return this->memNickname;
};

string ControladorUsuario::getmemContrasena()
{
    return this->memContrasena;
};

DTFecha ControladorUsuario::getmemFechaNac()
{
    return this->memFechaNac;
};

void ControladorUsuario::ingresarUsuario(string nickname, string contrasena, DTFecha fechaNac)
{
    this->memNickname = nickname;
    this->memContrasena = contrasena;
    this->memFechaNac = fechaNac;
//    this->memTipo = tipoUsuario;
};

bool ControladorUsuario::existeUsuarioIgualNickname(string nickname)
{
    bool existe = false;
    map<string, Usuario *>::iterator it;
    for (it = this->usuarios.begin(); it != this->usuarios.end(); ++it)
    {
        if (it->second->getNickname() == nickname)
        {
            existe = true;
            break;
        }
    }
    return existe;
};

// no se que iria aca
void ControladorUsuario::terminarAlta()
{
//acá se debe de liberar memoria del DTUsuario credo temporalmente en ingresarUsuario, 
// es para el caso en que el nickname ya existe en la colección de Usuarios
    this->memFechaNac.~DTFecha();
};

void ControladorUsuario::altaCliente(string direccion, string ciudad)
{
    Cliente* nuevo = new Cliente(this->memNickname,this->memContrasena, this->memFechaNac, direccion, ciudad);
    this->usuarios[this->memNickname] = nuevo;
};

void ControladorUsuario::altaVendedor(string codigoRUT) 
{
    Vendedor* nuevo = new Vendedor(this->memNickname, this->memContrasena, this->memFechaNac, codigoRUT);
    this->usuarios[this->memNickname] = nuevo;
};

void ControladorUsuario::confirmarAltaUsuario() 
{
    this->memFechaNac.~DTFecha();
};

void ControladorUsuario::setDataUsuario(string nickname, string contrasena, DTFecha fechaNac) {

};




// Se puede emprolijar sacando los if para afuera y el for dentro de cada if dependiendo el caso
set<DTUsuario> ControladorUsuario::listadoUsuarios(string tipoDeUsuario)
{
    set<DTUsuario> dataUsuarios;
    map<string, Usuario *>::iterator it;
    for (it = this->usuarios.begin(); it != this->usuarios.end(); ++it)
    {
        if (tipoDeUsuario == "cliente")
        {
            Cliente *cliente = dynamic_cast<Cliente*>(it->second);
            if (cliente != NULL)
            {
                dataUsuarios.insert(cliente->getDatosUsuario());
            }
        }
        else if (tipoDeUsuario == "vendedor") 
        {
            Vendedor *vendedor = dynamic_cast<Vendedor*>(it->second);
            if ("cliente" != NULL)
            {
                dataUsuarios.insert(vendedor->getDatosUsuario());
            }
        }
        else
        {
            dataUsuarios.insert(it->second->getDatosUsuario());
        }
    }
    return dataUsuarios;
};

set<DTUsuario> ControladorUsuario::listadoUsuarios()
{
    set<DTUsuario> dataUsuarios;
    map<string, Usuario *>::iterator it;
    for (it = this->usuarios.begin(); it != this->usuarios.end(); ++it)
    {
            dataUsuarios.insert(it->second->getDatosUsuario());
    }

    return dataUsuarios;
}

set<string> ControladorUsuario::listadoNicknameCliente()
{
    set<string> setNicknames;
    for(DTUsuario dtU : this->listadoUsuarios("cliente"))
    {
        setNicknames.insert(dtU.getNickname());
    }
    return setNicknames;
};

// aca asumi que el map usuarios de CUsuario que mapea usuarios a strings guarda como string el nickname del usuario
//set<string> ControladorUsuario::listadoUsuarioNickname()
//{
//    set<string> nombres;
//    map<string, Usuario *>::iterator it;
//    for (it = this->usuarios.begin(); it != this->usuarios.end(); ++it)
//    {
//        nombres.insert(it->getNickname);
//    }
//
//    return nombres;
//};

set<DTComentario> ControladorUsuario::listadoComentarioUsuario(string){

};

void ControladorUsuario::eliminarComentario(int) {

};

ControladorUsuario::ControladorUsuario()
{
    this->memFechaNac = DTFecha();
};

ControladorUsuario * ControladorUsuario::getInstance() 
{
    if (instancia == NULL)
        instancia = new ControladorUsuario();
    return instancia;
};
