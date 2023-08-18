#ifndef CATEGORIA_H
#define CATEGORIA_H

#include <string>

class Categoria {
private:
    std::string nombre;
    int numEquiposAsociados;

public:
    Categoria(const std::string& nombre);
    std::string getNombre() const;
};

#endif // CATEGORIA_H
