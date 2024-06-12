#ifndef IUSUARIO_H
#define IUSUARIO_H

#include <string>
#include <set>
#include <map>

#include "usuario.h"
#include "datatypes.h"
#include "observer.h"

using namespace std;

class IUsuario 
{
public:
    virtual void ingresarUsuario(string nickname, string contrasena, DTFecha fechaNac);
    virtual bool existeUsuarioIgualNickname(string nickname);
    virtual void terminarAlta();
    virtual void altaCliente(string algo, string algo2);
    virtual void altaVendedor(string algo);
    virtual void confirmarAltaUsuario();
    virtual void setDataUsuario(string nickname, string contrasena, DTFecha fechaNac);

    virtual set<DTUsuario> listadoUsuarios(string);
    virtual set<string> listadoNicknameCliente();
    virtual set<string> listadoUsuarioNickname();
    virtual set<DTComentario> listadoComentario(string);
    virtual void eliminarComentario(int);

    virtual ~IUsuario(){};
};