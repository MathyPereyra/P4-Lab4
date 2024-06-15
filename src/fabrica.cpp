#include "../include/fabrica.h"

Fabrica* Fabrica::getInstance()
{
    if (instancia == NULL)
        instancia = new Fabrica();
    return instancia;
}


