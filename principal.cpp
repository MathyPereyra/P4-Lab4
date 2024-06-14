#include <string>
#include <set>
#include <map>
#include <iostream>

#include "datatypes.h"
#include "observer.h"
#include "producto.h"
#include "promocion.h"
#include "compra_producto.h"
#include "compra.h"
#include "vendedor.h"
#include "cliente.h"
#include "producto.h"






int main()
{
int opcion;
bool continuar = true;
while (continuar) 
{
    cout << "Presione un numero para elegir un caso de uso: " << endl;
    cout << "   1: Alta de usuario" << endl << "2: Listado de usuarios" << endl << "3: Alta de producto" << endl << "4: Consultar producto" << endl << "5: Crear promocion" << endl << "6: Consultar promocion" << endl << "7: Realizar compra" << endl << "8: Dejar comentario" << endl<< "9: Eliminar comentario" << endl << "10: Enviar producto" << endl << "11: Expediente de Usuario" << endl << "12: Suscribirse a notificaciones" << endl << "13: Consulta de notificaciones" << endl << "14: Eliminar suscripciones" << endl << "15: Terminar programa" << endl;
    cout << "Ingrese el numero correspondiente al caso de uso a ejecutar: "
    cin >> opcion;
    switch (opcion)
    {
        case 1:
            cout << "Ejecutando caso de uso: Alta de usuario" << endl;

        case 2:
            cout << "Ejecutando caso de uso: Listado de usuarios" << endl;

        case 3:
            cout << "Ejecutando caso de uso: Alta de producto" << endl;

        case 4:
            cout << "Ejecutando caso de uso: Consultar producto" << endl;

        case 5:
            cout << "Ejecutando caso de uso: Crear promocion" << endl;

        case 6:
            cout << "Ejecutando caso de uso: Consultar promocion" << endl;

        case 7:
            cout << "Ejecutando caso de uso: Realizar compra" << endl;

        case 8:
            cout << "Ejecutando caso de uso: Dejar comentario" << endl;

        case 9:
            cout << "Ejecutando caso de uso: Eliminar Comentario" << endl;

        case 10:
            cout << "Ejecutando caso de uso: Enviar Producto" << endl;

        case 11:
            cout << "Ejecutando caso de uso: Expediente de Usuario" << endl;

        case 12:
            cout << "Ejecutando caso de uso: Suscribirse a notificaciones" << endl;

        case 13:
            cout << "Ejecutando caso de uso: Consulta de notificaciones" << endl;       

        case 14:
            cout << "Ejecutando caso de uso: Eliminar suscripciones" << endl;

        case 15:
            cout << "Terminando programa...\n";
            continuar = false;
            break;
        
        default: 
            cout << "Opcion no valida. Intente nuevamente.\n"
    }
}


return 0;
}