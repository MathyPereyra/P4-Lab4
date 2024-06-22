#include "../include/producto.h"

#include <string>

using namespace std;
Producto::Producto(int id, categoria cat, string nombre, string descripcion, int cantStock, float precio, Promocion * promo, Compra_Producto * compProd)
    : id(id), cat(cat), nombre(nombre), descripcion(descripcion), cantStock(cantStock), precio(precio), promo(promo), compProd(compProd) {}


bool Producto::estaEnPromo()
{
   return (this->promo != NULL);
};


bool Producto::estaEnCompra()
{
   return this->getCompProd() != NULL;
}


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


Promocion * Producto::getPromo()
{
   return this->promo;
}


void Producto::agregadoAPromo(Promocion * promo)
{
   this->promo = promo;
}


void Producto::agregadoACompra(Compra_Producto * compProd)
{
   this->compProd = compProd;
}



float Producto::getPrecio()
{

    return this->precio;
}


void Producto::restaDeStock(int cantidad)
{
   if(this->cantStock >= cantidad)
   {  
      this->cantStock = this->cantStock - cantidad;
   }
}


Compra_Producto * Producto::getCompProd()
{
   return this->compProd;
}