#include "../include/comentario.h"

#include <string>

using namespace std;

Comentario::Comentario(){};

Comentario::Comentario(string text, DTFecha fecha, int id, Producto *producto)
    : texto(text), fecha(fecha), id(id), producto(*producto), respondeA(NULL) {}

Comentario::Comentario(string text, DTFecha fecha, int id, Producto *producto, Comentario *respondeA)
    : texto(text), fecha(fecha), id(id), producto(*producto), respondeA(respondeA) {}

string Comentario::getText()
{
  return this->texto;
};

DTComentario Comentario::getDataComentario()
{
  return DTComentario(this->texto, this->id, this->fecha);
};

DTFecha Comentario::getFecha()
{
  return this->fecha;
};

int Comentario::getId()
{
  return this->id;
};

void Comentario::eliminarComentario()
{
  if (this->respuestas == NULL)
  {
    this->producto->listadoComentarios().erase(this.getId());
    delete this->producto;
    if (this->respondeA != NULL)
      delete this->respondeA;
    this->~Comentario();
  }
  else
  {
    map<int, Comentario *>::iterator ite;
    for (ite = this->respuestas.begin(); it != this->respuestas.end(); ++it)
    {
      res.eliminarComentario();
    }
  }
}

// set<Comentario> Comentario::getRespuestas()
//{
//   return this->respuestas;
// }
