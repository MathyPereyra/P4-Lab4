#ifndef CUSUARIO_H
#define CUSUARIO_H

#include <string>
#include <set>

#include "datatypes.h"
#include "usuario.h"

using namespace std;

class ControladorUsuario : public IUsuario
{
private:
  map<string, Usuario *> usuarios;
  static ControladorUsuario *instancia;
  ControladorUsuario();
  // Memoria Alta de Usuario
  string memNickname;
  string memContrasena;
  DTFecha memFechaNac;

public:
  static ControladorUsuario *getInstancia();
  // Operaciones externas

  void ingresarUsuario(string nickname, string contrasena, DTFecha fechaNac);
  bool existeUsuarioIgualNickname(string nickname);
  bool terminarAlta();
  void altaCliente(string algo, string algo2);
  void altaVendedor(string algo);
  void confirmarAltaUsuario();
  void setDataUsuario(string nickname, string contrasena, DTFecha fechaNac);
  set<DTUsuario> listadoUsuarios(string);
  set<string> listadoNicknameCliente();
  set<string> listadoUsuarioNickname();
  set<DTComentario> listadoComentario(string);
  void eliminarComentario(int);
  void getInstance();

  // Operaciones internas
  void limpiarMemoria();

  virtual ~ControladorUsuario();
};

#endif
