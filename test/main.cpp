#include <iostream>
#include "Equipo.h"
#include "EquipoNode.h"
#include "EquipoList.h"

int main() {
    EquipoList equipoList;

    equipoList.agregarEquipo(new Equipo(1, "Equipo A", 2000, 5, "Alquilado"));
    equipoList.agregarEquipo(new Equipo(3, "Equipo C", 2010, 6, "Disponible"));
    equipoList.agregarEquipo(new Equipo(2, "Equipo B", 2020, 4, "Alquilado"));

    std::cout << "Original Catalog:" << std::endl;
    equipoList.listarCatalogoAscendentePorCodigo();

    std::cout << "\nCatalog Sorted by Nombre (Ascending):" << std::endl;
    equipoList.listarCatalogoAscendentePorNombre();

    std::cout << "\nCatalog Sorted by Nombre (Descending):" << std::endl;
    equipoList.listarCatalogoDescendentePorNombre();

    std::cout << "\nCatalog with Description 'Equipo':" << std::endl;
    equipoList.listarEquiposConDescripcion("Equipo");

    std::cout << "\nCatalog within Year Range 2000 - 2020:" << std::endl;
    equipoList.listarEquiposRangoAnio(2000, 2020);

    std::cout << "\nCatalog with pH Level between 4 and 7:" << std::endl;
    equipoList.listarEquiposPorNivelesAcidez(4, 7);

    std::cout << "\nModifying Equipo B's Nombre and Estado:" << std::endl;
    equipoList.modificarEquipo(2, "Nuevo Equipo B", "Disponible");

    std::cout << "\nUpdated Catalog:" << std::endl;
    equipoList.listarCatalogoAscendentePorCodigo();

    return 0;
}
