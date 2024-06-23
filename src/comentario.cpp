#include "../include/comentario.h"
#include "../include/producto.h"

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

void Comentario::agregarRespuesta(Comentario *Comentario)
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
    cout << "el id del comentario es " << this->getId();
    this->producto->listadoComentarios().erase(this->getId());
    if(this->respondeA != NULL)
    {
      this->respondeA->getMapRespuestas().erase(this->getId()); 
    }
    delete this;
  }
  else
  {
    map<int, Comentario *>::iterator ite;
    for (ite = this->respuestas.begin(); ite != this->respuestas.end(); ++ite)
    {
      ite->second->eliminarComentario();
      delete ite->second;
    }
    this->respuestas.clear();
  }
}

set<DTComentario> Comentario::getRespuestas()
{
    map<int, Comentario *>::iterator it;
    map<int, Comentario *> resp = this->respuestas;
    set<DTComentario> dataComens;
    for (it = resp.begin(); it != resp.end(); it++)
    {
        DTComentario dataC = DTComentario(it->second->getText(), it->second->getId(), it->second->getFecha());
        dataComens.insert(dataC);
    }
    return dataComens;
};

map<int, Comentario*> Comentario::getMapRespuestas()
{
 return this->respuestas; 
}
