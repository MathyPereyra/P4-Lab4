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
  int id;
  set<DTComentario> respuestas;

public:
  Comentario(string text, DTFecha fecha, int id)
  DTComentario getDataComentario();
  string getText();
  DTFecha getFecha();
  int getId();
  eliminarComentario();
  set<DTComentario> getRespuestas();
  virtual ~Comentario();
};

#endif