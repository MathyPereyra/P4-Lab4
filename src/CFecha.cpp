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
};

bool ControladorFecha::esBisiesto(int anio)
{
    if ((anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0))
    {
        return true;
    }
    return false;
};

bool ControladorFecha::esFechaValida(DTFecha fecha)
{
    int diasPorMes[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (fecha.getMes() < 1 || fecha.getMes() > 12)
    {
        return false;
    }

    if (this->esBisiesto(fecha.getAnio()) && fecha.getAnio() == 2)
    {
        diasPorMes[1] = 29;
    }

    if (fecha.getDia() < 1 || fecha.getDia() > diasPorMes[fecha.getMes() - 1])
    {
        return false;
    }

    return true;
};


ControladorFecha::ControladorFecha(){};

ControladorFecha *ControladorFecha::instancia = nullptr;

ControladorFecha *ControladorFecha::getInstanciaFecha()
{
    if (instancia == nullptr)
        instancia = new ControladorFecha();
    return instancia;
};
