#include "../include/datatypes.h"
#include <string>

// DTFecha
DTFecha::DTFecha() : dia(), mes(), anio() {};

DTFecha::DTFecha(int dia, int mes, int anio) : dia(dia),
                                               mes(mes),
                                               anio(anio){};

int DTFecha::getDia() const
{
  return this->dia;
}

int DTFecha::getMes() const
{
  return this->mes;
}

int DTFecha::getAnio() const
{
  return this->anio;
}

void DTFecha::setDia(int d)
{
  dia = d;
}

void DTFecha::setMes(int m)
{
  mes = m;
}

void DTFecha::setAnio(int a)
{
  anio = a;
}

bool DTFecha::operator>=(const DTFecha desde) const
{
  return ((this->anio > desde.anio) ||
          (this->anio == desde.anio && this->mes > desde.mes) ||
          (this->anio == desde.anio && this->mes == desde.mes && this->dia >= desde.dia));
}


// DataComentario
DTComentario::DTComentario(string text, int id, DTFecha fechaCom)
{
  this->text = text;
  this->id = id;
  this->fechaCom = fechaCom;
}

string DTComentario::getText()
{
  return this->text;
};

int DTComentario::getId()
{
  return this->id;
};

 DTFecha DTComentario::getFechaCom()
 {
  return this->fechaCom;
 };


// DTUsuario
DTUsuario::DTUsuario(){}
DTUsuario::DTUsuario(string nickname, string contrasena, DTFecha fechaNac)
{
  this->nickname = nickname;
  this->contrasena = contrasena;
  this->fechaNac = fechaNac;
};

string DTUsuario::getNickname() const
{
  return this->nickname;
};


//DTFecha DTUsuario::getFechaNac() const
//{
//  return this->fechaNac;
//};


bool DTUsuario::operator<(const DTUsuario& otro) const{
    return (this->nickname < otro.nickname); 
};

//DTCliente
DTCliente::DTCliente(){};
DTCliente::DTCliente(string nickname, string contrasena, DTFecha fechaNac, string ciudad, string direccion)
{
  this->nickname = nickname;
  this->contrasena = contrasena;
  this->fechaNac = fechaNac;
  this->ciudad = ciudad;
  this->direccion = direccion;
};

string DTCliente::getNickname() const{
  return this->nickname;
};

DTFecha DTCliente::getFechaNac() const{
return this->fechaNac;
};
  
string DTCliente::getCiudad(){
  return this->ciudad;
};

string DTCliente::getDireccion(){
  return this->direccion;
};

//DTVendedor
DTVendedor::DTVendedor(){};
DTVendedor::DTVendedor(string nickname, string contrasena, DTFecha fechaNac, string codigoRUT)
{
  this->nickname = nickname;
  this->contrasena = contrasena;
  this->fechaNac = fechaNac;
  this->codigoRUT = codigoRUT;
};

string DTVendedor::getNickname() const{
  return this->nickname;
};

DTFecha DTVendedor::getFechaNac() const{
  return this->fechaNac;
};
  
string DTVendedor::getCodigoRUT(){
  return this->codigoRUT;
};




//DTNotificacion
DTNotificacion::DTNotificacion(string nicknameUsuario, string nombreProm,set<DTProducto> productos){
  this->nicknameUsuario = nicknameUsuario;
  this->nombreProm = nombreProm;
  this->productos = productos;
};

string DTNotificacion::getNicknameUsuario()
{
  return this->nicknameUsuario;
};

string DTNotificacion::getNombreProm()
{
  return this->nombreProm;
};

set<DTProducto> DTNotificacion::getProductos()
{
  return this->productos;
};
   
//DTCompra
DTCompra::DTCompra(float precioTotal, DTFecha fechaCompra, set<DTCompra_Producto> comProd)
{
  this->precioTotal = precioTotal;
  this->fechaCompra = fechaCompra;
  this->comProd = comProd;
};

float DTCompra::getPrecioTotal()
{
  return this->precioTotal;
};

DTFecha DTCompra::getFecha()
{
  return this->fechaCompra;
};

set<DTCompra_Producto> DTCompra::getProdProm()
{
  return this->comProd;
};


//DTProducto
DTProducto::DTProducto(int id, categoria cat, string nombre, string desc, int cantStock, float precio)
{
  this->id = id;
  this->cat = cat;
  this->nombre = nombre;
  this->descripcion = desc;
  this->cantStock = cantStock;
  this->precio = precio;
};

string DTProducto::getNombre()
{
  return this->nombre;
};

int DTProducto::getId()
{
  return this->id;
};

categoria DTProducto::getCat()
{
  return this->cat;
};

string DTProducto::getDesc()
{
  return this-> descripcion;
};

int DTProducto::getCantStock()
{
  return this->cantStock;
};

float DTProducto::getPrecio()
{
  return this->precio;
};

bool DTProducto::getEstaEnProm()
{
  return this->estaEnProm;
};

bool DTProducto::operator<(const DTProducto& otro) const{
    return (this->id < otro.id); 
};