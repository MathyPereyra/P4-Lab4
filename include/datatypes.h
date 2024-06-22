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
protected:
  string nickname;
  string contrasena;
  DTFecha fechaNac;

public:
  DTUsuario();
  DTUsuario(string nickname, string contrasena, DTFecha fechaNac);
  string getNickname() const;
  DTFecha getFechaNac() const;

  virtual string getCodigoRUT()  { return "Usuario"; }
  virtual int getTipo()  { return 2; } // devuelve 1 si es cliente o 2 si es vendedor
  virtual string getCiudad()  { return "Usuario"; }
  virtual string getDireccion()  { return "Usuario"; }

  

  friend ostream &operator<<(ostream &os, const DTUsuario &dtU) 
  {  
    os << "Nickname: "<< dtU.getNickname() << ", Fecha: " << dtU.getFechaNac().getDia() << "/" << dtU.getFechaNac().getMes() << "/" << dtU.getFechaNac().getAnio() << "\n" ;
    return os;
  }
  
  bool operator<(const DTUsuario& otro) const;   // Comparacion entre DTUsuario

  virtual ~DTUsuario(){};
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

  string getNickname() const ;
  DTFecha getFechaNac() const ;
  string getCiudad()    override{
    return this->ciudad;
  };

  string getDireccion()   override{
    return this->direccion;
  };

  int getTipo()    override
  {
    return 1;
  };

  friend ostream &operator<<(ostream &os, const DTCliente &dtC)
  {  
    os << "Nickname: "<<dtC.getNickname() << ", Fecha: " << dtC.getFechaNac().getDia() << "/" << dtC.getFechaNac().getMes() << "/" << dtC.getFechaNac().getAnio() << "\n Ciudad:" << dtC.ciudad << ", Direccion: " << dtC.direccion << "\n" ;
    return os;
  }

  virtual ~DTCliente(){};
};


//DTVendedor
class DTVendedor : public DTUsuario
{
private:
  string codigoRUT;

public:
  DTVendedor();
  DTVendedor(string nickname, string contrasena, DTFecha fechaNac, string codigoRUT);
  
  string getNickname() const;
  DTFecha getFechaNac() const;

  
  string getCodigoRUT()  override {
    return this->codigoRUT;
  };

  int getTipo()  override
  {
    return 2;
  };

  friend ostream &operator<<(ostream &os, const DTVendedor &dtV)
  {  
    os << "Nickname: " << dtV.getNickname() << ", Fecha: " << dtV.getFechaNac().getDia() << "/" << dtV.getFechaNac().getMes() << "/" << dtV.getFechaNac().getAnio() << "\n Codigo RUT:" << dtV.codigoRUT << "\n" ;
    return os;
  }


  virtual ~DTVendedor(){};
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
  string getText()  const;
  int getId() const;
  DTFecha getFechaCom() const;
  bool operator<(const DTComentario este) const;

  virtual ~DTComentario(){};
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

  string getNombre() const;
  int getId() const;
  categoria getCat()  const;
  string getDesc()  const;
  int getCantStock()  const;
  float getPrecio() const;
  bool getEstaEnProm()  const;
  bool operator<(const DTProducto& otro) const;   // Comparacion entre DTProducto
  friend ostream &operator<<(ostream &os, const DTProducto &dtP)
  {  
    os << "ID: "<< dtP.id << ", Nombre: " << dtP.nombre<< ", Cantidad en stock: " << dtP.cantStock << ", Precio: " << dtP.precio << ", Categoria: " << dtP.cat<<"\n" ;
    return os;
  }
  virtual ~DTProducto(){};
};


//DTNotificacion
class DTNotificacion
{
private:
  string nicknameUsuario;
  string nombreProm;
  set<DTProducto> productos;

public:
  DTNotificacion();
  DTNotificacion(string nicknameUsuario, string nombreProm, set<DTProducto> productos);

  string getNicknameUsuario() const;
  string getNombreProm();
  set<DTProducto> getProductos();

  bool operator<(const DTNotificacion este) const;

  virtual ~DTNotificacion(){};
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

  virtual ~DTCompra_Producto(){};
};


//DTCompra
class DTCompra
{
private:
  float precioTotal;
  DTFecha fechaCompra;
  set<DTProducto> productos;

public:
  DTCompra(float precioTotal, DTFecha fechaCompra, set<DTProducto> comProd);
  float getPrecioTotal();
  DTFecha getFecha();
  set<DTProducto> getProductos();

  virtual ~DTCompra(){};
};



// DTPROMOCION

class DTPromocion 
{
private:
  string nombre;
  string descripcion;
  float descuento;
  DTFecha fechaVencimiento;
  string nicknameVendedor;

public:
  DTPromocion();
  DTPromocion(string nombre, string descripcion, float descuento, DTFecha fechaVencimiento, string nicknameV);

  string getNombre()  const;
  string getDescripcion() const;
  float getDescuento()  const;
  DTFecha getFechaVen() const;
  string getNicknameVendedor() const;

  bool operator<(const DTPromocion& otro) const;   // Comparacion entre DTProducto


  virtual ~DTPromocion(){};
};


#endif

