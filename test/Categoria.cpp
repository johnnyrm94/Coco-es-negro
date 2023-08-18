
#include "Categoria.h"

Categoria::Categoria(const std::string& nombre) : nombre(nombre), numEquiposAsociados(0) {
    // Initialize other attributes if needed
}

std::string Categoria::getNombre() const {
    return nombre; 
}
