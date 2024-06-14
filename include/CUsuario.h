#ifndef CUSUARIO_H
#define CUSUARIO_H

#include <string>
#include <set>

#include "datatypes.h"
#include "usuario.h"
#include "IUsuario.h"

using namespace std;

class ControladorUsuario : public IUsuario
{
private:
  // aca asumi que el map usuarios de CUsuario que mapea usuarios a strings guarda como string el nickname del usuario
  map<string, Usuario *> usuarios;
  static ControladorUsuario *instancia;
  ControladorUsuario();
  // Memoria Alta de Usuario
  string memNickname;
  string memContrasena;
  DTFecha memFechaNac;
  tipo memTipo;

public:
  static ControladorUsuario *getInstancia();
  // Operaciones externas
  string getmemNickname();
  string getmemContrasena();
  DTFecha getmemFechaNac();
  tipo getmemTipo();
  void ingresarUsuario(string nickname, string contrasena, DTFecha fechaNac, tipo tipousuario);
  bool existeUsuarioIgualNickname(string nickname);
  void terminarAlta();
  void altaCliente(string direccion, string ciudad);
  void altaVendedor(string algo);
  void confirmarAltaUsuario();
  void setDataUsuario(string nickname, string contrasena, DTFecha fechaNac, tipo tipousuario);
  //  Retorna set de nickanmes, si el tipo es cliente retorna los nickanme de todos los clientes y si el tipo es vendedor el de todos los vendedores
  set<string> listadoUsuarios(tipo tipodeusuario);
  //  Retorna set con los nickname de todos los usuarios del sistema (Clientes y Vendedores)
  set<string> listadoNicknameCliente();
  set<string> listadoUsuarioNickname();
  set<DTComentario> listadoComentarioUsuario(string);
  void eliminarComentario(int);
  void getInstance();

  // Operaciones internas
  void limpiarMemoria();

  virtual ~ControladorUsuario();
};

#endif
