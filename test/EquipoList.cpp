#include "EquipoList.h"
#include <iostream>

EquipoList::EquipoList() : head(nullptr) {
    // Initialize other attributes if needed
}

EquipoList::~EquipoList() {
    // Implement destructor logic to clean up memory
    EquipoNode* currentNode = head;
    while (currentNode != nullptr) {
        EquipoNode* tempNode = currentNode;
        currentNode = currentNode->getNext();
        delete tempNode->getEquipo();
        delete tempNode;
    }
}

// Method to add an equipo to the list
void EquipoList::agregarEquipo(Equipo* equipo) {
    EquipoNode* newNode = new EquipoNode(equipo);
    newNode->setNext(head);
    head = newNode;
}

void EquipoList::deleteSortedLinkedList(EquipoNode* head) {
    while (head != nullptr) {
        EquipoNode* temp = head;
        head = head->getNext();
        delete temp;
    }
}

// Method to remove an equipo from the list
void EquipoList::retirarEquipo(int codigo) {
    EquipoNode* currentNode = head;
    EquipoNode* prevNode = nullptr;

    while (currentNode != nullptr) {
        if (currentNode->getEquipo()->getCodigo() == codigo) {
            if (prevNode == nullptr) {
                head = currentNode->getNext();
            } else {
                prevNode->setNext(currentNode->getNext());
            }
            delete currentNode->getEquipo();
            delete currentNode;
            return;
        }
        prevNode = currentNode;
        currentNode = currentNode->getNext();
    }

    std::cout << "Equipo with codigo " << codigo << " not found." << std::endl;
}

// Method to find and return an equipo by its codigo
Equipo* EquipoList::consultarEquipo(int codigo) {
    EquipoNode* currentNode = head;
    while (currentNode != nullptr) {
        if (currentNode->getEquipo()->getCodigo() == codigo) {
            return currentNode->getEquipo();
        }
        currentNode = currentNode->getNext();
    }
    return nullptr;  // Equipo not found
}


// Method to modify the nombre of an equipo
void EquipoList::modificarEquipo(int codigo, const std::string& nuevoNombre, const std::string& nuevoEstado) {
    Equipo* equipo = consultarEquipo(codigo);
    if (equipo != nullptr) {
        equipo->setNombre(nuevoNombre);
        equipo->setEstado(nuevoEstado);
    } else {
        std::cout << "Equipo with codigo " << codigo << " not found." << std::endl;
    }
}

// Method to list the catalog in ascending order by codigo
void EquipoList::listarCatalogoAscendentePorCodigo() {
    EquipoNode* currentNode = head;
    while (currentNode != nullptr) {
        std::cout << "Codigo: " << currentNode->getEquipo()->getCodigo()
                  << ", Nombre: " << currentNode->getEquipo()->getNombre()
                  << ", Estado: " << currentNode->getEquipo()->getEstado() << std::endl;
        currentNode = currentNode->getNext();
    }
}

EquipoNode* reverseLinkedList(EquipoNode* head) {
    EquipoNode* prev = nullptr;
    EquipoNode* current = head;
    EquipoNode* next = nullptr;

    while (current != nullptr) {
        next = current->getNext();
        current->setNext(prev);
        prev = current;
        current = next;
    }

    return prev;
}


void EquipoList::listarCatalogoDescendentePorCodigo() {
    EquipoNode* reversedHead = reverseLinkedList(head);

    EquipoNode* currentNode = reversedHead;
    while (currentNode != nullptr) {
        std::cout << "Codigo: " << currentNode->getEquipo()->getCodigo()
                  << ", Nombre: " << currentNode->getEquipo()->getNombre()
                  << ", Estado: " << currentNode->getEquipo()->getEstado() << std::endl;
        currentNode = currentNode->getNext();
    }

    // Restore the original order of the linked list
    head = reverseLinkedList(reversedHead);
}

// Method to list the catalog in ascending order by nombre
void EquipoList::listarCatalogoAscendentePorNombre() {
    // Create a new linked list to store the sorted nodes
    EquipoNode* sortedHead = nullptr;

    EquipoNode* currentNode = head;
    while (currentNode != nullptr) {
        // Find the appropriate position in the sorted list to insert the current node
        EquipoNode* prev = nullptr;
        EquipoNode* temp = sortedHead;
        while (temp != nullptr && temp->getEquipo()->getNombre() < currentNode->getEquipo()->getNombre()) {
            prev = temp;
            temp = temp->getNext();
        }

        // Insert the current node in the sorted list
        EquipoNode* newNode = new EquipoNode(currentNode->getEquipo());
        if (prev == nullptr) {
            newNode->setNext(sortedHead);
            sortedHead = newNode;
        } else {
            prev->setNext(newNode);
            newNode->setNext(temp);
        }

        currentNode = currentNode->getNext();
    }

    // Print the sorted list
    currentNode = sortedHead;
    while (currentNode != nullptr) {
        std::cout << "Codigo: " << currentNode->getEquipo()->getCodigo()
                  << ", Nombre: " << currentNode->getEquipo()->getNombre()
                  << ", Estado: " << currentNode->getEquipo()->getEstado() << std::endl;
        currentNode = currentNode->getNext();
    }

    // Clean up memory
    deleteSortedLinkedList(sortedHead);
}

// Method to list the catalog in descending order by nombre
void EquipoList::listarCatalogoDescendentePorNombre() {
    // Create a new linked list to store the sorted nodes
    EquipoNode* sortedHead = nullptr;

    EquipoNode* currentNode = head;
    while (currentNode != nullptr) {
        // Find the appropriate position in the sorted list to insert the current node
        EquipoNode* prev = nullptr;
        EquipoNode* temp = sortedHead;
        while (temp != nullptr && temp->getEquipo()->getNombre() > currentNode->getEquipo()->getNombre()) {
            prev = temp;
            temp = temp->getNext();
        }

        // Insert the current node in the sorted list
        EquipoNode* newNode = new EquipoNode(currentNode->getEquipo());
        if (prev == nullptr) {
            newNode->setNext(sortedHead);
            sortedHead = newNode;
        } else {
            prev->setNext(newNode);
            newNode->setNext(temp);
        }

        currentNode = currentNode->getNext();
    }

    // Print the sorted list
    currentNode = sortedHead;
    while (currentNode != nullptr) {
        std::cout << "Codigo: " << currentNode->getEquipo()->getCodigo()
                  << ", Nombre: " << currentNode->getEquipo()->getNombre()
                  << ", Estado: " << currentNode->getEquipo()->getEstado() << std::endl;
        currentNode = currentNode->getNext();
    }

    // Clean up memory
    deleteSortedLinkedList(sortedHead);
}

// Method to list equipos with a specific description
void EquipoList::listarEquiposConDescripcion(const std::string& descripcion) {
    EquipoNode* currentNode = head;
    while (currentNode != nullptr) {
        if (currentNode->getEquipo()->getNombre().find(descripcion) != std::string::npos) {
            std::cout << "Codigo: " << currentNode->getEquipo()->getCodigo()
                      << ", Nombre: " << currentNode->getEquipo()->getNombre()
                      << ", Estado: " << currentNode->getEquipo()->getEstado() << std::endl;
        }
        currentNode = currentNode->getNext();
    }
}

// Method to list equipos within a specific year range
void EquipoList::listarEquiposRangoAnio(int anioInicio, int anioFin) {
    EquipoNode* currentNode = head;
    while (currentNode != nullptr) {
        if (currentNode->getEquipo()->getAnio() >= anioInicio && currentNode->getEquipo()->getAnio() <= anioFin) {
            std::cout << "Codigo: " << currentNode->getEquipo()->getCodigo()
                      << ", Nombre: " << currentNode->getEquipo()->getNombre()
                      << ", Estado: " << currentNode->getEquipo()->getEstado() << std::endl;
        }
        currentNode = currentNode->getNext();
    }
}

// Method to list equipos that meet pH level criteria
void EquipoList::listarEquiposPorNivelesAcidez(int minPh, int maxPh) {
    EquipoNode* currentNode = head;
    while (currentNode != nullptr) {
        int ph = currentNode->getEquipo()->getNivelesAcidez();
        if (ph >= minPh && ph <= maxPh) {
            std::cout << "Codigo: " << currentNode->getEquipo()->getCodigo()
                      << ", Nombre: " << currentNode->getEquipo()->getNombre()
                      << ", Estado: " << currentNode->getEquipo()->getEstado() << std::endl;
        }
        currentNode = currentNode->getNext();
    }
}

