#ifndef COMENTARIO_H
#define COMENTARIO_H

#include <string>
#include <set>
#include <map>

#include "datatypes.h"
#include "observer.h"

using namespace std;

class Comentario
{
private:
  string texto;
  DTFecha fecha;
  int id;
  set<Comentario> *respuestas;

public:
  Comentario(string text, DTFecha fecha, int id);

  DTComentario getDataComentario();
  string getText();
  DTFecha getFecha();
  int getId();
  set<Comentario> getRespuestas();

  void eliminarComentario();

  virtual ~Comentario();
};

#endif
