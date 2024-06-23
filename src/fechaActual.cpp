#include "../include/fechaActual.h"
#include <ctime>

fechaActual *fechaActual::instance = nullptr;

fechaActual::fechaActual() {}

fechaActual *fechaActual::getInstance()
{
  if (instance == nullptr)
  {
    instance = new fechaActual();
  }
  return instance;
}

std::tm fechaActual::getFechaActual()
{
  return this->currentDate;
}
