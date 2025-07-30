
#include "ArvoreIterador.h"

#include <cstdlib>

ArvoreIterador::ArvoreIterador() {
    this->pilha = NULL;
}

bool ArvoreIterador::temProx() {
    return pilha != NULL;
}

void ArvoreIterador::pushNaPilha( Arv* perc ) {
    Pilha* novo = new Pilha();
    novo->perc = perc;
    novo->prox = pilha;
    pilha = novo;
}

Arv* ArvoreIterador::popNaPilha() {
    if ( pilha == NULL )
        return NULL;

    Arv* perc = pilha->perc;

    Pilha* aux = pilha;
    pilha = pilha->prox;
    delete aux;

    return perc;
}
