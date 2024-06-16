#include <string>
#include <set>
// #include <map>
#include <iostream>

#include "include/CUsuario.h"
#include "include/IVenta.h"
#include "include/comentario.h"
#include "include/datatypes.h"
#include "include/fabrica.h"
#include "include/IUsuario.h"
#include "include/usuario.h"
#include "include/vendedor.h"
#include "CUsuario.h"
// #include "include/observer.h"
// #include "include/producto.h"
// #include "include/promocion.h"
// #include "include/compra_producto.h"
// #include "include/compra.h"
// #include "include/vendedor.h"
// DTUsuario#include "include/cliente.h"
// #include "include/producto.h"

using namespace std;

void altaDeUsuario(IUsuario *controlador)
{
    string nickname, contrasena;
    int dia, mes, anio;
    cout << "Ingrese nickname:";
    cin >> nickname;
    cout << "\nIngrese contasena: ";
    cin >> contrasena;
    cout << "\nIngrese dia: ";
    cin >> dia;
    cout << "\nIngrese mes: ";
    cin >> mes;
    cout << "\nIngrese anio: ";
    cin >> anio;
    DTFecha fecha(dia, mes, anio);
    controlador->ingresarUsuario(nickname, contrasena, fecha);
    if (controlador->existeUsuarioIgualNickname(nickname))
    {
        cout << "\nNickname ya existe, intente nuevamente. ";
        controlador->terminarAlta();
        altaDeUsuario(controlador);
        return;
    }
    cout << "\nIngrese 1 si va a ingresar un cliente o 2 si va a ingresar un vendedor: ";
    int opcion;
    cin >> opcion;
    switch (opcion)
    {
    case 1:
    {
        cout << "\nIngrese direccion: ";
        string direccion;
        cin >> direccion;
        cout << "\nIngrese ciudad: ";
        string ciudad;
        cin >> ciudad;
        controlador->altaCliente(direccion, ciudad);
    }
    break;

    case 2:
    {
        cout << "\nIngrese codigoRUT: ";
        string codigoRUT;
        cin >> codigoRUT;
        controlador->altaVendedor(codigoRUT);
    }
    break;
    }
    controlador->confirmarAltaUsuario();
    return;
}

void listadoDeUsuarios(IUsuario *controlador)
{
    set<DTUsuario> dataUsuarios;
    dataUsuarios = controlador->listadoUsuarios();
    for (DTUsuario usuario : dataUsuarios)
    {
        cout << usuario << "\n";
    }
}

void altaDeProducto(IUsuario *controladorU, IVenta *controladorV)
{
    set<DTUsuario> dataVendedores;
    dataVendedores = controladorU->listadoUsuarios("vendedor");
    for (DTUsuario vendedor : dataVendedores)
    {
        cout << vendedor.getNickname() << "\n";
    }
    string nicknameV, nombreP, descripcionP;
    float precioP;
    int cantStockP, opcion;
    categoria cat;
    cout << "Elija un vendedor: ";
    cin >> nicknameV;
    cout << "\n"
         << "Ingrese nombre : ";
    cin >> nombreP;
    cout << "\n"
         << "Ingrese descripcion : ";
    cin >> descripcionP;
    cout << "\n"
         << "Ingrese precio : ";
    cin >> precioP;
    cout << "\n"
         << "Ingrese cantidad en stock: ";
    cin >> cantStockP;
    cout << "\n"
         << "Ingrese 1 si es electrodomestico, 2 si es ropa, 3 si es otro: ";
    cin >> opcion;
    switch (opcion)
    {
    case 1:
        cat = electrodomesticos;
        break;
    case 2:
        cat = ropa;
        break;
    case 3:
        cat = otro;
        break;
    }
    Usuario *usuario = controladorU->obtenerUsuarioPorNickname(nicknameV);
    Vendedor *vendedor = dynamic_cast<Vendedor *>(usuario);
    if (vendedor != NULL)
    {
        controladorV->crearProducto(vendedor, nombreP, descripcionP, precioP, cantStockP, cat);
    }
}

void consultarProducto(IVenta *controladorV)
{
    int idProducto;
    set<DTProducto> dataProductos;
    dataProductos = controladorV->listadoProductos();
    for (DTProducto producto : dataProductos)
    {
        cout << "Id: " << producto.getId() << "\n";
        cout << "Categoria: " << producto.getCat() << "\n";
        cout << "Nombre: " << producto.getNombre() << "\n";
        cout << "Descripcion: " << producto.getDesc() << "\n";
        cout << "Cantidad en stock: " << producto.getCantStock() << "\n";
        cout << "Precio: " << producto.getPrecio() << "\n";
        cout << "Nombre: " << producto.getNombre() << "\n";
    }

    cout << "Seleccione un Producto con su id: ";
    cin >> idProducto;

    Producto *productoConsultado = controladorV->seleccionarProductoPorId(idProducto);
}

void dejarComentario(IUsuario *controladorU, IVenta *controladorV)
{
    // lista usuarios y selecciona uno
    string nicknameU, textoC;
    int idP;
    set<DTUsuario> dataUsuarios;
    dataUsuarios = controladorU->listadoUsuarios();

    for (DTUsuario usuario : dataUsuarios)
    {
        cout << usuario.getNickname() << "\n";
    }
    cout << "Seleccione un Usuario: ";
    cin >> nicknameU;

    // lista productos y selecciona uno
    set<DTProducto> dataProductos;
    dataProductos = controladorV->listadoProductos();

    for (DTProducto producto : dataProductos)
    {
        cout << "Id: " << producto.getId() << "\n";
        cout << "Nombre: " << producto.getNombre() << "\n";
        cout << "Categoria: " << producto.getCat() << "\n";
        cout << "Descripcion: " << producto.getDesc() << "\n";
        cout << "Cantidad en stock: " << producto.getCantStock() << "\n";
        cout << "Precio: " << producto.getPrecio() << "\n";
    }
    cout << "Seleccione un Producto con su id: ";
    cin >> idP;

    cout << "\nIngrese 1 si desea realizar un comentario nuevo o 2 si desea responder a un comentario existente: ";
    int opcion;
    cin >> opcion;
    switch (opcion)
    {
    case 1:
    {
        cout << "Ingrese el texto del comentario: ";
        cin >> textoC;
        Producto *seleccionado = controladorV->seleccionarProductoPorId(idP);
        controladorU->crearComentario(textoC, seleccionado);
    }
    break;

    case 2:
    {
        map<int, Comentario *>::iterator it;
        for (it = seleccionado->comentarios.begin(); it != seleccionado->comentarios.end(); ++it)
        {
            cout << "Id comentario: " << it->second->getId() << "\n";
            cout << "Comentario: " << it->second->getText() << "\n";
        }
    }
    break;
    }
}

void eliminarComentario(IUsuario *controladorU)
{
    set<DTUsuario> dataUsuarios;
    dataUsuarios = controladorU->listadoUsuarios();

    for (DTUsuario usuario : dataUsuarios)
    {
        cout << usuario.getNickname() << "\n";
    }
    string usuarioSeleccionado;
    cout << "Ingrese el nickname del usuario que desee borrar un comentario: \n";
    cin >> usuarioSeleccionado;

    Usuario *usuario = controladorU->obtenerUsuarioPorNickname(usuarioSeleccionado);
    controladorU->recordarUsuario(usuario);
    map<int, Comentario *> comentarios;
    comentarios = usuario->getComentarios();
    cout << "Listado de Comentarios de " << usuarioSeleccionado << "\n";
    for (map<int, Comentario *>::const_iterator it = comentarios.begin(); it != comentarios.end(); ++it)
    {
        cout << "ID: " << it->second->getId() << " ";
        cout << "Contenido: " << it->second->getText() << " \n";
        cout << "Fecha: " << it->second->getFecha().getDia() << "/" << it->second->getFecha().getMes() << "/" << it->second->getFecha().getAnio() << "\n";
    }
    cout << "Ingrese ID del comentario a eliminar: ";
    int id;
    cin >> id;
    cout << "\n";
    controladorU->eliminarComentario(id);
    cout << "Comentario " << id << "eliminado. ";
}

void expedienteDeUsuario(IUsuario *controlador)
{
    string nicknameU;

    cout << "Usuarios registrados:\n";
    set<DTUsuario> dataUsuarios;
    dataUsuarios = controlador->listadoUsuarios();
    for (DTUsuario usuario : dataUsuarios)
    {
        cout << usuario.getNickname() << "\n";
    }

    cout << "Seleccione un usuario: ";
    cin >> nicknameU;
    Usuario *usuario;
    usuario = controlador->obtenerUsuarioPorNickname(nicknameU);
    DTUsuario dataUsuario;
    dataUsuario = usuario->getDatosUsuario();
    cout << "Datos del usuario seleccionado:\n"
         << dataUsuario << endl;

    Vendedor *vendedor = dynamic_cast<Vendedor *>(usuario);
    if (vendedor != NULL)
    {
        // lista todos los productos del vendedor
        map<int, Producto *> productos = vendedor->getProductos();
        cout << "Productos del vendedor " << vendedor->getNickname() << ": \n"
             << endl;

        for (map<int, Producto *>::const_iterator it = productos.begin(); it != productos.end(); ++it)
        {
            Producto *producto = it->second;
            cout << producto->getDataProducto().getNombre() << endl;
        }

        // Lista todos las promociones activas
        set<Promocion> promociones = vendedor->getPromociones();
        cout << "\nPromociones del vendedor " << vendedor->getNickname() << ": \n"
             << endl;

        for (std::set<Promocion>::const_iterator it = promociones.begin(); it != promociones.end(); ++it)
        {
            Promocion promocion = *it;
            std::cout << promocion.getNombre() << std::endl; // Mostrar el nombre de la promoción
        }
    }
    else
    {
        // El usuario no es de tipo Vendedor
    }
}

int main()
{

    Fabrica *fabrica = Fabrica::getInstanceF();      // se crea instancia única de fábrica
    IUsuario *controladorU = fabrica->getIUsuario(); // se crea la instancia del controlador CUsuario de tipo IUsuario
    IVenta *contraladorV = fabrica->getIVenta();
    contraladorV->setContador();

    int opcion;
    bool continuar = true;
    while (continuar)
    {
        cout << "   Presione un numero para elegir un caso de uso: " << endl;
        cout << "1: Alta de usuario" << endl
             << "2: Listado de usuarios" << endl
             << "3: Alta de producto" << endl
             << "4: Consultar producto" << endl
             << "5: Crear promocion" << endl
             << "6: Consultar promocion" << endl
             << "7: Realizar compra" << endl
             << "8: Dejar comentario" << endl
             << "9: Eliminar comentario" << endl
             << "10: Enviar producto" << endl
             << "11: Expediente de Usuario" << endl
             << "12: Suscribirse a notificaciones" << endl
             << "13: Consulta de notificaciones" << endl
             << "14: Eliminar suscripciones" << endl
             << "15: Terminar programa" << endl;
        cout << "Ingrese el numero correspondiente al caso de uso a ejecutar: ";
        cin >> opcion;
        switch (opcion)
        {
        case 1:
            cout << "Ejecutando caso de uso: Alta de usuario" << endl;
            altaDeUsuario(controladorU);
            break;

        case 2:
            cout << "Ejecutando caso de uso: Listado de usuarios" << endl;
            listadoDeUsuarios(controladorU);
            break;

        case 3:
            cout << "Ejecutando caso de uso: Alta de producto" << endl;
            break;

        case 4:
            cout << "Ejecutando caso de uso: Consultar producto" << endl;
            break;

        case 5:
            cout << "Ejecutando caso de uso: Crear promocion" << endl;
            break;

        case 6:
            cout << "Ejecutando caso de uso: Consultar promocion" << endl;
            break;

        case 7:
            cout << "Ejecutando caso de uso: Realizar compra" << endl;
            break;

        case 8:
            cout << "Ejecutando caso de uso: Dejar comentario" << endl;
            break;

        case 9:
            cout << "Ejecutando caso de uso: Eliminar Comentario" << endl;
            break;

        case 10:
            cout << "Ejecutando caso de uso: Enviar Producto" << endl;
            break;

        case 11:
            cout << "Ejecutando caso de uso: Expediente de Usuario" << endl;
            break;

        case 12:
            cout << "Ejecutando caso de uso: Suscribirse a notificaciones" << endl;
            break;

        case 13:
            cout << "Ejecutando caso de uso: Consulta de notificaciones" << endl;
            break;

        case 14:
            cout << "Ejecutando caso de uso: Eliminar suscripciones" << endl;
            break;

        case 15:
            cout << "Terminando programa...\n";
            continuar = false;
            break;

        default:
            cout << "Opcion no valida. Intente nuevamente.\n";
        }
    };

    return 0;
}
