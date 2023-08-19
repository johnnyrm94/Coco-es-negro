#ifndef CATEGORIA_H
#define CATEGORIA_H

#include <string>

class Categoria {
private:
    std::string nombre;
    int numEquiposAsociados;

public:
    Categoria(const std::string& nombre);
    int getnumEquiposAsociados() const;
    std::string getNombre() const;
    void setnumEquiposAsociados(int n);
    void setNombre(std::string n);
};

#endif // CATEGORIA_H
