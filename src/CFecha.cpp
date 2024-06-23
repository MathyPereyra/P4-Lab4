#include "../include/CFecha.h"

void ControladorFecha::setFecha(int dia, int mes, int anio)
{
    this->dia = dia;
    this->mes = mes;
    this->anio = anio;
};

DTFecha ControladorFecha::getFecha()
{
    return DTFecha(this->dia, this->mes, this->anio);
}

ControladorFecha::ControladorFecha(){};

ControladorFecha *ControladorFecha::instancia = nullptr;

ControladorFecha *ControladorFecha::getInstanciaFecha()
{
    if (instancia == nullptr)
        instancia = new ControladorFecha();
    return instancia;
};
