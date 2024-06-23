#ifndef COMENTARIO_H
#define COMENTARIO_H

#include "datatypes.h"
#include "producto.h"
#include <string>
#include <set>
#include <map>

using namespace std;

class Comentario
{
private:
  string texto;
  DTFecha fecha;
  int id;
  map<int, Comentario *> respuestas;
  Comentario *respondeA;
  Producto *producto;

public:
  Comentario();
  Comentario(string text, DTFecha fecha, int id, Producto *prod);
  Comentario(string text, DTFecha fecha, int id);

  DTComentario getDataComentario();
  string getText();
  DTFecha getFecha();
  int getId();
  set<Comentario> getRespuestas();
  void agregarRespuesta(Comentario *Comentario);

  void eliminarComentario();

  virtual ~Comentario(){};
};

#endif
