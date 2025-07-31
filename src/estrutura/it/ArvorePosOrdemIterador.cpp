
#include "ArvorePosOrdemIterador.h"

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
    if ( perc != nullptr ) {
        Arv* p = perc;
        while( p->esq != nullptr && p->dir != nullptr ) {
            Arv* ant = p;
            while( p != nullptr ) {
                ArvoreIterador::pushNaPilha( p );
                ant = p;
                p = p->esq;
            }
            p = ant;
            if ( p->dir != nullptr )
                p = p->dir;
        }
    }
}
