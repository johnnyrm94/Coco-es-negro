#include "EquipoNode.h"

EquipoNode::EquipoNode(Equipo* equipo) : equipo(equipo), next(nullptr) {
    // Initialize other attributes if needed
}

Equipo* EquipoNode::getEquipo() const {
    return equipo;
}

EquipoNode* EquipoNode::getNext() const {
    return next;
}

void EquipoNode::setNext(EquipoNode* nextNode) {
    next = nextNode;
}
