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

string DTComentario::getText() const
{
  return this->text;
};

int DTComentario::getId() const
{
  return this->id;
};

 DTFecha DTComentario::getFechaCom() const
 {
  return this->fechaCom;
 };

 bool DTComentario::operator<(const DTComentario este) const
 {
    return this->getId() < este.getId();
 }


// DTUsuario
DTUsuario::DTUsuario(){}
DTUsuario::DTUsuario(string nickname, string contrasena, DTFecha fechaNac) : nickname(nickname) , contrasena(contrasena), fechaNac(fechaNac) {}


string DTUsuario::getNickname() const
{
  return this->nickname;
};


DTFecha DTUsuario::getFechaNac() const
{
  return this->fechaNac;
};


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

string DTCliente::getNickname()  const {
  return this->nickname;
};

DTFecha DTCliente::getFechaNac() const{
return this->fechaNac;
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



//DTNotificacion
DTNotificacion::DTNotificacion(){}

DTNotificacion::DTNotificacion(string nicknameUsuario, string nombreProm,set<DTProducto> productos){
  this->nicknameUsuario = nicknameUsuario;
  this->nombreProm = nombreProm;
  this->productos = productos;
};

string DTNotificacion::getNicknameUsuario()  const
{
  return this->nicknameUsuario;
};

string DTNotificacion::getNombreProm() const
{
  return this->nombreProm;
};

set<DTProducto> DTNotificacion::getProductos()
{
  return this->productos;
};
   

bool DTNotificacion::operator<(const DTNotificacion este) const
{
   return this->getNombreProm() < este.getNombreProm();
}



//DTCompra

DTCompra::DTCompra(float precioTotal, DTFecha fechaCompra, set<DTProducto> productos, int id)
{
  this->precioTotal = precioTotal;
  this->fechaCompra = fechaCompra;
  this->productos = productos;
  this->id = id;
};

DTCompra::DTCompra(float precioTotal, DTFecha fechaCompra, int id)
{
  this->precioTotal = precioTotal;
  this->fechaCompra = fechaCompra;
  this->id = id;
};

float DTCompra::getPrecioTotal()
{
  return this->precioTotal;
};

DTFecha DTCompra::getFecha()
{
  return this->fechaCompra;
};

set<DTProducto> DTCompra::getProductos()
{
  return this->productos;
};

//DTProducto
DTProducto::DTProducto(){};

DTProducto::DTProducto(int id, categoria cat, string nombre, string desc, int cantStock, float precio)
{
  this->id = id;
  this->cat = cat;
  this->nombre = nombre;
  this->descripcion = desc;
  this->cantStock = cantStock;
  this->precio = precio;
};

string DTProducto::getNombre() const
{
  return this->nombre;
};

int DTProducto::getId() const
{
  return this->id;
};

categoria DTProducto::getCat()  const
{
  return this->cat;
};

string DTProducto::getDesc()  const
{
  return this-> descripcion;
};

int DTProducto::getCantStock()  const
{
  return this->cantStock;
};

float DTProducto::getPrecio() const
{
  return this->precio;
};

bool DTProducto::getEstaEnProm()  const
{
  return this->estaEnProm;
};

bool DTProducto::operator<(const DTProducto& otro) const{
    return (this->id < otro.id); 
};

//DTPROMOCION
DTPromocion::DTPromocion(){};

DTPromocion::DTPromocion(string nombre, string descripcion, float descuento, DTFecha fechaVencimiento, string nicknameVendedor) :
nombre(nombre), descripcion(descripcion), descuento(descuento), fechaVencimiento(fechaVencimiento), nicknameVendedor(nicknameVendedor){};

string DTPromocion::getNombre() const
{
  return this->nombre;
}

string DTPromocion::getDescripcion()  const
{
  return this->descripcion;
}

float DTPromocion::getDescuento() const
{
  return this->descuento;
}

DTFecha DTPromocion::getFechaVen()  const
{
  return this->fechaVencimiento;
}

string DTPromocion::getNicknameVendedor() const
{
  return this->nicknameVendedor;
}

bool DTPromocion::operator<(const DTPromocion& otro) const
{ 
  return this->getNicknameVendedor() > otro.getNicknameVendedor();
}                                                              
// Comparacion entre DTProducto
