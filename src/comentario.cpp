#include "../include/usuario.h"
#include "../include/comentario.h"
#include <string>
#include "datatypes.h"

using namespace std;

Comentario::Comentario(string text, DTFecha fecha, int id)
    : texto(text), fecha(fecha), id(id){};

string Comentario::getText()
{
  return this->texto;
};

DTComentario::getDataComentario()
{
  return DTComentario(this->text, this->id, this->fecha);
};

DTFecha Comentario::getFecha()
{
  return this->fecha;
};

int Comentario::getId()
{
  return this->id;
};

set<Comentario> Comentario::getRespuestas()
{
  return this->respuestas;
}

void Cliente::crearCompra(int id)
{
  Compra d = Compra();
  d.setId(id);
  this->compras.insert(d);
}

void Comentario::eliminarComentario()
{
}
