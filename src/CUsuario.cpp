#include "../include/CUsuario.h"
#include "../include/usuario.h"
#include "../include/comentario.h"

#include <cstddef>

string ControladorUsuario::getmemNickname()
{
    return this->memNickname;
};

string ControladorUsuario::getmemContrasena()
{
    return this->memContrasena;
};

DTFecha ControladorUsuario::getmemFechaNac()
{
    return this->memFechaNac;
};

Usuario *ControladorUsuario::getmemUsuario()
{
    return this->memUsuario;
}

void ControladorUsuario::ingresarUsuario(string nickname, string contrasena, DTFecha fechaNac)
{
    this->memNickname = nickname;
    this->memContrasena = contrasena;
    this->memFechaNac = fechaNac;
};

bool ControladorUsuario::existeUsuarioIgualNickname(string nickname)
{
    bool existe = false;
    map<string, Usuario *>::iterator it;
    for (it = this->usuarios.begin(); it != this->usuarios.end(); ++it)
    {
        if (it->second->getNickname() == nickname)
        {
            existe = true;
            break;
        }
    }
    return existe;
};

// no se que iria aca
void ControladorUsuario::terminarAlta()
{
    // acá se debe de liberar memoria del DTUsuario credo temporalmente en ingresarUsuario,
    //  es para el caso en que el nickname ya existe en la colección de Usuarios
    this->memFechaNac.~DTFecha();
};



void ControladorUsuario::altaCliente(string direccion, string ciudad)
{
    Cliente *nuevo = new Cliente(this->memNickname, this->memContrasena, this->memFechaNac, direccion, ciudad);
    this->usuarios[this->memNickname] = nuevo;
};



void ControladorUsuario::altaVendedor(string codigoRUT)
{
    Vendedor *nuevo = new Vendedor(this->memNickname, this->memContrasena, this->memFechaNac, codigoRUT);
    this->usuarios[this->memNickname] = nuevo;
};



void ControladorUsuario::confirmarAltaUsuario()
{
    this->memFechaNac.~DTFecha();
};



// void ControladorUsuario::setDataUsuario(string nickname, string contrasena, DTFecha fechaNac) {

// };



// Se puede emprolijar sacando los if para afuera y el for dentro de cada if dependiendo el caso
map<string, Usuario*> ControladorUsuario::listadoUsuarios(string tipoDeUsuario)
{
    map<string, Usuario *> resultado;
    map<string, Usuario *>::iterator it;
    for (it = this->usuarios.begin(); it != this->usuarios.end(); ++it)
    {
        if (tipoDeUsuario == "cliente")
        {
            Cliente *cliente = dynamic_cast<Cliente *>(it->second);
            if (cliente != NULL)
            {
                resultado[it->second->getNickname()] = cliente; 
            }
        }
        else if (tipoDeUsuario == "vendedor")
        {
            Vendedor *vendedor = dynamic_cast<Vendedor *>(it->second);
            if ("cliente" != NULL)
            {
                resultado[it->second->getNickname()] = vendedor;
            }
        }
        else
        {
            resultado[it->second->getNickname()];
        }
    }
    return resultado;
};



Usuario *ControladorUsuario::obtenerUsuarioPorNickname(const string &nickname)
{
    map<string, Usuario *>::iterator it = usuarios.find(nickname);
    if (it != usuarios.end())
    {
        return it->second;
    }
    throw std::runtime_error("Usuario no encontrado");
};

map<string, Usuario*> ControladorUsuario::listadoUsuarios()
{
    return this->usuarios;
};

//set<DTUsuario> ControladorUsuario::listadoUsuarios()
//{
//    set<DTUsuario> dataUsuarios;
//    map<string, Usuario *>::iterator it;
//    for (it = this->usuarios.begin(); it != this->usuarios.end(); ++it)
//    {
//        dataUsuarios.insert(it->second->getDatosUsuario());
//    }
//
//    return dataUsuarios;
//};



void ControladorUsuario::setContadorComentario()
{
    this->contadorComentario = 0;
};



int ControladorUsuario::getContadorComentario()
{
    return this->contadorComentario;
};



void ControladorUsuario::avanzarContadorComentario()
{
    this->contadorComentario = this->contadorComentario + 1;
};



/*set<string> ControladorUsuario::listadoNicknameCliente()
{
    set<string> setNicknames;
    for(DTUsuario dtU : this->listadoUsuarios("cliente"))
    {
        setNicknames.insert(dtU.getNickname());
    }
    return setNicknames;
};*/



// aca asumi que el map usuarios de CUsuario que mapea usuarios a strings guarda como string el nickname del usuario
/* set<string> ControladorUsuario::listadoUsuarioNickname()
 {
    set<string> nombres;
    map<string, Usuario *>::iterator it;
    for (it = this->usuarios.begin(); it != this->usuarios.end(); ++it)
    {
        nombres.insert((it->second)->getNickname());
    }

    return nombres;
};*/



// set<DTComentario> ControladorUsuario::listadoComentario(string){

// };



void ControladorUsuario::recordarUsuario(Usuario *usuario)
{
    this->memUsuario = usuario;
}

void ControladorUsuario::eliminarComentario(int id)
{
    Usuario *usuario = getmemUsuario();
    map<int, Comentario *>::iterator it = usuario->getComentarios().find(id);
    it->second->eliminarComentario();
    liberarMemoriaUsuario();
}

void ControladorUsuario::liberarMemoriaUsuario()
{
    delete this->memUsuario;
}

void ControladorUsuario::crearComentario(string texto, Producto *producto)
{
    int id = this->getContadorComentario();
    this->avanzarContadorComentario();
    DTFecha fecha = DTFecha();
    Comentario *nuevo = new Comentario(texto, fecha, id, producto);
    producto->agregarComentario(id, nuevo);
};



void ControladorUsuario::crearRespuesta(string texto, Comentario * comentarioOg)
{
    int id = this->getContadorComentario();
    this->avanzarContadorComentario();
    DTFecha fecha = DTFecha();
    Comentario *nuevo = new Comentario(texto, fecha, id);
    comentarioOg->agregarRespuesta(nuevo);
};

ControladorUsuario::ControladorUsuario(){};

ControladorUsuario *ControladorUsuario::instancia = nullptr;

ControladorUsuario *ControladorUsuario::getInstance()
{
    if (instancia == nullptr)
        instancia = new ControladorUsuario();
    return instancia;
};
