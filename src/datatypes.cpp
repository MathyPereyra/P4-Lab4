#include "../include/datatypes.h"
#include "datatypes.h"

// DTFecha
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
DTComentario::DTComentario(string text, int id, DTFecha fechaCom);
{
  this->text = text;
  this->id = id;
  this->fechaCom = fechaCom;
};

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
DTUsuario::DTUsuario(string nickname, string contrasena, DTFecha fechaNac, tipo tipocliente)
{
  this->nickname = nickname;
  this->contrasena = contrasena;
  this->fechaNac = fechaNac;
  this->tipo = tipocliente;
};

string DTUsuario::getNickname() const
{
  return this->nickname;
};

string DTUsuario::getContrasena() const
{
  return this->contrasena;
};

DTFecha DTUsuario::getFechaNac() const
{
  return this->fechaNac;
};

string DTUsuario::getTipo() const
{
  return this->tipo;
};

void DTUsuario::print()
{
  cout << "Nickname: " << this->nickname << endl;
  cout << "Contraseña: " << this->contrasena << endl;
  cout << "Fecha de nacimiento: " << this->fechaNac << endl;
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
DTCompra::DTCompra(float precioTotal, DTFecha fechaCompra, set<Compra_Producto> com-Prod)
{
  this->precioTotal = precioTotal;
  this->fechaCompra = fechaCompra;
  this->com-Prod = com-Prod;
};

float DTCompra::getPrecioTotal()
{
  return this->precioTotal
};

DTFecha DTCompra::getFecha()
{
  return this->fechaCompra;
};

set<Com-Prod> DTCompra::getProdProm()
{
  return this->com-prod;
};