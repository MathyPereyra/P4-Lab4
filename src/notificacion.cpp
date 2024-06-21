#include "../include/notificacion.h"
#include <string>

using namespace std;

Notificacion::Notificacion(){}

Notificacion::Notificacion(string nicknameV, string nombreProm, map<int, Producto*> productos)
  : nicknameV(nicknameV),nombreProm(nombreProm), productos(productos) {}

string Notificacion::getNicknameV(){
  return this->nicknameV;
};

string Notificacion::getNombreProm(){
  return this->nombreProm;
};

map<int, Producto *> Notificacion::getProductos(){
  return this->productos;
};