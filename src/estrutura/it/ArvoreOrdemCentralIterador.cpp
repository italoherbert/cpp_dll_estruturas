
#include "ArvoreOrdemCentralIterador.h"

ArvoreOrdemCentralIterador::ArvoreOrdemCentralIterador( Arv* raiz ) : ArvoreIterador() {
    pushEsquerdosNaPilha( raiz );
}

Objeto* ArvoreOrdemCentralIterador::prox() {
    Arv* perc = ArvoreIterador::popNaPilha();

    pushEsquerdosNaPilha( perc->dir );

    return perc->dados;
}

void ArvoreOrdemCentralIterador::pushEsquerdosNaPilha( Arv* perc ) {
    Arv* p = perc;
    while( p != nullptr ) {
        ArvoreIterador::pushNaPilha( p );
        p = p->esq;
    }
}





