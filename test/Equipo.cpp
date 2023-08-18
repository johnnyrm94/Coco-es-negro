#include "Equipo.h"

Equipo::Equipo(int codigo, const std::string& nombre) : codigo(codigo), nombre(nombre) {
    // Initialize other attributes if needed
}

int Equipo::getCodigo() const {
    return codigo;
}

std::string Equipo::getNombre() const {
    return nombre;
}
