#ifndef USUARIO_H
#define USUARIO_H

#include <string>
#include <set>
#include <map>

#include "datatypes.h"
#include "observer.h"
#include "comentario.h"

using namespace std;

class Compra;

class Usuario
{
protected:
  string nickname;
  string contrasena;
  DTFecha fechaNac;
  map<int, Comentario*> comentarios;
//  tipo tipoUsuario;

public:
  Usuario(string nickname, string contrasena, DTFecha fechaNac);

  virtual string getNickname();
  virtual string getContrasena();
  virtual DTFecha getFechaNac();

//  tipo getTipo();

  //virtual set<DTComentario> listadoComentarioUsuario() ;
  virtual DTUsuario getDatosUsuario() = 0;
  virtual map<int, Comentario*> getComentarios() = 0;
  virtual void agregarComentario(int id, Comentario * nuevo) = 0;
  virtual void crearCompra(Compra * compra) = 0;

  virtual ~Usuario(){};
};

#endif
