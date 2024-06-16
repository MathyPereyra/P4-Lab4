#include "../include/comentario.h"

#include <string>

using namespace std;

Comentario::Comentario(){};

Comentario::Comentario(string text, DTFecha fecha, int id, Producto *producto)
    : texto(text), fecha(fecha), id(id), producto(producto), respondeA(NULL) {}

Comentario::Comentario(string text, DTFecha fecha, int id)
    : texto(text), fecha(fecha), id(id), producto(NULL), respondeA(NULL) {}

string Comentario::getText()
{
  return this->texto;
};

 void Comentario::agregarRespuesta(Comentario * Comentario)
{
  this->respuestas[Comentario->getId()] = Comentario;
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
  if (this->respuestas.empty())
  {
    this->producto->listadoComentarios().erase(this->getId());
    delete this->producto;
    if (this->respondeA != NULL)
      delete this->respondeA;
    this->~Comentario();
  }
  else
  {
    map<int, Comentario *>::iterator ite;
    for (ite = this->respuestas.begin(); ite != this->respuestas.end(); ++ite)
    {
      ite->second->eliminarComentario();
    }
  }
}

// set<Comentario> Comentario::getRespuestas()
//{
//   return this->respuestas;
// }
