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
  // Recordar pasar estos tres atributos como DataUsuario antes de entregar
  string memNickname;
  string memContrasena;
  DTFecha memFechaNac;
  Usuario *memUsuario;
  int contadorComentario;

public:
  void setContadorComentario();
  int getContadorComentario();
  void avanzarContadorComentario();

  static ControladorUsuario *getInstancia();
  // Operaciones externas
  string getmemNickname();
  string getmemContrasena();
  DTFecha getmemFechaNac();
  Usuario *getmemUsuario();
  void recordarUsuario(Usuario *usuario);
  void ingresarUsuario(string nickname, string contrasena, DTFecha fechaNac);
  bool existeUsuarioIgualNickname(string nickname);
  void terminarAlta();
  void altaCliente(string direccion, string ciudad);
  void altaVendedor(string codigoRUT);
  void confirmarAltaUsuario();
  // void setDataUsuario(string nickname, string contrasena, DTFecha fechaNac);

  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  //  Retorna set de nicknames, si el tipo es cliente retorna los nickname de todos los clientes y si el tipo es vendedor el de todos los vendedores
  map<string, Usuario*> listadoUsuarios(string tipoDeUsuario);
  map<string, Usuario*> listadoUsuarios();
  //  Retorna set con los nickname de todos los usuarios del sistema (Clientes y Vendedores)
  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

  // set<string> listadoNicknameCliente();
  set<string> listadoUsuarioNickname();
  // set<DTComentario> listadoComentario(string);
  void eliminarComentario(int id);
  static ControladorUsuario *getInstance();

  // Operaciones internas
  // void limpiarMemoria();

  void crearComentario(string texto, Producto *producto, Usuario * usuario);
  void crearRespuesta(string texto, Comentario *comentarioOg);

  Usuario *obtenerUsuarioPorNickname(const string &nickname);

  void liberarMemoriaUsuario();

  virtual ~ControladorUsuario(){};
};

#endif
