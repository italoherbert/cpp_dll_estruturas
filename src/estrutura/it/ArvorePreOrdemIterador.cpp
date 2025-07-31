
#include "ArvorePreOrdemIterador.h"

ArvorePreOrdemIterador::ArvorePreOrdemIterador( Arv* raiz ) : ArvoreIterador() {
    if ( raiz != nullptr )
        ArvoreIterador::pushNaPilha( raiz );
}

Objeto* ArvorePreOrdemIterador::prox() {
    Arv* perc = ArvoreIterador::popNaPilha();

    if ( perc->esq == nullptr ) {
        ArvoreIterador::pushNaPilha( perc->dir );
    } else {
        ArvoreIterador::pushNaPilha( perc );
        ArvoreIterador::pushNaPilha( perc->esq );
    }

    return perc->dados;
}





