
#include "InversoListaIterador.h"

InversoListaIterador::InversoListaIterador( Lst* topo ) {
    this->perc = topo;
}

bool InversoListaIterador::temProx() {
    return perc != nullptr;
}

Objeto* InversoListaIterador::prox() {
    Objeto* dados = perc->dados;
    perc = perc->ant;
    return dados;
}
