#ifndef CFECHA_H
#define CFECHA_H

 #include "IFecha.h"
 #include <string>


using namespace std;

class ControladorFecha : public IFecha
{
private:
    int dia;
    int mes;
    int anio;
    static ControladorFecha *instancia;
    ControladorFecha();
  

public:
  void setFecha(int dia, int mes, int anio);
  DTFecha getFecha();

  static ControladorFecha *getInstanciaFecha();
  // Operaciones externas

  virtual ~ControladorFecha(){};
};

#endif
