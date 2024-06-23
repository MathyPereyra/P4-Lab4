#ifndef CUSUARIO_H
#define CUSUARIO_H

#include "IUsuario.h"
#include "datatypes.h"
#include <string>
#include <set>
#include <map>

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
  void recordarUsuario(string nickname);
  void ingresarUsuario(string nickname, string contrasena, DTFecha fechaNac);
  bool existeUsuarioIgualNickname(string nickname);
  void terminarAlta();
  void altaCliente(string direccion, string ciudad);
  void altaVendedor(string codigoRUT);
  void confirmarAltaUsuario();

  DTUsuario *getDatosUsuario(string nickname);

  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  //  Retorna set de nicknames, si el tipo es cliente retorna los nickname de todos los clientes y si el tipo es vendedor el de todos los vendedores
  set<DTUsuario *> listadoUsuarios(string tipoDeUsuario);
  set<DTUsuario *> listadoUsuarios();
  set<DTCliente> listadoClientes();
  map<string, Usuario *> getMapaUsuarios(string opcion);
  //  Retorna set con los nickname de todos los usuarios del sistema (Clientes y Vendedores)
  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

  set<string> listadoUsuarioNickname();
  set<DTComentario> listadoComentario(int id);
  set<DTComentario> listadoComentario(string nickname);
  void eliminarComentario(int id);
  static ControladorUsuario *getInstance();

  // Operaciones internas
  // void limpiarMemoria();

  void crearComentario(string texto, int producto, string usuario);
  void crearComentario(string texto, int idP, string nicknameU, DTFecha fecha);

  void crearRespuesta(string texto, int idC, int idP, string nicknameU);
  void crearRespuesta(string texto, int idC, int idP, string nicknameU, DTFecha fecha);
  bool hayComentarios(int id);

  Usuario *obtenerUsuarioPorNickname(const string &nickname);

  void liberarMemoriaUsuario();

  virtual ~ControladorUsuario(){};
};

#endif
