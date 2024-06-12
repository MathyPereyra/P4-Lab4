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
  DTFecha fechaNac;

public:
  DTUsuario();
  DTUsuario(string nickname, DTFecha fechaNac);
  string getNickname() const;
  string getContrasena() const;
  DTFecha getFechaNac() const;
  virtual void print();
  virtual ~DTUsuario();
};

class DTCliente
{
private:
  string nickname;
  DTFecha fechaNac;
  string ciudad;
  string direccion;

public:
  DTUsuario();
  DTUsuario(string nickname, DTFecha fechaNac, string ciudad, string direccion);
  
  string getNickname() const;
  DTFecha getFechaNac() const;
  string getCiudad();
  string getDireccion();
  virtual void print();
  virtual ~DTUsuario();
};

class DTVendedor
{
private:
  string nickname;
  DTFecha fechaNac;
  string codigoRUT;

public:
  DTUsuario();
  DTUsuario(string nickname, DTFecha fechaNac, string codigoRUT);
  string getNickname() const;
  DTFecha getFechaNac() const;
  string getCodigoRUT();
  virtual void print();
  virtual ~DTUsuario();
};


class DTComentario
{
private:
  string text;
  integer id;
  DTFecha fechaCom;

public:
  DTComentario(string text, integer id, DTFecha fechaCom);
  string getText();
  integer getId();
  DTFecha getFechaCom();

  virtual ~DTComentario();
};

enum categoria {ropa, electrodomesticos, otro}


class DTProducto
{
private:
  integer id;
  categoria cat;
  string descripcion;
  integer cantStock;
  float precio;
public:
  DTProducto();
  DTProducto(integer id, categoria cat, string desc, integer cantStock, float precio);
  integer getId();
  categoria getCat();
  string getDesc();
  integer getCantStock();
  float getPrecio();
  virtual ~DTProducto();
};

class DTNotificacion
{
  private:
    string nicknameUsuario;
    string nombreProm;
    set<DTProductopr>
oductos;
  public:
    DTNotificacion(string nicknameUsuario, string nombreProm,set<DTProducto> productos);
    string getNicknameUsuario();
    string getNombreProm();
    set<DTProducto> getProductos();
    virtual ~DTNotificacion();}:

class DTCompra
{
private:
  float precioTotal;
  DTFecha fechaCompra;
  set<Compra_Producto> com-Prod;
public:

  DTCompra(float precioTotal, DTFecha fechaCompra, set<Compra_Producto> com-Prod);
  float getPrecioTotal();
  DTFecha getFecha();
  set<Com-Prod> getProdProm();

  virtual ~DTCompra();};

class DTIdNProducto
{
private:
  integer id;
  string nombre;
public:
  DTIdNProducto(integer id, string nombre);
  intger getId();
  string getNombre()

  virtual ~DTIdNProducto;
}

#endif
