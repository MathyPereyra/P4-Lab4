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
DTComentario::DTComentario(){

};

// DTUsuario
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

string DTUsuario::getContrasena() const
{
  return this->contrasena;
};

DTFecha DTUsuario::getFechaNac() const
{
  return this->fechaNac;
};

void DTUsuario::print()
{
  cout << "Nickname: " << this->nickname << endl;
  cout << "Contraseña: " << this->contrasena << endl;
  cout << "Fecha de nacimiento: " << this->fechaNac << endl;
};
