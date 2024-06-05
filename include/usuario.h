#ifndef USUARIO_H
#define USUARIO_H

#include <string>
#include <set>
#include <map>

#include "datatypes.h"
#include "observer.h"

using namespace std;

class Usuario : public IObserver
{
private:
  string nickname;
  string contrasena;
  DTFecha fechaNac;

public:
  Usuario(string nickname, string contrasena, DTFecha fechaNac);
  string getNickname();
  string getContrasena();
  string getFechaNac();
  DTComentario listadoComentario();
  void eliminarComentario(int);
  DTUsuario getDatos();
};

#endif
