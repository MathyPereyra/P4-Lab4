#ifndef USUARIO_H
#define USUARIO_H

#include <string>
#include <set>
#include <map>

#include "datatypes.h"
#include "observer.h"
#include "comentario.h"

using namespace std;

class Usuario : public IObserver
{
protected:
  string nickname;
  string contrasena;
  DTFecha fechaNac;
  tipo tipoUsuario;
  set<Comentario> comentarios;

public:
  Usuario(string nickname, string contrasena, DTFecha fechaNac, tipo tipoUsuario);

  virtual string getNickname();
  virtual string getContrasena();
  virtual DTFecha getFechaNac();
  virtual tipo getTipo();

  virtual set<DTComentario> listadoComentario();
  virtual void eliminarComentario(int id) ;
  virtual DTUsuario getDatos();
  virtual set<Comentario> getComentarios();
};

#endif
