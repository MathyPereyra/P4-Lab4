#ifndef DATATYPES_H
#define DATATYPES_H

#include <iostream>
#include <string>
#include <set>
#include <map>


using namespace std;

//DTFecha
class DTFecha
{
private:
  int dia;
  int mes;
  int anio;

public:
  // Constructor
  DTFecha();
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
  DTFecha getFechaNac() const;
  virtual void print();
  friend ostream &operator<<(ostream &os, const DTUsuario &ie);    // Sobrecarga del operador << para imprimir DTInfoEstudiante


  virtual ~DTUsuario();
};


//DTCliente
class DTCliente : public DTUsuario
{
private:
  string ciudad;
  string direccion;

public:
  DTCliente();
  DTCliente(string nickname, string constrasena, DTFecha fechaNac, string ciudad, string direccion);

  string getNickname() const;
  DTFecha getFechaNac() const;
  string getCiudad();
  string getDireccion();
  friend ostream &operator<<(ostream &os, const DTCliente &dtC)
  {  
    os << "Nickname: "<<dtC.getNickname() << ", Fecha: " << dtC.getFechaNac().getDia() << "/" << dtC.getFechaNac().getMes() << "/" << dtC.getFechaNac().getAnio() << "\n Ciudad:" << dtC.ciudad << ", Direccion: " << dtC.direccion << "/n" ;
    return os;
  }

  virtual void print();
  virtual ~DTCliente();
};


//DTVendedor
class DTVendedor : DTUsuario
{
private:
  string codigoRUT;

public:
  DTVendedor();
  DTVendedor(string nickname, string contrasena, DTFecha fechaNac, string codigoRUT);
  
  string getNickname() const;
  DTFecha getFechaNac() const;
  string getCodigoRUT();

  friend ostream &operator<<(ostream &os, const DTVendedor &dtV)
  {  
    os << "Nickname: "<<dtV.getNickname() << ", Fecha: " << dtV.getFechaNac().getDia() << "/" << dtV.getFechaNac().getMes() << "/" << dtV.getFechaNac().getAnio() << "\n Codigo RUT:" << dtV.codigoRUT << "\n" ;
    return os;
  }


  virtual void print();
  virtual ~DTVendedor();
};


//DTComentario
class DTComentario
{
private:
  string text;
  int id;
  DTFecha fechaCom;

public:
  DTComentario(string text, int id, DTFecha fechaCom);
  string getText();
  int getId();
  DTFecha getFechaCom();

  virtual ~DTComentario();
};


//Enumerados categoria 
enum categoria
{
  ropa,
  electrodomesticos,
  otro
};



//DTProducto
class DTProducto
{
private:
  int id;
  categoria cat;
  string nombre;
  string descripcion;
  int cantStock;
  float precio;
  bool estaEnProm;

public:
  DTProducto();
  DTProducto(int id, categoria cat, string nombre, string desc, int cantStock, float precio);

  int getId();
  categoria getCat();
  string getDesc();
  int getCantStock();
  float getPrecio();
  bool getEstaEnProm();

  virtual ~DTProducto();
};


//DTNotificacion
class DTNotificacion
{
private:
  string nicknameUsuario;
  string nombreProm;
  set<DTProducto> productos;

public:
  DTNotificacion(string nicknameUsuario, string nombreProm, set<DTProducto> productos);

  string getNicknameUsuario();
  string getNombreProm();
  set<DTProducto> getProductos();

  virtual ~DTNotificacion();
};


class DTCompra_Producto
{
private:
  int cantidad;
  bool envio;
  set<DTProducto> productos;
public:
  DTCompra_Producto(int cantidad, bool envio);

  int getCantidad();
  bool getEnvio();
  set<DTProducto> getProductos();

  virtual ~DTCompra_Producto();
};


//DTCompra
class DTCompra
{
private:
  float precioTotal;
  DTFecha fechaCompra;
  set<DTCompra_Producto> comProd;

public:
  DTCompra(float precioTotal, DTFecha fechaCompra, set<DTCompra_Producto> comProd);
  float getPrecioTotal();
  DTFecha getFecha();
  set<DTCompra_Producto> getProdProm();

  virtual ~DTCompra();
};


class DTIdNProducto
{
private:
  int id;
  string nombre;

public:
  DTIdNProducto(int id, string nombre);

  int getId();
  string getNombre();

  virtual ~DTIdNProducto();
};






#endif

