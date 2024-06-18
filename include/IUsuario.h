#ifndef IUSUARIO_H
#define IUSUARIO_H

#include <string>
#include <set>
#include <map>

#include "usuario.h"
#include "datatypes.h"
#include "observer.h"
#include "cliente.h"  //no estoy seguro de si debe estar, pero para altaCliente creo qeu se utilizará
#include "vendedor.h" //no estoy seguro de si debe estar, pero para altaVendedor creo qeu se utilizará
#include "promocion.h"

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
    virtual void recordarUsuario(Usuario *usuario) = 0;
    virtual Usuario *obtenerUsuarioPorNickname(const string &nickname) = 0;
    virtual map<string, Usuario*> listadoUsuarios(string tipoUsuario) = 0;
    virtual map<string, Usuario*> listadoUsuarios() = 0;
    // virtual set<string> listadoNicknameCliente() = 0;
    // virtual set<string> listadoUsuarioNickname() = 0;
    // virtual set<DTComentario> listadoComentario(string) = 0;
    virtual void eliminarComentario(int id) = 0;
    virtual void crearComentario(string texto, Producto *producto, Usuario * usuario) = 0;
    virtual void liberarMemoriaUsuario() = 0;
    virtual void crearRespuesta(string texto, Comentario* comentarioOg) = 0;

    virtual ~IUsuario(){};
};

#endif
