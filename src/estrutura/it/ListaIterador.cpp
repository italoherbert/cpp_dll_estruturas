
#include "ListaIterador.h"

ListaIterador::ListaIterador( Lst* topo ) {
    this->perc = topo;
}

bool ListaIterador::temProx() {
    return perc != nullptr;
}

Objeto* ListaIterador::prox() {
    Objeto* dados = perc->dados;
    perc = perc->prox;
    return dados;
}
