#ifndef IUSUARIO_H
#define IUSUARIO_H

#include "usuario.h"
#include "cliente.h"
#include <string>
#include <set>
#include <map>

using namespace std;

class IUsuario
{
public:
    virtual void setContadorComentario() = 0;
    virtual void ingresarUsuario(string nickname, string contrasena, DTFecha fechaNac) = 0;
    virtual bool existeUsuarioIgualNickname(string nickname) = 0;
    virtual void terminarAlta() = 0;
    virtual void altaCliente(string direccion, string ciudad) = 0;
    virtual void altaVendedor(string codigoRUT) = 0;
    virtual void confirmarAltaUsuario() = 0;
    // virtual void setDataUsuario(string nickname, string contrasena, DTFecha fechaNac) = 0;
    virtual void recordarUsuario(string nickname) = 0;
    virtual Usuario *obtenerUsuarioPorNickname(const string &nickname) = 0;
    virtual set<DTUsuario *> listadoUsuarios(string tipoUsuario) = 0;
    virtual set<DTUsuario *> listadoUsuarios() = 0;
    virtual map<string, Usuario *> getMapaUsuarios(string tipoDeUsuario) = 0;
    // virtual set<string> listadoNicknameCliente() = 0;
    // virtual set<string> listadoUsuarioNickname() = 0;
    virtual set<DTComentario> listadoComentario(int id) = 0;
    virtual set<DTComentario> listadoComentario(string nickname) = 0;
    virtual void eliminarComentario(int id) = 0;
    virtual void crearComentario(string texto, int id, string nicknameU) = 0;
    virtual void crearRespuesta(string texto, int idC, int idP) = 0;
    virtual bool hayComentarios(int id) = 0;

    virtual void liberarMemoriaUsuario() = 0;

    virtual ~IUsuario(){};
};

#endif
