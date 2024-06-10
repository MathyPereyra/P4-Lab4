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

// DTUsuario
class DTUsuario
{
private:
  string nickname;
  string contrasena;
  DTFecha fechaNac;

public:
  DTUsuario();
  DTUsuario(string nickname, string contrasena, DTFecha fechaNac);
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

enum categoria {electrodomestico,,}


class DTProducto
{
private:
  integer id;
  categoria cat;
  string descripcion;
  nombre string;
  integer cantStock;
  float precio;
public:
  DTProducto();
  DTProducto(integer id, categoria cat, string desc, string nombre, integer cantStock, float precio);
  integer getId();
  categoria getCat();
  string getDesc();
  integer getCantStock();
  float getPrecio();
  virtual ~DTProducto();
}

class DTNotificacion
{

}












#endif
