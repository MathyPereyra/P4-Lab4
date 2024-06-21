#ifndef CNOTIFICACION_H
#define CNOTIFICACION_H

#include <string>
#include <set>

#include "CUsuario.h"
#include "IUsuario.h"

#include "usuario.h"
#include "INotificacion.h"

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


    set<DTVendedor> listarVendedoresNoSuscritos(string nickname);
    void suscribirAVendedor(string nickname, set<DTVendedor> suscritos);
    set<DTVendedor> mostrarSuscripciones(string nickname);
    set<DTNotificacion> mostrarNotificaciones(string nickname, IUsuario * contUsuario);
    void eliminarNotificacion();
    set<DTVendedor> listarVendedoresSuscritos(string nickname);
    void eliminarSuscripciones(string nickname, set<DTVendedor> vendedores);


    // Operaciones internas

    virtual ~ControladorNotificacion(){};
};

#endif