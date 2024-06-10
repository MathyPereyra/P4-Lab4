#ifndef COMENTARIO_H
#define COMENTARIO_H

#include <string>
#include <set>
#include <map>

#include "usuario.h"
#include "datatypes.h"
#include "observer.h"

using namespace std;

class Comentario 
{
private:
  string texto;
  DTFecha fecha;
  integer id;
  set<DTComentario> respuestas;

public:
  Comentario(string text, DTFecha fecha, integer id)
  DTComentario getDataComentario();
  string getText();
  DTFecha getFecha();
  integer getId();
  eliminarComentario();
  set<DTComentario> getRespuestas();
  virtual ~Cliente();
};

#endif