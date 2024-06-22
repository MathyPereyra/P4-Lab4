#ifndef CNOTIFICACION_H
#define CNOTIFICACION_H

#include "INotificacion.h"
#include <string>
#include <set>



using namespace std;

class ControladorNotificacion : public INotificacion
{
private:
    static ControladorNotificacion * instancia;
    ControladorNotificacion();
    Usuario * memUsuario;
    IUsuario * contUsuario;

public:
    static ControladorNotificacion * getInstanciaN();
    Usuario * getMemUsuario();
    void setMemUsuario(Usuario * usuario);
    void setControladorUsuario(IUsuario * contUsuario);
    IUsuario * getControladorUsuario();

    // Operaciones externas


    set<DTUsuario*> listarVendedoresNoSuscritos(string nickname);
    void suscribirAVendedor(string nicknameC, string nicknameV);
    //set<DTVendedor> mostrarSuscripciones(string nickname);
    set<DTNotificacion> mostrarNotificaciones(string nickname);
    void eliminarNotificacion();
    set<DTUsuario*> listarVendedoresSuscritos(string nickname);
    void eliminarSuscripcion(string nicknameC, string nicknameV);


    // Operaciones internas

    virtual ~ControladorNotificacion(){};
};

#endif