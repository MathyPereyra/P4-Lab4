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
    virtual void ingresarUsuario(string nickname, string contrasena, DTFecha fechaNac) = 0;
    virtual bool existeUsuarioIgualNickname(string nickname) = 0;
    virtual void terminarAlta() = 0;
    virtual void altaCliente(string algo, string algo2) = 0;
    virtual void altaVendedor(string algo) = 0;
    virtual void confirmarAltaUsuario() = 0;
    virtual void setDataUsuario(string nickname, string contrasena, DTFecha fechaNac) = 0;

    virtual set<DTUsuario> listadoUsuarios(string) = 0;
    virtual set<string> listadoNicknameCliente() = 0;
    virtual set<string> listadoUsuarioNickname() = 0;
    virtual set<DTComentario> listadoComentario(string) = 0;
    virtual void eliminarComentario(int) = 0;

    virtual ~IUsuario(){};
};

#endif