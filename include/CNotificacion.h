#ifndef CNOTIFICACION_H
#define CNOTIFICACION_H

#include <string>
#include <set>

#include "datatypes.h"
#include "usuario.h"

using namespace std;

class ControladorNotificacion : public INotificacion
{
private:
    static ControladorNotificacion * instancia;
    ControaldorNotificacion();

public:
    static ControladorNotificacion * getInstancia();
    // Operaciones externas
    set<DTVendedor> listarVendedoresNoSuscritos(string nickname);
    void suscribirAVendedor(string nickname, set<DTVendedor> suscritos);
    set<DTVendedor> mostrarSuscripciones(string nickname);
    void eliminarNotificacion();
    set<DTVendedor> listarVendedoresSuscritos(string nickname)
    void eliminarSuscripciones(string nickname, set<DTVendedor> vendedores);
    //aca no pusimos datadetallecompra al final
    DTCompra detallesCompra();
    void confirmarCompra();

    // Operaciones internas

    virtual ~ControladorNotificacion(){};
};

#endif