#ifndef USUARIO_H
#define USUARIO_H

#include <string>
#include <set>
#include <map>

#include "datatypes.h"
#include "observer.h"
#include "comentario.h"

using namespace std;

class Usuario 
{
protected:
  string nickname;
  string contrasena;
  DTFecha fechaNac;
  set<Comentario> *comentarios;

public:
  Usuario(string nickname, string contrasena, DTFecha fechaNac);

  virtual string getNickname();
  virtual string getContrasena();
  virtual DTFecha getFechaNac();

  virtual set<DTComentario> listadoComentario();
  virtual DTUsuario getDatos() = ;
  virtual set<Comentario> getComentarios();
};

#endif
