#include <ios>
#include <limits>
#include <string>
#include <set>
#include <iostream>
// #include <sstream>
// #include <fstream>

#include "include/CUsuario.h"
#include "include/IFecha.h"
#include "include/INotificacion.h"
#include "include/IVenta.h"

#include "include/datatypes.h"
#include "include/fabrica.h"
#include "include/IUsuario.h"

using namespace std;

#define ARCHIVO_USUARIOS "2024Usuarios.cvs"
#define ARCHIVO_USUARIOS_CLIENTES "2024Usuarios-Clientes.cvs"
#define ARCHIVO_USUARIOS_VENDEDORES "2024Usuarios-Vendedores.cvs"

void altaDeUsuario() 
{
    Fabrica *fabrica = Fabrica::getInstanceF(); // se crea instancia única de fábrica
    IUsuario *controladorU = fabrica->getIUsuario();
    IFecha *controladorF = fabrica->getIFecha();

    string nickname, contrasena;
    int dia, mes, anio;

    cout << "👤 Ingrese nickname: ";
    cin >> nickname;
    
    cout << "🔑 Ingrese contraseña: ";
    cin >> contrasena;
    while (contrasena.length() < 6) {
        cout << "❌ La contraseña debe tener al menos 6 caracteres. Intente de nuevo.\n";
        cout << "🔑 Ingrese contraseña: ";
        cin >> contrasena;
    }

    cout << "📅 Ingrese día: ";
    cin >> dia;
    cout << "📅 Ingrese mes: ";
    cin >> mes;
    cout << "📅 Ingrese año: ";
    cin >> anio;

    DTFecha fecha(dia, mes, anio);
    while (!controladorF->esFechaValida(fecha)) {
        cout << "❌ Ingrese una fecha válida:\n";
        cout << "📅 Ingrese día: ";
        cin >> dia;
        cout << "📅 Ingrese mes: ";
        cin >> mes;
        cout << "📅 Ingrese año: ";
        cin >> anio;
        fecha = DTFecha(dia, mes, anio);
    }

    controladorU->ingresarUsuario(nickname, contrasena, fecha);
    if (controladorU->existeUsuarioIgualNickname(nickname)) {
        cout << "❌ Nickname ya existe, intente nuevamente.\n";
        controladorU->terminarAlta();
        altaDeUsuario();
        return;
    }

    cout << "👥 Ingrese 1 si va a ingresar un cliente o 2 si va a ingresar un vendedor: ";
    int opcion;
    cin >> opcion;

    switch (opcion) {
    case 1: {
        cout << "🏙️ Ingrese ciudad: ";
        string ciudad;
        cin >> ciudad;

        cout << "🏡 Ingrese dirección: ";
        string direccion;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, direccion);

        controladorU->altaCliente(direccion, ciudad);
        break;
    }
    case 2: {
        cout << "🆔 Ingrese código RUT (debe tener exactamente 12 caracteres): ";
        string codigoRUT;
        cin >> codigoRUT;
        while (codigoRUT.length() != 12) {
            cout << "❌ El código RUT debe tener exactamente 12 caracteres. Intente de nuevo.\n";
            cout << "🆔 Ingrese código RUT (debe tener exactamente 12 caracteres): ";
            cin >> codigoRUT;
        }
        controladorU->altaVendedor(codigoRUT);
        break;
    }
    default:
        cout << "❌ Opción no válida. Intente de nuevo.\n";
        altaDeUsuario();
        return;
    }

    controladorU->confirmarAltaUsuario();
    cout << "✅ Usuario registrado con éxito.\n";
    return;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////

void listadoDeUsuarios()
{
    Fabrica *fabrica = Fabrica::getInstanceF(); // se crea instancia única de fábrica
    IUsuario *controladorU = fabrica->getIUsuario();

    set<DTUsuario *> clientes = controladorU->listadoUsuarios("cliente");
    set<DTUsuario *> vendedores = controladorU->listadoUsuarios("vendedor");

    if (clientes.empty() && vendedores.empty())
    {
        cout << "❌ No hay usuarios disponibles.\n";
        cout << "🔘 Ingrese enter para continuar...";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.get();
        return;
    }

    cout << "\n📋 Listado de Usuarios:\n\n";

    cout << "🧑‍🤝‍🧑 Clientes:\n";
    for (DTUsuario *usuario : clientes)
    {
        cout << "------------------------------------------\n";
        cout << "   🆔 Nombre: " << usuario->getNickname() << "\n";
        cout << "   🎂 Fecha de nacimiento: " << usuario->getFechaNac().getDia() << "/" << usuario->getFechaNac().getMes() << "/" << usuario->getFechaNac().getAnio() << "\n";
        cout << "   🏠 Dirección: " << usuario->getDireccion() << "\n";
        cout << "   🌆 Ciudad: " << usuario->getCiudad() << "\n";
        cout << "------------------------------------------\n";
    }

    cout << "\n🛒 Vendedores:\n";
    for (DTUsuario *vend : vendedores)
    {
        cout << "------------------------------------------\n";
        cout << "   🆔 Nombre: " << vend->getNickname() << "\n";
        cout << "   🎂 Fecha de nacimiento: " << vend->getFechaNac().getDia() << "/" << vend->getFechaNac().getMes() << "/" << vend->getFechaNac().getAnio() << "\n";
        cout << "   🧾 Código RUT: " << vend->getCodigoRUT() << "\n";
        cout << "------------------------------------------\n";
    }

    cout << "🔘 Ingrese enter para continuar...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void altaDeProducto()
{
    Fabrica *fabrica = Fabrica::getInstanceF(); // se crea instancia única de fábrica
    IUsuario *controladorU = fabrica->getIUsuario();
    IVenta *controladorV = fabrica->getIVenta();

    set<DTUsuario *> dataVendedores = controladorU->listadoUsuarios("vendedor");
    cout << "📋 Listado de Vendedores: " << "\n";

    if (dataVendedores.empty())
    {
        cout << "❌ No hay vendedores disponibles. Por favor cree uno antes de comenzar con esta operación.\n";
        cout << "🔘 Ingrese enter para continuar...";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.get();
        return;
    }
    else
    {
        for (const DTUsuario *vendedor : dataVendedores)
        {
            cout << "   🧑‍💼 " << vendedor->getNickname() << "\n";
        }
    }
    cout << "\n";

    string nicknameV, nombreP, descripcionP;
    float precioP;
    int cantStockP, opcion;
    categoria cat;

    cout << "🔍 Elija un vendedor: ";
    cin >> nicknameV;

    // Agregar precondición de que el vendedor sea correcto
    bool encontrado = false;
    while (!encontrado)
    {
        for (DTUsuario *usuario : dataVendedores)
        {
            if (usuario->getNickname() == nicknameV)
            {
                encontrado = true;
                break;
            }
        }
        if (!encontrado)
        {
            cout << "❌ El vendedor ingresado no existe. Vuelva a intentar.\n";
            cin >> nicknameV;
        }
    }
    
    cout << "\n📝 Ingrese nombre del producto: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, nombreP);
    cout << "\n📝 Ingrese descripción del producto: ";
    getline(cin, descripcionP);
    cout << "\n💲 Ingrese precio del producto: ";
    cin >> precioP;

    while (cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "❌ El precio del producto debe ser de tipo float, ingrese nuevamente el precio del producto:\n";
        cin >> precioP;
    }
    
    cout << "\n📦 Ingrese cantidad en stock: ";
    cin >> cantStockP;

    while (cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "❌ El valor de stock debe ser de tipo integer, ingrese nuevamente la cantidad en stock:\n";
        cin >> cantStockP;
    }

    cout << "\n🔢 Ingrese 1 si es electrodoméstico, 2 si es ropa, 3 si es otro: ";
    cin >> opcion;

    while (cin.fail() || opcion < 1 || opcion > 3)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "❌ Opción incorrecta, ingrese 1 si es electrodoméstico, 2 si es ropa, 3 si es otro:\n";
        cin >> opcion;
    }

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

    controladorV->crearProducto(nicknameV, nombreP, descripcionP, precioP, cantStockP, cat);
    cout << "\n✅ Producto creado exitosamente.\n";
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*void consultarProducto() // agregar precondicion de no hay producto
{
    Fabrica *fabrica = Fabrica::getInstanceF(); // se crea instancia única de fábrica
    IUsuario *controladorU = fabrica->getIUsuario();
    IVenta *controladorV = fabrica->getIVenta();

    int idProducto;
    set<DTProducto> dataProductos = controladorV->listadoProductos();
    cout << "Listado de Productos: " << "\n";
    for (DTProducto producto : dataProductos)
    {
        cout << "----Id: " << producto.getId() << "\n";
        cout << "Nombre: " << producto.getNombre() << "\n\n";
    }

    cout << "\n";
    cout << "Seleccione un Producto con su id: ";
    cin >> idProducto;
    while (cin.fail() || !controladorV->existeProducto(idProducto))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Id incorrecto, seleccione un producto nuevamente con su id:\n";
        cin >> idProducto;
    }
    cout << "\n";

    DTProducto dataP = controladorV->dataDeProducto(controladorV->seleccionarProductoPorId(idProducto));

    cout << "Nombre : " << dataP.getNombre() << "\n";
    cout << "Id: " << dataP.getId() << "\n";
    cout << "Precio: " << dataP.getPrecio() << "\n";
    cout << "Cantidad en stock: " << dataP.getCantStock() << "\n";
    cout << "Descripcion: " << dataP.getDesc() << "\n";
    string cat;
    switch (dataP.getCat())
    {
    case ropa:
    {
        cat = "ropa";
        break;
    }
    case electrodomesticos:
    {
        cat = "electrodomestico";
        break;
    }
    case otro:
    {
        cat = "otro";
        break;
    }
    }
    cout << "Categoria: " << cat << "\n";
    cout << "Nickname del vendedor: " << controladorV->nombreVendedor(idProducto) << "\n\n";
    cout << "Ingrese enter para continuar...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}*/

void consultarProducto()
{
    Fabrica *fabrica = Fabrica::getInstanceF(); // se crea instancia única de fábrica
    IUsuario *controladorU = fabrica->getIUsuario();
    IVenta *controladorV = fabrica->getIVenta();

    int idProducto;
    set<DTProducto> dataProductos = controladorV->listadoProductos();
    cout << "📋 Listado de Productos: " << "\n";

    if (dataProductos.empty())
    {
        cout << "❌ No hay productos disponibles.\n";
        cout << "🔘 Ingrese enter para continuar...";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.get();
        return;
    }

    for (DTProducto producto : dataProductos)
    {
        cout << "🔸 Id: " << producto.getId() << "\n";
        cout << "   Nombre: " << producto.getNombre() << "\n\n";
    }

    cout << "\n";
    cout << "🔍 Seleccione un Producto con su id: ";
    cin >> idProducto;
    while (cin.fail() || !controladorV->existeProducto(idProducto))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "❌ Id incorrecto, seleccione un producto nuevamente con su id:\n";
        cin >> idProducto;
    }
    cout << "\n";

    DTProducto dataP = controladorV->dataDeProducto(controladorV->seleccionarProductoPorId(idProducto));

    cout << "📝 Detalles del Producto:\n";
    cout << "   📛 Nombre: " << dataP.getNombre() << "\n";
    cout << "   🔢 Id: " << dataP.getId() << "\n";
    cout << "   💲 Precio: " << dataP.getPrecio() << "\n";
    cout << "   📦 Cantidad en stock: " << dataP.getCantStock() << "\n";
    cout << "   📝 Descripción: " << dataP.getDesc() << "\n";

    string cat;
    switch (dataP.getCat())
    {
    case ropa:
        cat = "Ropa";
        break;
    case electrodomesticos:
        cat = "Electrodoméstico";
        break;
    case otro:
        cat = "Otro";
        break;
    }
    cout << "   🏷️ Categoría: " << cat << "\n";
    cout << "   🧑‍💼 Nickname del vendedor: " << controladorV->nombreVendedor(idProducto) << "\n\n";
    cout << "🔘 Ingrese enter para continuar...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void crearPromocion()
{
    Fabrica *fabrica = Fabrica::getInstanceF(); // se crea instancia única de fábrica
    IUsuario *controladorU = fabrica->getIUsuario();
    IVenta *controladorV = fabrica->getIVenta();
    IFecha *controladorF = fabrica->getIFecha();

    string nombreProm, descripcionProm;
    float descuento;
    int dia, mes, anio;
    cout << "Ingrese nombre de la promocion: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, nombreProm);
    cout << "\n"
         << "Ingrese descripcion: ";
    getline(cin, descripcionProm);
    cout << "\n"
         << "Ingrese descuento: ";
    cin >> descuento;
    cout << "\nIngrese fecha de vencimiento. ";
    cout << "\n Dia: ";
    cin >> dia;
    cout << "\n Mes: ";
    cin >> mes;
    cout << "\n Anio: ";
    cin >> anio;
    cout << "\n";
    DTFecha fechaVen = DTFecha(dia, mes, anio);
    
    while (!controladorF->esFechaValida(fechaVen) || controladorF->getFecha() >= fechaVen)
    {
        cout << "\nIngrese una fecha válida. ";
        cout << "\n Dia: ";
        cin >> dia;
        cout << "\n Mes: ";
        cin >> mes;
        cout << "\n Anio: ";
        cin >> anio;
        DTFecha fechaVen = DTFecha(dia, mes, anio);
    }
    
    string nicknameV;

    set<DTUsuario *> vendedores = controladorU->listadoUsuarios("vendedor");

    cout << "Listado de Vendedores: " << "\n";
    for (DTUsuario *vendedor : vendedores)
    {
        cout << vendedor->getNickname() << "\n";
    }

    cout << "\n";

    cout << "Seleccione un vendedor: ";
    cin >> nicknameV;

    while (!controladorU->existeUsuarioIgualNickname(nicknameV))
    {
        cout << "El vendedor no existe. seleccione nuevamente un vendedor.\n"
             << "Ingrese nickname: ";
        cin >> nicknameV;
    }

    controladorV->setMemUsuario(nicknameV);
    controladorV->crearPromocion(nombreProm, descripcionProm, descuento, fechaVen);

    set<DTProducto> productosNoEnPromo = controladorV->listadoProductosNoEnPromo();
    cout << "Listado de productos disponibles para el vendedor " << nicknameV << " :\n";

    if (productosNoEnPromo.empty())
    {
        cout << "No hay productos disponibles." << endl;
    }
    else
    {
        for (set<DTProducto>::iterator it = productosNoEnPromo.begin(); it != productosNoEnPromo.end(); it++)
        {

            cout << "Id: " << it->getId();
            cout << ", Nombre: " << it->getNombre() << "\n";
        }
        cout << "\n";
    }
    int id, cantMinima;
    DTProducto dataProd;
    bool flag = true;
    cout << "Ingrese los productos que van a componer la promo (ingrese -1 para dejar de agregar)\n";
    int SoN;
    while (flag)
    {
        cout << "Producto a agregar: \n";
        cout << "Id: ";
        cin >> id;
        if (id == -1)
            break;
        cout << "Cantidad Mínima: ";
        cin >> cantMinima;
        // while(cantMinima< )
        // {
        //     cout << "Cantidad Mínima incorrecta, ingrese nuevamente: ";
        //     cout << "Cantidad Mínima: ";
        //     cin >> cantMinima;
        // }

        if (!controladorV->productoEnPromo(id))
        {
            controladorV->seleccionarProductoAProm(id, cantMinima);
            cout << "Producto ingresado correctamente. \n";
        }
        else
        {
            cout << "El producto ya se encuentra en una promoción.\n";
        }
        cout << "Quiere continuar?  0 o 1: ";

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> SoN;
        if (SoN == 0)
        {
            flag = false;
            // break;
        }
    }
    if (id != -1)
        controladorV->confirmarCrearPromocion(nicknameV);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void consultarPromocion()
{
    Fabrica *fabrica = Fabrica::getInstanceF(); // se crea instancia única de fábrica
    IVenta *controladorV = fabrica->getIVenta();
    // Imprime todas las Promociones vigentes en el sistema  (HABRIA Q PREGUNTAR PRECOND PARA IMPRIMIR: FECHA VENC < FECHA SISTEMA)
    string opcion;
    set<DTPromocion> dataPromos = controladorV->listadoPromociones();
    cout << "\nListado de Promociones.\n"
         << "\n";
    for (DTPromocion promo : dataPromos)
    {
        cout << "------Nombre: " << promo.getNombre() << "\n";
        cout << "-Descripcion: " << promo.getDescripcion() << "\n";
        cout << "---Descuento: " << promo.getDescuento() << "\n";
        cout << "Valido hasta: " << promo.getFechaVen().getDia() << "/" << promo.getFechaVen().getMes() << "/" << promo.getFechaVen().getAnio() << "\n\n";
    }

    cout << "\nDesea ver los productos dentro de una promoción? y/n: ";
    cin >> opcion;

    // aca faltaria ver precond q opcion sea un nombre valido
    if (opcion == "y")
    {
        cout << "\nIngrese el nombre de la promocion a consultar: ";
        cin >> opcion;

        // Imprime informacion del vendedor de la Promocion

        DTUsuario *dataVen = controladorV->infoPromocionVendedor(opcion);

        cout << "-----------Vendedor: " << dataVen->getNickname() << "\n";
        cout << "---------Codigo RUT: " << dataVen->getCodigoRUT() << "\n";
        cout << "Fecha de nacimiento: " << dataVen->getFechaNac().getDia() << "/" << dataVen->getFechaNac().getMes() << "/" << dataVen->getFechaNac().getAnio() << "\n";

        // Imprime informacion de todos los productos de la Promocion

        set<DTProducto> dataProds = controladorV->infoPromocionProductos(opcion);

        string cat;
        set<DTProducto>::iterator prod;
        for (prod = dataProds.begin(); prod != dataProds.end(); prod++)
        {
            cout << "---------Id: " << prod->getId() << "\n";
            cout << "-----Nombre: " << prod->getNombre() << "\n";
            cout << "--Categoria: " << prod->getCat() << "\n";
            switch (prod->getCat())
            {
            case ropa:
            {
                cat = "ropa";
                break;
            }
            case electrodomesticos:
            {
                cat = "electrodomestico";
                break;
            }
            case otro:
            {
                cat = "otro";
                break;
            }
            }
            int cantMinima = controladorV->cantidadMinimaPromo(opcion, prod->getId());
            cout << "--Categoria: " << cat << "\n";
            cout << "Descripcion: " << prod->getDesc() << "\n";
            cout << "Cantidad en stock: " << prod->getCantStock() << "\n";
            cout << "Cantidad minima para aplicar promoción: " << cantMinima << "\n";
            cout << "-----Precio: " << prod->getPrecio() << "\n";
        }
    }
    cout << "Ingrese enter para continuar...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void realizarCompra()
{
    Fabrica *fabrica = Fabrica::getInstanceF();
    IUsuario *controladorU = fabrica->getIUsuario();
    IVenta *controladorV = fabrica->getIVenta();
    IFecha * controladorF = fabrica->getIFecha();

    string nicknameC, cat;
    int opcion;

    set<DTUsuario *> clientes = controladorU->listadoUsuarios("cliente");
    set<DTUsuario *>::iterator it;

    cout << "Listado de clientes. \n\n";

    for (it = clientes.begin(); it != clientes.end(); it++)
    {
        cout << "  " << (*it)->getNickname() << "\n";
    }
    cout << "Seleccione un cliente: ";
    cin >> nicknameC;
    cout << "\n";
    cout << "Listado de productos: \n";
    set<DTProducto> dataProductos = controladorV->listadoProductos();
    for (DTProducto prod : dataProductos)
    {
        cout << "   Id: " << prod.getId() << "\n";
        cout << "   Nombre: " << prod.getNombre() << "\n";
        switch (prod.getCat())
        {
        case ropa:
        {
            cat = "   ropa";
            break;
        }
        case electrodomesticos:
        {
            cat = "   electrodomestico";
            break;
        }
        case otro:
        {
            cat = "   otro";
            break;
        }
        }
        cout << "   Categoria: " << cat << "\n";
        cout << "   Descripcion: " << prod.getDesc() << "\n";
        cout << "   Cantidad en stock: " << prod.getCantStock() << "\n";
        cout << "   Precio: " << prod.getPrecio() << "\n\n";
    }
    
    DTFecha fechaActual = controladorF->getFecha();
    controladorV->crearCompra(nicknameC, fechaActual);

    int id, cantidad;
    bool flag = true;
    bool flagProd = true;
    cout << "Ingrese ID y cantidad del producto que desea agregar a su compra.\n";
    while (flag)
    {
        cout << "   Ingrese ID: ";
        cin >> id;
        cout << "   Ingrese Cantidad: ";
        cin >> cantidad;
        if (!controladorV->existeProducto(id))
        {
            cout << "Producto no encontrado. Ingrese otro ID:";
            cin >> id;
            cout << "Ingrese cantidad: ";
            cin >> cantidad;
            cout << "\n";
        }
        if (controladorV->productoEnCompra(id))
        {
            cout << "Producto ya agregado a la compra. Ingrese otro ID: ";
            cin >> id;
            cout << "Ingrese cantidad: ";
            cin >> cantidad;
            cout << "\n";
        }
        controladorV->agregarACompra(id, cantidad);
        flagProd = controladorV->cantidadValida(id, cantidad);
        if (!flagProd)
        {
            cout << "El producto seleccionado no dispone de tantas unidades como desea comprar. ";
        }
        cout << "\n Desea agregar otro producto? Ingrese 0 o 1: ";
        cin >> opcion;
        flag = !(opcion == 0);
    }

    DTCompra dataCompra = controladorV->detallesCompra();

    cout << "---Detalles de su compra: \n"
         << "Precio Total: " << dataCompra.getPrecioTotal() << "\nFecha: " << dataCompra.getFecha().getDia() << "/" << dataCompra.getFecha().getMes() << "/" << dataCompra.getFecha().getAnio() << "\n";
    cout << "\n ---Detalles de los productos en su compra: \n";
    for (DTProducto dp : dataCompra.getProductos())
    {
        cout << "Id: " << dp.getId() << "\n";
        cout << "Nombre: " << dp.getNombre() << "\n";
        switch (dp.getCat())
        {
        case ropa:
        {
            cat = "ropa";
            break;
        }
        case electrodomesticos:
        {
            cat = "electrodomestico";
            break;
        }
        case otro:
        {
            cat = "otro";
            break;
        }
        }
        cout << "Categoria: " << cat << "\n";
        cout << "Descripcion: " << dp.getDesc() << "\n";
        cout << "Cantidad en stock: " << dp.getCantStock() << "\n";
        cout << "Precio: " << dp.getPrecio() << "\n";
    }
    cout << "-------------------------------\n";
    cout << "Ingrese enter para continuar...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void dejarComentario()
{
    Fabrica *fabrica = Fabrica::getInstanceF(); // se crea instancia única de fábrica
    IVenta *controladorV = fabrica->getIVenta();
    IUsuario *controladorU = fabrica->getIUsuario();
    // lista usuarios y selecciona uno
    string nicknameU, textoC;
    int idP;
    set<DTUsuario *> dataUsuarios = controladorU->listadoUsuarios();
    for (DTUsuario *usuario : dataUsuarios) 
    {
        cout << usuario->getNickname() << "\n";
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
    cout << "Seleccione un Producto con su id: \n";
    cin >> idP;

    cout << "\nIngrese 1 si desea realizar un comentario nuevo o 2 si desea responder a un comentario existente,\n";
    int opcion;
    cin >> opcion;
    switch (opcion)
    {
    case 1:
    {
        cout << "Ingrese el texto del comentario: \n";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, textoC);
        controladorU->crearComentario(textoC, idP, nicknameU);
    }
    break;
    case 2:
    {
        if (!controladorU->hayComentarios(idP))
        {
            cout << "No hay comentarios que responder.\n";
            break;
        }
        else
        {
            int idComen;
            set<DTComentario>::iterator it;
            set<DTComentario> dtComentarios = controladorU->listadoComentario(idP);
            // lista todos los comentarios asociados al producto seleccionado
            for (it = dtComentarios.begin(); it != dtComentarios.end(); ++it)
            {
                cout << "Id comentario: " << it->getId() << "\n";
                cout << "Comentario: " << it->getText() << "\n";
            }
            cout << "Seleccione un Comentario con su id: ";
            cin >> idComen;
            cout << "\n";
            cout << "Ingrese el texto de la respuesta al comentario: ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, textoC);
            controladorU->crearRespuesta(textoC, idComen, idP, nicknameU);
        }
    }
    break;
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void eliminarComentario()
{
    Fabrica *fabrica = Fabrica::getInstanceF(); // se crea instancia única de fábrica
    IVenta *controladorV = fabrica->getIVenta();
    IUsuario *controladorU = fabrica->getIUsuario();

    set<DTUsuario *> dataUsuarios = controladorU->listadoUsuarios();
    
    // Mostrar listado de usuarios
    cout << "\n👥 Listado de usuarios:\n";
    cout << "-------------------------\n";
    for (DTUsuario *usuario : dataUsuarios)
    {
        cout << usuario->getNickname() << "\n";
    }

    string usuarioSeleccionado;
    cout << "\nIngrese el nickname del usuario del que desea eliminar un comentario: ";
    cin >> usuarioSeleccionado;

    controladorU->recordarUsuario(usuarioSeleccionado);
    set<DTComentario> comentarios = controladorU->listadoComentario(usuarioSeleccionado);
    
    cout << "\nListado de Comentarios de " << usuarioSeleccionado << ":\n";
    if (comentarios.empty())
    {
        cout << "   No hay comentarios para este usuario.\n";
        return;
    }

    // mostrar comentarios
    cout << "--------------------------------------------\n";
    for (const auto &comentario : comentarios)
    {
        cout << "ID: " << comentario.getId() << "\n";
        cout << "Contenido: " << comentario.getText() << "\n";
        cout << "Fecha: " << comentario.getFechaCom().getDia() << "/" << comentario.getFechaCom().getMes() << "/" << comentario.getFechaCom().getAnio() << "\n";
        cout << "--------------------------------------------\n";
    }

    // eliminar comentario
    cout << "Ingrese el ID del comentario que desea eliminar: ";
    int id;
    cin >> id;
    cout << "\n";

    controladorU->eliminarComentario(id);
    cout << "Comentario " << id << " eliminado correctamente.\n";
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void suscribirANotificaciones()
{
    // Lista los vendedores a los que no esta suscrito el cliente
    Fabrica *fabrica = Fabrica::getInstanceF(); // se crea instancia única de fábrica
    INotificacion *controladorN = fabrica->getINotificacion();

    set<DTUsuario *> clientes = ControladorUsuario::getInstance()->listadoUsuarios("cliente");

    cout << "Listado de clientes: \n";
    for (set<DTUsuario *>::iterator it = clientes.begin(); it != clientes.end(); ++it)
    {
        cout << (*it)->getNickname() << "\n";
    }

    string nombreCliente;
    cout << "Ingrese el nombre del cliente que desea suscribir: ";
    cin >> nombreCliente;

    set<DTUsuario *> vendNoSuscritos;
    vendNoSuscritos = controladorN->listarVendedoresNoSuscritos(nombreCliente);

    cout << "Listado de vendedores donde " << nombreCliente << " no esta suscrito: \n";
    for (set<DTUsuario *>::iterator it = vendNoSuscritos.begin(); it != vendNoSuscritos.end(); ++it)
    {
        cout << (*it)->getNickname() << "\n";
    }

    string nombreVend;
    cout << "Ingrese el nickname del vendedor al que desea suscribirse: " << " \n";
    cin >> nombreVend;

    controladorN->suscribirAVendedor(nombreCliente, nombreVend);
    for (; nombreVend != "0";)
    {
        cout << "Si desea suscribirse a otro vendedor ingrese su nombre, de lo contrario ingrese 0: " << " \n";
        cin >> nombreVend;
        if (nombreVend != "0")
        {
            controladorN->suscribirAVendedor(nombreCliente, nombreVend);
        }
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void consultaDeNotificacion()
{
    Fabrica *fabrica = Fabrica::getInstanceF(); // se crea instancia única de fábrica
    INotificacion *controladorN = fabrica->getINotificacion();
    IUsuario *controladorU = fabrica->getIUsuario();
    string nicknameC;

    set<DTUsuario *> clientes = ControladorUsuario::getInstance()->listadoUsuarios("cliente");

    cout << "Listado de clientes: \n";
    for (set<DTUsuario *>::iterator it = clientes.begin(); it != clientes.end(); ++it)
    {
        cout << (*it)->getNickname() << "\n";
    }
    cout << "Ingrese nickname del cliente que va a constular sus notificaciones: ";
    cin >> nicknameC;

    set<DTNotificacion> notificaciones = controladorN->mostrarNotificaciones(nicknameC);
    // falta ver la condicion del caso de uso

    if (notificaciones.empty())
    {
        cout << "No tiene notificaciones pendientes. \n";
        cout << "Ingrese enter para continuar...";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.get();
        return;
    }

    cout << "Listado de notificaciones de " << nicknameC << ": \n";
    for (DTNotificacion notificacion : notificaciones)
    {
        cout << "Vendedor: " << notificacion.getNicknameUsuario() << "\n";
        cout << "Nombre de promoción: " << notificacion.getNombreProm() << "\n";
        set<DTProducto> dataProds = notificacion.getProductos();
        cout << "Informacion de los productos: \n";
        for (DTProducto prod : dataProds)
        {
            cout << "   ID del producto: " << prod.getId() << "\n";
            cout << "   Nombre del producto: " << prod.getNombre() << "\n";
            cout << "   Descripción: " << prod.getDesc() << "\n";
            cout << "   Precio del producto: " << prod.getPrecio() << "\n";
            cout << "   Stock del producto: " << prod.getCantStock() << "\n";
        }
    }

    controladorN->eliminarNotificacion();
    cout << "Ingrese enter para continuar...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void eliminarSuscripciones()
{
    Fabrica *fabrica = Fabrica::getInstanceF(); // se crea instancia única de fábrica
    INotificacion *controladorN = fabrica->getINotificacion();

    set<DTUsuario *> clientes = ControladorUsuario::getInstance()->listadoUsuarios("cliente");

    // Mostrar listado de clientes
    cout << "\n👤 Listado de clientes:\n";
    cout << "-------------------------\n";
    for (auto it = clientes.begin(); it != clientes.end(); ++it)
    {
        cout << "• " << (*it)->getNickname() << "\n";
    }

    string nombreCliente;
    cout << "\nIngrese el nickname del cliente que desea eliminar sus suscripciones: ";
    cin >> nombreCliente;

    set<DTUsuario *> vendSuscritos = controladorN->listarVendedoresSuscritos(nombreCliente);

    // Mostrar listado de vendedores suscritos por el cliente
    cout << "\n📋 Listado de vendedores suscritos por " << nombreCliente << ":\n";
    cout << "-------------------------------------------------------\n";
    for (auto it = vendSuscritos.begin(); it != vendSuscritos.end(); ++it)
    {
        cout << "• " << (*it)->getNickname() << "\n";
    }

    string nombreVend;
    cout << "\nIngrese el nickname del vendedor al que desea eliminar su suscripción: ";
    cin >> nombreVend;

    controladorN->eliminarSuscripcion(nombreCliente, nombreVend);

    // Confirmar si se desea eliminar más suscripciones
    while (nombreVend != "0")
    {
        cout << "\n✂️ Si desea eliminar otra suscripción, ingrese el nombre del vendedor; de lo contrario, ingrese 0: ";
        cin >> nombreVend;
        if (nombreVend != "0")
        {
            controladorN->eliminarSuscripcion(nombreCliente, nombreVend);
        }
    }

    cout << "\n👋 Proceso de eliminación de suscripciones finalizado.\n";
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void enviarProducto()
{
    Fabrica *fabrica = Fabrica::getInstanceF(); // se crea instancia única de fábrica
    IVenta *controladorV = fabrica->getIVenta();
    IUsuario *controladorU = fabrica->getIUsuario();

    string nombreVendedor, nombreProducto;
    cout << "Listado de vendedores:\n";
    set<DTUsuario *> vendedores = controladorU->listadoUsuarios("vendedor");

    for (set<DTUsuario *>::iterator it = vendedores.begin(); it != vendedores.end(); it++)
    {
        cout << (*it)->getNickname() << " \n";
    }
    cout << "\n";

    cout << "Ingrese el nombre del vendedor: " << " \n";
    cin >> nombreVendedor;

    bool existeVendedor = controladorU->existeUsuarioIgualNickname(nombreVendedor);
    while (!existeVendedor)
    {
        cout << "El vendedor no fue encontrado, vuelva a ingresar un vendedor:\n";
        cout << "Ingrese el nombre del vendedor: " << " \n";
        cin >> nombreVendedor;
        existeVendedor = controladorU->existeUsuarioIgualNickname(nombreVendedor);
    }

    set<string> productosPorEnviar = controladorV->obtenerProdsPendEnvio(nombreVendedor);

    if (productosPorEnviar.empty())
    {
        char opcion;
        cout << "No hay productos pendientes de envío.\n";
        cout << "Desea volver a intentar (y) o salir (n)?\n";
        cin >> opcion;
        if (opcion == 'y' || opcion == 'Y')
        {
            enviarProducto(); // Llamar de nuevo a la función
            return;           // Salir de la función actual
        }
        else
        {
            return; // Salir de la función
        }
    }

    cout << "Productos en compras pendientes de envío.\n " << "\n";
    for (set<string>::iterator itProd = productosPorEnviar.begin(); itProd != productosPorEnviar.end(); ++itProd)
    {
        cout << "--Producto: " << *itProd << "\n";
    }
    cout << "\n";

    cout << "Ingrese el nombre del producto: " << " \n";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, nombreProducto);
    while (productosPorEnviar.find(nombreProducto) == productosPorEnviar.end())
    {
        cout << "Producto incorrecto, ingrese un producto pendiente de envío." << "\n";
        cout << "Ingrese el nombre del producto: " << " \n";
        getline(cin, nombreProducto);
    }
    cout << " \n";
    set<DTCompra2> parejasEnv;
    set<DTCompra2> pareja = controladorV->clientesConEnvioPend(nombreProducto);
    for (set<DTCompra2>::iterator itPareja = pareja.begin(); itPareja != pareja.end(); ++itPareja)
    {
        cout << "--Nombre del cliente: " << itPareja->getNicknameC() << "\n";
        cout << "-----Fecha de compra: " << itPareja->getFecha().getDia() << "/" << itPareja->getFecha().getMes() << "/" << itPareja->getFecha().getAnio() << "\n";
        parejasEnv.insert(*itPareja);
    }
    cout << " \n";
    string nombreCliente;
    cout << "\nSeleccione cliente: ";
    cin >> nombreCliente;
    int idC;
    DTFecha fechaCompra;
    for (set<DTCompra2>::iterator itClienteComp = parejasEnv.begin(); itClienteComp != parejasEnv.end(); ++itClienteComp)
    {
        if (itClienteComp->getNicknameC() == nombreCliente)
        {
            idC = itClienteComp->getId();
        }
    }
    ///////////////////////////////////////////////////
    // buscar forma mas eficiente de encontrar el id //
    ///////////////////////////////////////////////////
    int idProducto;
    set<DTProducto> asd = controladorV->listadoProductos();
    for (set<DTProducto>::iterator itAsd = asd.begin(); itAsd != asd.end(); ++itAsd)
    {
        if (itAsd->getNombre() == nombreProducto)
        {
            idProducto = itAsd->getId();
        }
    }

    controladorV->enviarProducto(idProducto, nombreCliente);
    //controladorV->enviarProducto(idProducto, idC, nombreCliente);

    cout << "El producto ha sido enviado. \n ";
    cout << "Ingrese enter para continuar...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void expedienteDeUsuario()
{
    Fabrica *fabrica = Fabrica::getInstanceF(); // se crea instancia única de fábrica
    IVenta *controladorV = fabrica->getIVenta();
    IUsuario *controladorU = fabrica->getIUsuario();

    string nicknameU;
    cout << "Usuarios registrados:\n";
    set<DTUsuario *> usuarios = controladorU->listadoUsuarios();
    for (set<DTUsuario *>::iterator it = usuarios.begin(); it != usuarios.end(); ++it)
    {
        cout << (*it)->getNickname() << "\n";
    }

    cout << "Seleccione un usuario: ";
    cin >> nicknameU;
    cout << "\n";

    DTUsuario *dataUsuario = controladorU->getDatosUsuario(nicknameU);

    cout << "Datos del usuario seleccionado.\n";
    cout << "   Nombre del usuario: " << dataUsuario->getNickname() << "\n";
    cout << "   Fecha de Nacimiento: " << dataUsuario->getFechaNac().getDia() << "/" << dataUsuario->getFechaNac().getMes() << "/" << dataUsuario->getFechaNac().getAnio() << "\n";

    int tipo = dataUsuario->getTipo();

    if (tipo == 2)
    {
        // Usuario es vendedor
        // lista todos los productos del vendedor

        set<DTProducto> dataProds = controladorV->getDatosProductosVendedor(nicknameU);
        cout << "Productos del vendedor " << nicknameU << ":\n";
        for (set<DTProducto>::iterator iter = dataProds.begin(); iter != dataProds.end(); ++iter)
        {
            cout << "---ID: " << iter->getId() << "\n";
            cout << "   Nombre: " << iter->getNombre() << "\n";
            cout << "   Descripcion: " << iter->getDesc() << "\n";
            cout << "   Precio: " << iter->getPrecio() << "\n";
            cout << "   Cantidad En Stock: " << iter->getCantStock() << "\n";
            cout << "\n";
        }
        cout << "\n";
        // // Lista todos las promociones activas

        set<DTPromocion> dataPromos = controladorV->getDatosPromocionVigentesVendedor(nicknameU);
        cout << "Promociones del vendedor " << nicknameU << ":\n";
        for (set<DTPromocion>::iterator iterador = dataPromos.begin(); iterador != dataPromos.end(); ++iterador)
        {
            cout << iterador->getNombre() << endl; // Muestro el nombre de la promo
            cout << iterador->getDescripcion() << "\n";
            cout << iterador->getDescuento() << "\n";
        }
    }
    else if (tipo == 1)
    {
        // El usuario es cliente
        set<DTCompra> comprasCliente = controladorV->getDatosCompraRealizadaCliente(nicknameU);
        cout << "\n   Compras del cliente: " << nicknameU << "\n\n";
        if(comprasCliente.empty())
        {
            cout << "Este cliente no ha realizado compras.";
            cout << "Ingrese enter para continuar...";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.get();        
            return;
        }
        for (set<DTCompra>::iterator compra = comprasCliente.begin(); compra != comprasCliente.end(); ++compra) {
            cout << "\n=============================================\n";
            cout << "          Detalles de la Compra              \n";
            cout << "=============================================\n";
            cout << "   Id de la compra       : " << compra->getId() << "\n";
            cout << "   Monto total           : $" << compra->getPrecioTotal() << "\n";
            cout << "   Fecha de la compra    : " 
                << compra->getFecha().getDia() << "/" 
                << compra->getFecha().getMes() << "/" 
                << compra->getFecha().getAnio() << "\n";
            cout << "---------------------------------------------\n";

            set<DTProducto> prodsCompra = compra->getProductos();
            if (prodsCompra.empty()) {
                cout << "   No hay productos para esta compra\n";
            } else {
                cout << "   Productos en la compra:\n";
                for (set<DTProducto>::iterator it2 = prodsCompra.begin(); it2 != prodsCompra.end(); ++it2) {
                    cout << "   -----------------------------\n";
                    cout << "   Nombre del producto : " << (*it2).getNombre() << "\n";
                    cout << "   Descripción         : " << (*it2).getDesc() << "\n";
                    cout << "   Precio              : $" << (*it2).getPrecio() << "\n";
                    cout << "   Stock disponible    : " << (*it2).getCantStock() << "\n";
                }
            }
            cout << "=============================================\n";
        }
    }
    cout << "\nIngrese enter para continuar...\n";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void altaDeUsuarioCARGARDATOSPREESTABLECIDOS(string nickname, string contrasena, int dia, int mes, int anio, int opcion, string ciudad, string direccion, string codigoRUT)
{                                               // Pasar opcion = 1 si es cliente y 2 si es vendedor.
    Fabrica *fabrica = Fabrica::getInstanceF(); // se crea instancia única de fábrica
    IUsuario *controladorU = fabrica->getIUsuario();
    DTFecha fecha(dia, mes, anio);
    controladorU->ingresarUsuario(nickname, contrasena, fecha);
    switch (opcion)
    {
    case 1:
    {
        controladorU->altaCliente(direccion, ciudad);
    }
    break;
    case 2:
    {
        controladorU->altaVendedor(codigoRUT);
    }
    break;
    }
    controladorU->confirmarAltaUsuario();
    return;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void altaDeProductoCARGARDATOSPREESTABLECIDOS(string nicknameV, string nombreP, string descripcionP, float precioP, int cantStockP, int opcion)
{
    Fabrica *fabrica = Fabrica::getInstanceF(); // se crea instancia única de fábrica
    IUsuario *controladorU = fabrica->getIUsuario();
    IVenta *controladorV = fabrica->getIVenta();
    categoria cat;
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

    controladorV->crearProducto(nicknameV, nombreP, descripcionP, precioP, cantStockP, cat);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void crearPromocionCARGARDATOSPREESTABLECIDOS(string nombreProm, string descripcionProm, float descuento, int dia, int mes, int anio, map<int, int> prom, string nicknameV)
{
    Fabrica *fabrica = Fabrica::getInstanceF(); // se crea instancia única de fábrica
    IUsuario *controladorU = fabrica->getIUsuario();
    IVenta *controladorV = fabrica->getIVenta();

    DTFecha fechaVen = DTFecha(dia, mes, anio);
    controladorV->setMemUsuario(nicknameV);
    controladorV->crearPromocion(nombreProm, descripcionProm, descuento, fechaVen);

    for (map<int, int>::iterator it = prom.begin(); it != prom.end(); ++it)
    {
        controladorV->seleccionarProductoAProm(it->first, it->second);
    }
    controladorV->confirmarCrearPromocion(nicknameV);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void realizarCompraCARGARDATOSPREESTABLECIDOS(string nicknameC, map<int, int> compra, map<int, bool> enviado, DTFecha fecha)
{
    Fabrica *fabrica = Fabrica::getInstanceF();
    IUsuario *controladorU = fabrica->getIUsuario();
    IVenta *controladorV = fabrica->getIVenta();

    controladorV->crearCompra(nicknameC, fecha);
    //int idC = controladorV->getContadorCompra() - 1;

    for (map<int, int>::iterator it = compra.begin(); it != compra.end(); ++it)
    {
        controladorV->agregarACompra(it->first, it->second);
        set<DTProducto> sas = controladorV->detallesCompra().getProductos(); //esto va?
        if(enviado[it->first])
        {
            controladorV->enviarProducto(it->first, nicknameC);
        }   
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void dejarComentarioCARGARDATOSPREESTABLECIDOS(string nicknameU, int idP, string texto, int idComen, DTFecha fecha, int opcion)
// dejarComentarioCARGARDATOSPREESTABLECIDOS("juan87", 1, "¿La c?", 0, DTFecha(01, 06, 2024), 1); 
{
    Fabrica *fabrica = Fabrica::getInstanceF(); // se crea instancia única de fábrica
    //IVenta *controladorV = fabrica->getIVenta();
    IUsuario *controladorU = fabrica->getIUsuario();
    switch (opcion)
    {
    case 1:
    {
        controladorU->crearComentario(texto, idP, nicknameU, fecha);
    }
    break;
    case 2:
    {
        controladorU->crearRespuesta(texto, idComen, idP, nicknameU, fecha);
    }
    break;
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void cargarDatosPreestablecidos()
{
    // altaDeUsuarioCARGARDATOSPREESTABLECIDOS le paso el controlador, nombre, fecha, opcion = 1 si es cliente y 2 si es vendedor
    //  si es cliente le paso ciudad y direecion y en codigo rut le paso x, si es vendedor le paso codigoRUT y en ciudad, y direccion le pongo x.
    altaDeUsuarioCARGARDATOSPREESTABLECIDOS("ana23", "qwer1234", 15, 5, 1988, 2, "x", "x", "212345678001");
    altaDeUsuarioCARGARDATOSPREESTABLECIDOS("carlos78", "asdfghj", 18, 6, 1986, 2, "x", "x", "356789012345");
    altaDeUsuarioCARGARDATOSPREESTABLECIDOS("diegom", "zxcvbn", 28, 7, 1993, 2, "x", "x", "190123456789");
    altaDeUsuarioCARGARDATOSPREESTABLECIDOS("juan87", "1qaz2wsx", 20, 10, 1992, 1, "Melo", "Av. 18 de Julio 456", "x");
    altaDeUsuarioCARGARDATOSPREESTABLECIDOS("laura", "3edc4rfv", 22, 9, 1979, 1, "Montevideo", "Rondeau 1617", "x");
    altaDeUsuarioCARGARDATOSPREESTABLECIDOS("maria01", "5tgb6yhn", 2, 3, 1985, 2, "x", "x", "321098765432");
    altaDeUsuarioCARGARDATOSPREESTABLECIDOS("natalia", "poiuyt", 14, 4, 1982, 1, "Salto", "Paysandu 2021", "x");
    altaDeUsuarioCARGARDATOSPREESTABLECIDOS("pablo10", "lkjhgv", 30, 11, 1995, 1, "Mercedes", "Av. Rivera 1819", "x");
    altaDeUsuarioCARGARDATOSPREESTABLECIDOS("roberto", "mnbvcx", 12, 8, 1990, 1, "Montevideo", "Av. Brasil 1011", "x");
    altaDeUsuarioCARGARDATOSPREESTABLECIDOS("sofia25", "1234asdf", 7, 12, 1983, 2, "x", "x", "445678901234");

    altaDeProductoCARGARDATOSPREESTABLECIDOS("carlos78", "Camiseta Azul", "Camiseta de poliester, color azul", 1400, 50, 2);
    altaDeProductoCARGARDATOSPREESTABLECIDOS("ana23", "Televisor LED", "Televisor LED 55 pulgadas", 40500, 30, 1);
    altaDeProductoCARGARDATOSPREESTABLECIDOS("carlos78", "Chaqueta de Cuero", "Chaqueta de cuero, color negro", 699.99, 20, 2);
    altaDeProductoCARGARDATOSPREESTABLECIDOS("ana23", "Microondas Digital", "Microondas digital, 30L", 1199.99, 15, 1);
    altaDeProductoCARGARDATOSPREESTABLECIDOS("diegom", "Luz LED", "Luz Bluetooth LED", 599.99, 40, 3);
    altaDeProductoCARGARDATOSPREESTABLECIDOS("carlos78", "Pantalones Vaqueros", "Pantalones vaqueros, talla 32", 60, 25, 2);
    altaDeProductoCARGARDATOSPREESTABLECIDOS("diegom", "Auriculares Bluetooth", "Auriculares bluethooth para celular", 199.99, 35, 3);
    altaDeProductoCARGARDATOSPREESTABLECIDOS("ana23", "Refrigerador", "Refrigerador de doble puerta", 15499, 10, 1);
    altaDeProductoCARGARDATOSPREESTABLECIDOS("ana23", "Cafetera", "Cafetera de goteo programable", 23000, 50, 1);
    altaDeProductoCARGARDATOSPREESTABLECIDOS("carlos78", "Zapatillas Deportivas", "Zapatillas para correr, talla 42", 5500, 20, 2);
    altaDeProductoCARGARDATOSPREESTABLECIDOS("carlos78", "Mochila", "Mochila de viaje, 40L", 9000, 30, 3);
    altaDeProductoCARGARDATOSPREESTABLECIDOS("diegom", "Plancha de Ropa", "Plancha a vapor, 1500W", 12534, 25, 1);
    altaDeProductoCARGARDATOSPREESTABLECIDOS("sofia25", "Gorra", "Gorra para deportes, color rojo", 200, 50, 2);
    altaDeProductoCARGARDATOSPREESTABLECIDOS("diegom", "Tablet", "Tablet Android de 10 pulgadas", 15000, 15, 1);
    altaDeProductoCARGARDATOSPREESTABLECIDOS("sofia25", "Reloj de Pared", "Reloj de pared vintage", 150.50, 20, 3);

    map<int, int> promo1;
    promo1.insert({2, 1}); // key idProd, value CantidadProd
    promo1.insert({4, 1});
    promo1.insert({8, 1});

    map<int, int> promo2;
    promo2.insert({3, 2});
    promo2.insert({6, 3});

    map<int, int> promo3;
    promo1.insert({5, 2});

    map<int, int> promo4;
    promo4.insert({14, 1});

    crearPromocionCARGARDATOSPREESTABLECIDOS("Casa nueva", "Para que puedas ahorrar en la casa nueva", 30, 25, 10, 2024, promo1, "ana23");
    crearPromocionCARGARDATOSPREESTABLECIDOS("Fiesta", "Para que no te quedes sin ropa para las fiestas", 20, 26, 10, 2024, promo2, "carlos78");
    crearPromocionCARGARDATOSPREESTABLECIDOS("Domotica", "Para modernizar tu casa", 10, 26, 10, 2024, promo3, "diegom");
    crearPromocionCARGARDATOSPREESTABLECIDOS("Liquidacion", "Hasta agotar stock", 10, 26, 03, 2024, promo4, "diegom");

    map<int, int> compra1;
    compra1.insert({2, 2});//id prod //cantidad
    compra1.insert({4, 1});
    compra1.insert({8, 1});
    map<int, bool> enviado1;
    enviado1.insert({2, true});
    enviado1.insert({4, false});
    enviado1.insert({8, false});

    map<int, int> compra2;
    compra2.insert({5, 1});
    map<int, bool> enviado2;
    enviado2.insert({5, true});

    map<int, int> compra3;
    compra3.insert({14, 10});
    map<int, bool> enviado3;
    enviado3.insert({14, true});

    map<int, int> compra4;
    compra4.insert({11, 1});
    compra4.insert({12, 1});
    compra4.insert({13, 1});
    map<int, bool> enviado4;
    enviado4.insert({11, true});
    enviado4.insert({12, true});
    enviado4.insert({13, true});

    map<int, int> compra5;
    compra5.insert({3, 2});
    compra5.insert({6, 3});
    map<int, bool> enviado5;
    enviado5.insert({3, false});
    enviado5.insert({6, true});

    map<int, int> compra6;
    compra6.insert({1, 2});
    map<int, bool> enviado6;
    enviado6.insert({1, false});

    map<int, int> compra7;
    compra7.insert({1, 3});
    map<int, bool> enviado7;
    enviado7.insert({1, true});

    map<int, int> compra8;
    compra8.insert({1, 4});
    map<int, bool> enviado8;
    enviado8.insert({1, false});

    map<int, int> compra9;
    compra9.insert({1, 5});
    map<int, bool> enviado9;
    enviado9.insert({1, false});

    realizarCompraCARGARDATOSPREESTABLECIDOS("juan87", compra1, enviado1, DTFecha(1, 5, 2024));
    realizarCompraCARGARDATOSPREESTABLECIDOS("juan87", compra2, enviado2, DTFecha(1, 5, 2024));
    realizarCompraCARGARDATOSPREESTABLECIDOS("laura", compra3, enviado3, DTFecha(15, 5, 2024));
    realizarCompraCARGARDATOSPREESTABLECIDOS("natalia", compra4, enviado4, DTFecha(25, 4, 2024));
    realizarCompraCARGARDATOSPREESTABLECIDOS("juan87", compra5, enviado5, DTFecha(20, 5, 2024));
    realizarCompraCARGARDATOSPREESTABLECIDOS("laura", compra6, enviado6, DTFecha(12, 5, 2024));
    realizarCompraCARGARDATOSPREESTABLECIDOS("natalia", compra7, enviado7, DTFecha(13,05,2024));
    realizarCompraCARGARDATOSPREESTABLECIDOS("pablo10", compra8, enviado8, DTFecha(14, 05, 2024));
    realizarCompraCARGARDATOSPREESTABLECIDOS("roberto", compra9, enviado9, DTFecha(15,05,2024));

    //  si comenta entonces opcion = 1, si responde un comentario entonces opcion = 2
    dejarComentarioCARGARDATOSPREESTABLECIDOS("juan87", 1, "¿La camiseta azul esta disponible en talla M?", 0, DTFecha(01, 06, 2024), 1);
    dejarComentarioCARGARDATOSPREESTABLECIDOS("carlos78", 1, "Si, tenemos la camiseta azul en talla M.", 1, DTFecha(01, 06, 2024), 2);
    dejarComentarioCARGARDATOSPREESTABLECIDOS("laura", 1, "¿Es de buen material? Me preocupa la durabilidad.", 2, DTFecha(02, 06, 2024), 2);
    dejarComentarioCARGARDATOSPREESTABLECIDOS("juan87", 1, "He comprado antes y la calidad es buena.", 3, DTFecha(02, 06, 2024), 2);
    dejarComentarioCARGARDATOSPREESTABLECIDOS("natalia", 1, "¿Como es el ajuste? ¿Es ajustada o holgada?", 0, DTFecha(02, 06, 2024), 1);
    dejarComentarioCARGARDATOSPREESTABLECIDOS("laura", 2, "¿Cual es la resolucion del Televisor LED?", 0, DTFecha(02, 06, 2024), 1);
    dejarComentarioCARGARDATOSPREESTABLECIDOS("ana23", 2, "El televisor LED tiene una resolucion de 4K UHD.", 6, DTFecha(02, 06, 2024), 2);
    dejarComentarioCARGARDATOSPREESTABLECIDOS("pablo10", 2, "¿Tiene soporte para HDR10?", 0, DTFecha(03, 06, 2024), 1);
    dejarComentarioCARGARDATOSPREESTABLECIDOS("ana23", 2, "Si, soporta HDR10.", 8, DTFecha(03, 06, 2024), 2);
    dejarComentarioCARGARDATOSPREESTABLECIDOS("natalia", 3, "¿La chaqueta de cuero es resistente al agua?", 0, DTFecha(03, 06, 2024), 1);
    dejarComentarioCARGARDATOSPREESTABLECIDOS("carlos78", 3, "No, la chaqueta de cuero no es resistente al agua.", 10, DTFecha(03, 06, 2024), 2);
    dejarComentarioCARGARDATOSPREESTABLECIDOS("laura", 3, "¿Viene en otros colores?", 10, DTFecha(04, 06, 2024), 2);
    dejarComentarioCARGARDATOSPREESTABLECIDOS("carlos78", 3, "Si, tambien esta disponible en marron.", 12, DTFecha(04, 06, 2024), 2);
    dejarComentarioCARGARDATOSPREESTABLECIDOS("roberto", 3, "¿Es adecuada para climas frios?", 10, DTFecha(04, 06, 2024), 2);
    dejarComentarioCARGARDATOSPREESTABLECIDOS("pablo10", 4, "¿El microondas digital tiene funcion de descongelacion rapida?", 0, DTFecha(04, 06, 2024), 1);
    dejarComentarioCARGARDATOSPREESTABLECIDOS("ana23", 4, "Si, el microondas digital incluye una funcion de descongelacion rapida.", 15, DTFecha(04, 06, 2024), 2);
    dejarComentarioCARGARDATOSPREESTABLECIDOS("natalia", 4, "¿Cuantos niveles de potencia tiene?", 15, DTFecha(05, 06, 2024), 2);
    dejarComentarioCARGARDATOSPREESTABLECIDOS("ana23", 4, "Tiene 10 niveles de potencia", 17, DTFecha(05, 06, 2024), 2);
    dejarComentarioCARGARDATOSPREESTABLECIDOS("roberto", 4, "¿Es facil de limpiar?", 15, DTFecha(05, 06, 2024), 2);
    dejarComentarioCARGARDATOSPREESTABLECIDOS("roberto", 5, "¿La luz LED se puede controlar con una aplicacion movil?", 0, DTFecha(05, 06, 2024), 1);
    dejarComentarioCARGARDATOSPREESTABLECIDOS("diegom", 5, "Si, la luz LED se puede controlar a traves de una aplicacion movil.", 20, DTFecha(05, 06, 2024), 2);
    dejarComentarioCARGARDATOSPREESTABLECIDOS("pablo10", 5, "¿Es compatible con Alexa o Google Home?", 20, DTFecha(06, 06, 2024), 2);
    dejarComentarioCARGARDATOSPREESTABLECIDOS("diegom", 5, "Si, es compatible con ambos.", 22, DTFecha(06, 06, 2024), 2);
    dejarComentarioCARGARDATOSPREESTABLECIDOS("natalia", 5, "¿Cuanto dura la bateria?", 20, DTFecha(06, 06, 2024), 2);
    dejarComentarioCARGARDATOSPREESTABLECIDOS("pablo10", 5, "¿La aplicacion movil es facil de usar?", 20, DTFecha(07, 06, 2024), 2);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    Fabrica *fabrica = Fabrica::getInstanceF();      // Se crea instancia única de fábrica
    IUsuario *controladorU = fabrica->getIUsuario(); // Se crea la instancia del controlador CUsuario de tipo IUsuario
    IVenta *controladorV = fabrica->getIVenta();
    INotificacion *controladorN = fabrica->getINotificacion();
    IFecha *controladorF = fabrica->getIFecha();

    int dia, mes, anio;

    cout << "Ingrese fecha actual. ";
    cout << "\nIngrese dia: ";
    cin >> dia;
    cout << "\nIngrese mes: ";
    cin >> mes;
    cout << "\nIngrese anio: ";
    cin >> anio;
    controladorF->setFecha(dia, mes, anio);
    while (!controladorF->esFechaValida(controladorF->getFecha()))
    {
        cout << "\nIngrese una fecha valida: ";
        cout << "\nIngrese dia: ";
        cin >> dia;
        cout << "\nIngrese mes: ";
        cin >> mes;
        cout << "\nIngrese anio: ";
        cin >> anio;
        controladorF->setFecha(dia, mes, anio);
    }
    cout << "\n";
    controladorV->setContador();
    controladorU->setContadorComentario();
    controladorV->setContadorCompra();
    // /////////////////////////////////////////////
    // ///////////////CARGA DE DATOS////////////////
    // /////////////////////////////////////////////

    // ifstream archivoUsuarios(ARCHIVO_USUARIOS);
    // ifstream archivoUsuariosClientes(ARCHIVO_USUARIOS_CLIENTES);
    // ifstream archivoUsuariosVendedores(ARCHIVO_USUARIOS_VENDEDORES);
    // string linea;
    // char delimitador = ';';
    // // Lee primera linea y la descarta, es encabezado de columnas
    // getline(archivoUsuarios, linea);
    // getline(archivoUsuariosClientes, linea);
    // getline(archivoUsuariosVendedores, linea);

    // // Acá empieza la carga de usuario
    // while (getline(archivoUsuarios, linea))
    // {
    //     stringstream stream(linea); // Convierte la cadena a un stream
    //     string ref, tipo, nickname, contrasena, fechaNacimiento;
    //     getline(stream, ref, delimitador);
    //     getline(stream, tipo, delimitador);
    //     getline(stream, nickname, delimitador);
    //     getline(stream, contrasena, delimitador);
    //     getline(stream, fechaNacimiento, delimitador);

    //     int dia, mes, anio;
    //     // Usamos sscanf para extraer día, mes y año de la cadena de fecha
    //     sscanf(fechaNacimiento.c_str(), "%d/%d/%d", &dia, &mes, &anio);
    //     DTFecha fecha(dia, mes, anio);

    //     controladorU->ingresarUsuario(nickname, contrasena, fecha);

    //     if (tipo == "C")
    //     {
    //         while (!controladorU->existeUsuarioIgualNickname(nickname) && getline(archivoUsuariosClientes, linea))
    //         {
    //             string refCli, numeroPuerta, calle, ciudad;
    //             stringstream stream2(linea); // Convierte la cadena a un stream
    //             getline(stream2, refCli, delimitador);
    //             if (refCli == ref)
    //             {
    //                 getline(stream2, numeroPuerta, delimitador);
    //                 getline(stream2, calle, delimitador);
    //                 getline(stream2, ciudad, delimitador);
    //                 string direccion = calle + " " + numeroPuerta;
    //                 controladorU->altaCliente(direccion, ciudad);
    //             }
    //             controladorU->confirmarAltaUsuario();
    //         }
    //     }
    //     else if (tipo == "V")
    //     {
    //         while (!controladorU->existeUsuarioIgualNickname(nickname) && getline(archivoUsuariosVendedores, linea))
    //         {
    //             string refVend, codigoRUT;
    //             stringstream stream3(linea); // Convierte la cadena a un stream
    //             getline(stream3, refVend, delimitador);
    //             if (refVend == ref)
    //             {
    //                 getline(stream3, codigoRUT, delimitador);
    //                 controladorU->altaVendedor(codigoRUT);
    //             }
    //             controladorU->confirmarAltaUsuario();
    //         }
    //     }
    // }
    // archivoUsuarios.close();
    // archivoUsuariosClientes.close();
    // archivoUsuariosVendedores.close();
    // /////////////////////////////////////////////
    // //////////FINALIZA CARGA DE DATOS////////////
    // /////////////////////////////////////////////

    int opcion;
    bool continuar = true;
    while (continuar)
    {
        cout << "╔══════════════════════════════════════════════════╗" << endl;
        cout << "║         🚀 Seleccione un caso de uso 🚀          ║" << endl;
        cout << "╠══════════════════════════════════════════════════╣" << endl;
        cout << "║  1. 👤 Alta de usuario                           ║" << endl;
        cout << "║  2. 👥 Listado de usuarios                       ║" << endl;
        cout << "║  3. 📦 Alta de producto                          ║" << endl;
        cout << "║  4. 🔍 Consultar producto                        ║" << endl;
        cout << "║  5. 🏷️ Crear promoción                            ║" << endl;
        cout << "║  6. 🔎 Consultar promoción                       ║" << endl;
        cout << "║  7. 🛒 Realizar compra                           ║" << endl;
        cout << "║  8. 💬 Dejar comentario                          ║" << endl;
        cout << "║  9. ❌ Eliminar comentario                       ║" << endl;
        cout << "║ 10. 📤 Enviar producto                           ║" << endl;
        cout << "║ 11. 🗂️ Expediente de Usuario                      ║" << endl;
        cout << "║ 12. 🔔 Suscribirse a notificaciones              ║" << endl;
        cout << "║ 13. 📩 Consulta de notificaciones                ║" << endl;
        cout << "║ 14. 🗑️ Eliminar suscripciones                     ║" << endl;
        cout << "║ 15. 📋 Cargar datos preestablecidos              ║" << endl;
        cout << "║ 16. 🛑 Terminar programa                         ║" << endl;
        cout << "╚══════════════════════════════════════════════════╝" << endl;
        cout << "Ingrese el número correspondiente al caso de uso a ejecutar: ";
        cin >> opcion;

        cout << "\n";
        cout << "╔══════════════════════════════════════════════════╗" << endl;
        switch (opcion)
        {
        case 1:
            cout << "║ 👤 Ejecutando caso de uso: Alta de usuario       ║" << endl;
            cout << "╚══════════════════════════════════════════════════╝" << endl;
            altaDeUsuario();
            break;
        case 2:
            cout << "║ 👥 Ejecutando caso de uso: Listado de usuarios   ║" << endl;
            cout << "╚══════════════════════════════════════════════════╝" << endl;
            listadoDeUsuarios();
            break;
        case 3:
            cout << "║ 📦 Ejecutando caso de uso: Alta de producto      ║" << endl;
            cout << "╚══════════════════════════════════════════════════╝" << endl;
            altaDeProducto();
            break;
        case 4:
            cout << "║ 🔍 Ejecutando caso de uso: Consultar producto    ║" << endl;
            cout << "╚══════════════════════════════════════════════════╝" << endl;
            consultarProducto();
            break;
        case 5:
            cout << "║ 🏷️ Ejecutando caso de uso: Crear promoción       ║" << endl;
            cout << "╚══════════════════════════════════════════════════╝" << endl;
            crearPromocion();
            break;
        case 6:
            cout << "║ 🔎 Ejecutando caso de uso: Consultar promoción   ║" << endl;
            cout << "╚══════════════════════════════════════════════════╝" << endl;
            consultarPromocion();
            break;
        case 7:
            cout << "║ 🛒 Ejecutando caso de uso: Realizar compra       ║" << endl;
            cout << "╚══════════════════════════════════════════════════╝" << endl;
            realizarCompra();
            break;
        case 8:
            cout << "║ 💬 Ejecutando caso de uso: Dejar comentario      ║" << endl;
            cout << "╚══════════════════════════════════════════════════╝" << endl;
            dejarComentario();
            break;
        case 9:
            cout << "║ ❌ Ejecutando caso de uso: Eliminar comentario   ║" << endl;
            cout << "╚══════════════════════════════════════════════════╝" << endl;
            eliminarComentario();
            break;
        case 10:
            cout << "║ 📤 Ejecutando caso de uso: Enviar producto       ║" << endl;
            cout << "╚══════════════════════════════════════════════════╝" << endl;
            enviarProducto();
            break;
        case 11:
            cout << "║ 🗂️ Ejecutando caso de uso: Expediente de Usuario ║" << endl;
            cout << "╚══════════════════════════════════════════════════╝" << endl;
            expedienteDeUsuario();
            break;
        case 12:
            cout << "║ 🔔 Ejecutando caso de uso: Suscribirse a notificaciones ║" << endl;
            cout << "╚═════════════════════════════════════════════════════════╝" << endl;
            suscribirANotificaciones();
            break;
        case 13:
            cout << "║ 📩 Ejecutando caso de uso: Consulta de notificaciones ║" << endl;
            cout << "╚═══════════════════════════════════════════════════════╝" << endl;
            consultaDeNotificacion();
            break;
        case 14:
            cout << "║ 🗑️ Ejecutando caso de uso: Eliminar suscripciones ║" << endl;
            cout << "╚═══════════════════════════════════════════════════╝" << endl;
            eliminarSuscripciones();
            break;
        case 15:
            cout << "║ 📋 Ejecutando caso de uso: Cargar datos preestablecidos ║" << endl;
            cout << "╚═════════════════════════════════════════════════════════╝" << endl;
            cargarDatosPreestablecidos();
            break;
        case 16:
            cout << "║ 🛑 Terminando programa...                        ║" << endl;
            cout << "╚══════════════════════════════════════════════════╝" << endl;

            continuar = false;
            break;
        default:
            cout << "║ ⚠️ Opción no válida. Intente nuevamente.        ║" << endl;
            cout << "╚════════════════════════════════════════════════╝" << endl;
        }
    }
    return 0;
}
