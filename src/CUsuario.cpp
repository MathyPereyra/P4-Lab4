#include "../include/CUsuario.h"
#include "../include/usuario.h"
#include "../include/comentario.h"
#include "../include/CVenta.h"

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

void ControladorUsuario::confirmarAltaUsuario() {
};

// void ControladorUsuario::setDataUsuario(string nickname, string contrasena, DTFecha fechaNac) {

// };

set<DTUsuario *> ControladorUsuario::listadoUsuarios(string tipoDeUsuario)
{
    set<DTUsuario *> resultado;
    map<string, Usuario *>::iterator it;
    for (it = this->usuarios.begin(); it != this->usuarios.end(); ++it)
    {
        if (tipoDeUsuario == "cliente")
        {
            Cliente *cliente = dynamic_cast<Cliente *>(it->second);
            if (cliente != NULL)
            {
                resultado.insert(cliente->getDatosCliente());
            }
        }
        else if (tipoDeUsuario == "vendedor")
        {
            Vendedor *vendedor = dynamic_cast<Vendedor *>(it->second);
            if (vendedor != NULL)
            {
                resultado.insert(vendedor->getDatosUsuario());
            }
        }
    }
    return resultado;
};

set<DTCliente> listadoClientes()
{
}

map<string, Usuario *> ControladorUsuario::getMapaUsuarios(string tipoDeUsuario)
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
                resultado[cliente->getNickname()] = cliente;
            }
        }
        else if (tipoDeUsuario == "vendedor")
        {
            Vendedor *vendedor = dynamic_cast<Vendedor *>(it->second);
            if (vendedor != NULL)
            {
                resultado[vendedor->getNickname()] = vendedor;
            }
        }
        else
        {
            resultado[it->second->getNickname()] = it->second;
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

set<DTUsuario *> ControladorUsuario::listadoUsuarios()
{
    set<DTUsuario *> resultado;
    map<string, Usuario *>::iterator it;
    for (it = this->usuarios.begin(); it != this->usuarios.end(); ++it)
    {

        resultado.insert(it->second->getDatosUsuario());
    }
    return resultado;
};

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

set<DTComentario> ControladorUsuario::listadoComentario(int id)
{
    Producto *prod = ControladorVenta::getInstanciaVen()->seleccionarProductoPorId(id);
    map<int, Comentario *>::iterator it;
    map<int, Comentario *> comens = prod->listadoComentarios();
    set<DTComentario> dataComens;
    for (it = comens.begin(); it != comens.end(); it++)
    {
        DTComentario dataC = DTComentario(it->second->getText(), it->second->getId(), it->second->getFecha());
        dataComens.insert(dataC);
    }
    return dataComens;
};

set<DTComentario> ControladorUsuario::listadoComentario(string nickname)
{
    Usuario *user = obtenerUsuarioPorNickname(nickname);
    map<int, Comentario *>::iterator it;
    map<int, Comentario *> comens = user->getComentarios();
    set<DTComentario> dataComens;
    for (it = comens.begin(); it != comens.end(); it++)
    {
        DTComentario dataC = DTComentario(it->second->getText(), it->second->getId(), it->second->getFecha());
        dataComens.insert(dataC);
    }
    return dataComens;
};

bool ControladorUsuario::hayComentarios(int id)
{
    Producto *prod = ControladorVenta::getInstanciaVen()->seleccionarProductoPorId(id);
    return (!prod->listadoComentarios().empty());
}

void ControladorUsuario::recordarUsuario(string nickname)
{
    Usuario *usuario = obtenerUsuarioPorNickname(nickname);
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

void ControladorUsuario::crearComentario(string texto, int idP, string nicknameU)
{
    Usuario *usuario = obtenerUsuarioPorNickname(nicknameU);
    Producto *producto = ControladorVenta::getInstanciaVen()->seleccionarProductoPorId(idP);
    int id = this->getContadorComentario();
    this->avanzarContadorComentario();
    DTFecha fecha = DTFecha();
    Comentario *nuevo = new Comentario(texto, fecha, id, producto);
    producto->agregarComentario(id, nuevo);
    usuario->agregarComentario(id, nuevo);
};

void ControladorUsuario::crearRespuesta(string texto, int idC, int idP)
{
    Producto *prod = ControladorVenta::getInstanciaVen()->seleccionarProductoPorId(idP);
    map<int, Comentario *> comens = prod->listadoComentarios();
    Comentario *comentarioOg = comens.find(idC)->second;
    int id = this->getContadorComentario();
    this->avanzarContadorComentario();
    DTFecha fecha = DTFecha();
    Comentario *nuevo = new Comentario(texto, fecha, id);
    comentarioOg->agregarRespuesta(nuevo);
};

DTUsuario *ControladorUsuario::getDatosUsuario(string nickname)
{
    Usuario *user = this->obtenerUsuarioPorNickname(nickname);
    return user->getDatosUsuario();
}

ControladorUsuario::ControladorUsuario(){};

ControladorUsuario *ControladorUsuario::instancia = nullptr;

ControladorUsuario *ControladorUsuario::getInstance()
{
    if (instancia == nullptr)
        instancia = new ControladorUsuario();
    return instancia;
};
