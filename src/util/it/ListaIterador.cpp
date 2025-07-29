
#include "ListaIterador.h"

#include <cstdlib>

ListaIterador::ListaIterador( Lst* topo ) {
    this->perc = topo;
}

bool ListaIterador::temProx() {
    return perc != NULL;
}

Objeto* ListaIterador::prox() {
    Objeto* dados = perc->dados;
    perc = perc->prox;
    return dados;
}
