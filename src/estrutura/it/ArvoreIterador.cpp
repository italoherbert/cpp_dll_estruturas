
#include "ArvoreIterador.h"

ArvoreIterador::ArvoreIterador() {
    this->pilha = nullptr;
}

bool ArvoreIterador::temProx() {
    return pilha != nullptr;
}

void ArvoreIterador::pushNaPilha( Arv* perc ) {
    Pilha* novo = new Pilha();
    novo->perc = perc;
    novo->prox = pilha;
    pilha = novo;
}

Arv* ArvoreIterador::popNaPilha() {
    if ( pilha == nullptr )
        return nullptr;

    Arv* perc = pilha->perc;

    Pilha* aux = pilha;
    pilha = pilha->prox;
    delete aux;

    return perc;
}
