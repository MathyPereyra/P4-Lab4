#include "../include/CUsuario.h"

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

tipo ControladorUsuario::getmemTipo()
{
    return this->memTipo;
};

void ControladorUsuario::ingresarUsuario(string nickname, string contrasena, DTFecha fechaNac, tipo tipousuario)
{
    this->memNickname = nickname;
    this->memContrasena = contrasena;
    this->memFechaNac = fechaNac;
    this->memTipo = tipousuario;
};

bool ControladorUsuario::existeUsuarioIgualNickname(string nickname)
{
    bool existe = false;
    map<string, Usuario *>::iterator it;
    for (it = this->usuarios.begin(); it != this->usuarios.end(); ++it)
    {
        if (it->getNickname() == nickname)
        {
            existe = true;
            break;
        }
    }

    return existe;
};

// no se que iria aca
void ControladorUsuario::terminarAlta() {

};

// esta no la termine, hay q chequear la creadora/setter de usuario
void ControladorUsuario::altaCliente(string direccion, string ciudad)
{
    Cliente *nuevo = new Cliente(direccion, ciudad);
    nuevo->setnickname
        nuevo->setcontrasena
            nuevo->setfechanac

        this->usuarios[this->memNickname] = new Cliente(direccion, ciudad);
};

void ControladorUsuario::altaVendedor(string algo) {

};

void ControladorUsuario::confirmarAltaUsuario() {

};

void ControladorUsuario::setDataUsuario(string nickname, string contrasena, DTFecha fechaNac, tipo tipousuario) {

};

set<string> ControladorUsuario::listadoUsuarios(tipo tipodeusuario)
{
    set<string> nombres;
    map<string, Usuario *>::iterator it;
    for (it = this->usuarios.begin(); it != this->usuarios.end(); ++it)
    {
        if (it->getTipo == tipodeusuario)
        {
            nombres.insert(it->getNickname);
        }
    }

    return nombres;
};

set<string> ControladorUsuario::listadoNicknameCliente()
{
    return this->listadoUsuarios(cliente);
};

// aca asumi que el map usuarios de CUsuario que mapea usuarios a strings guarda como string el nickname del usuario
set<string> ControladorUsuario::listadoUsuarioNickname()
{
    set<string> nombres;
    map<string, Usuario *>::iterator it;
    for (it = this->usuarios.begin(); it != this->usuarios.end(); ++it)
    {
        nombres.insert(it->getNickname);
    }

    return nombres;
};

set<DTComentario> ControladorUsuario::listadoComentarioUsuario(string){

};

void ControladorUsuario::eliminarComentario(int) {

};

void ControladorUsuario::getInstance() {

};
