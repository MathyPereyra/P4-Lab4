#ifndef CUSUARIO_H
#define CUSUARIO_H

#include <string>
#include <set>
#include <map>

#include "datatypes.h"
#include "usuario.h"
#include "IUsuario.h"
#include "cliente.h"  //no estoy seguro de si debe estar, pero para altaCliente creo qeu se utilizará
#include "vendedor.h" //no estoy seguro de si debe estar, pero para altaVendedor creo qeu se utilizará

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
  void altaVendedor(string codigoRUT);
  void confirmarAltaUsuario();
  void setDataUsuario(string nickname, string contrasena, DTFecha fechaNac, tipo tipousuario);

  
  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  //  Retorna set de nicknames, si el tipo es cliente retorna los nickname de todos los clientes y si el tipo es vendedor el de todos los vendedores
  set<DTUsuario> listadoUsuarios(tipo tipodeusuario);
  //  Retorna set con los nickname de todos los usuarios del sistema (Clientes y Vendedores)
  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

  set<DTUsuario> listadoUsuarios();
  set<string> listadoNicknameCliente();
  set<string> listadoUsuarioNickname();
  set<DTComentario> listadoComentarioUsuario(string);
  void eliminarComentario(int);
  static ControladorUsuario* getInstance();

  // Operaciones internas
  void limpiarMemoria();

  virtual ~ControladorUsuario();
};

#endif
