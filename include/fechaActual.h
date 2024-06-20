#ifndef FECHAACTUAL_H
#define FECHAACTUAL_H

#include <ctime>
#include <string>

class fechaActual {
private:
    static fechaActual* instance;
    std::tm currentDate;

    fechaActual();

public:
    static fechaActual* getInstance();
    std::tm getFechaActual();
    void setFechaActual(std::tm newDate);
    std::string getFechaActualString();
};

#endif 
