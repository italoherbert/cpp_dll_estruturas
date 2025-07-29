
#include "ArvorePosOrdemIterador.h"

#include <cstdlib>

ArvorePosOrdemIterador::ArvorePosOrdemIterador( Arv* raiz ) : ArvoreIterador() {
    pushEsquerdosNaPilha( raiz );
}

Objeto* ArvorePosOrdemIterador::prox() {
    Arv* perc = ArvoreIterador::popNaPilha();
    Arv* pai = ArvoreIterador::popNaPilha();

    pushEsquerdosNaPilha( pai->dir );

    ArvoreIterador::pushNaPilha( pai );

    return perc->dados;
}

void ArvorePosOrdemIterador::pushEsquerdosNaPilha( Arv* perc ) {
    if ( perc != NULL ) {
        Arv* p = perc;
        while( p->esq != NULL && p->dir != NULL ) {
            Arv* ant = p;
            while( p != NULL ) {
                ArvoreIterador::pushNaPilha( p );
                ant = p;
                p = p->esq;
            }
            p = ant;
            if ( p->dir != NULL )
                p = p->dir;
        }
    }
}
