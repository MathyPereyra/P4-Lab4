#include "../include/producto.h"
#include <string>

using namespace std;

Producto(integer id, categoria cat, string desc, integer cantStock, float precio, bool esta){
: id(id), categoria(cat), desc(string), cantStock(cantStock), precio(precio), esta(esta){};
};


bool producto::estaEnPromo(){
    
    return this->esta;
};



//cambiar DCD flecha q va a producto desde producto-promocion
float producto::calcularDescuento(){
    
};


DTProducto producto::getDataProducto(){

    return DTProducto(this->id, this->cat, this->descripcion, this->cantStock, this->precio);
};


integer producto::getId(){

    return this->id;
};



categoria producto::getCat(){
    
    return this->cat;
};


string producto::getDesc(){
    
    return this->descripcion;
};



integer producto::getCantStock(){

    return this->cantStock;
};

  

float producto::getPrecio(){
    
    return this->precio;
};