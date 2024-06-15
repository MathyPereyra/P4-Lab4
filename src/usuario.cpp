#include "../include/usuario.h"

#include <string>

using namespace std;

Usuario::Usuario(string nickname, string contrasena, DTFecha fechaNac)
  : nickname(nickname), contrasena(contrasena), fechaNac(fechaNac){}

string Usuario::getNickname() {
  return this->nickname;
};

string Usuario::getContrasena() {
   return this->contrasena;
};

DTFecha Usuario::getFechaNac() {
   return this->fechaNac;
};


//set<DTComentario> Usuario::listadoComentarioUsuario()
//{
//  //  set<DTComentario> listadoComens;
//  //  for (Comentario comen : this->comentarios)
//  //  {
//  //    DTComentario dataComentario = DTComentario(comen.getText(), comen.getId(), comen.getFecha());
//  //    listadoComens.insert(dataComentario);
//  //  }
//  //  return listadoComens;
//}
//
//DTUsuario Usuario::getDatosUsuario()
//{
//  //  DTUsuario DataUsuario
//}
//
//set<Comentario> Usuario::getComentarios()
//{
//  //  DTComentario
//}