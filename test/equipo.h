#ifndef EQUIPO_H
#define EQUIPO_H

#include <string>

class Equipo {
private:
    int codigo;
    std::string nombre;

public:
    Equipo(int codigo, const std::string& nombre);
    int getCodigo() const;
    std::string getNombre() const;
};

#endif // EQUIPO_H
