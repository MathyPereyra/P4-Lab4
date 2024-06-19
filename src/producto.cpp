#include "../include/producto.h"

#include <string>

using namespace std;
Producto::Producto(int id, categoria cat, string nombre, string descripcion, int cantStock, float precio, bool estaEnProm)
    : id(id), cat(cat), nombre(nombre), descripcion(descripcion), cantStock(cantStock), precio(precio), estaEnProm(estaEnProm) {}

bool Producto::estaEnPromo()
{
   return this->estaEnProm;
};
//
//
////cambiar DCD flecha q va a producto desde producto-promocion
// float Producto::calcularDescuento(){

// };

map<int, Comentario *> Producto::listadoComentarios()
{
   return this->comentarios;
};

void Producto::agregarComentario(int id, Comentario *comentario)
{
   this->comentarios[id] = comentario;
};

DTProducto Producto::getDataProducto()
{
   return DTProducto(this->id, this->cat, this->nombre, this->descripcion, this->cantStock, this->precio);
};

int Producto::getId()
{
   return this->id;
};


string Producto::getNombre()
{
   return this->nombre;
}


categoria Producto::getCat()
{
   return this->cat;
};

string Producto::getDesc()
{
   return this->descripcion;
};

int Producto::getCantStock()
{
   return this->cantStock;
};


void Producto::agregadoAPromo()
{
   this->estaEnProm = true;
}


float Producto::getPrecio()
{

    return this->precio;
}