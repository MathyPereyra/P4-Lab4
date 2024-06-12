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
private:
  string nickname;
  string contrasena;
  DTFecha fechaNac;
  set<Comentario> comentarios;

public:
  Usuario(string nickname, string contrasena, DTFecha fechaNac);
  string getNickname();
  string getContrasena();
  string getFechaNac();
  set<DTComentario> listadoComentario();
  void eliminarComentario(integer id);
  DTUsuario getDatos();
  set<Comentario> getComentarios();
};

#endif
