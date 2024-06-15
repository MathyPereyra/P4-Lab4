#include "../include/comentario.h"

#include <string>

using namespace std;

Comentario::Comentario(string text, DTFecha fecha, int id)
    : texto(text), fecha(fecha), id(id){};

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

//set<Comentario> Comentario::getRespuestas()
//{
//  return this->respuestas;
//}

