#ifndef DATATYPES_H
#define DATATYPES_H

#include <iostream>
#include <string>
#include <set>
#include <map>

using namespace std;

class DTFecha
{
private:
  int dia;
  int mes;
  int anio;

public:
  // Constructor
  DTFecha(int dia, int mes, int anio);

  // getters
  int getDia() const;
  int getMes() const;
  int getAnio() const;

  // setters
  void setDia(int dia);
  void setMes(int mes);
  void setAnio(int anio);

  // Comparacion entre fechas
  bool operator>=(const DTFecha fecha) const;
};

class DTUsuario
{
private:
  string nickname;
  string contrasena;
  DTFecha fechaNac;

public:
  DTUsuario();
  DTUsuario(string nickname, string nombre, string descripcion);
  string getNickname() const;
  string getContrasena() const;
  DTFecha getFechaNac() const;
  virtual void print();
  virtual ~DTUsuario();
};

class DTComentario
{
private:
  string nickname;
  string contrasena;
  DTFecha fechaNac;

public:
  DTComentario();
};

#endif
