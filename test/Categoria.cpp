
#include "Categoria.h"

Categoria::Categoria(const std::string& nombre) : nombre(nombre), numEquiposAsociados(0) {
    // Initialize other attributes if needed
}

std::string Categoria::getNombre() const {
    return nombre;
}

void Categoria::setnumEquiposAsociados(int n){
numEquiposAsociados = n;
}

void Categoria::setNombre(std::string n){
nombre = n;
}
