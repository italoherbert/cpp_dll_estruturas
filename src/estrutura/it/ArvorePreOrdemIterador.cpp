
#include "ArvorePreOrdemIterador.h"

#include <cstdlib>

ArvorePreOrdemIterador::ArvorePreOrdemIterador( Arv* raiz ) : ArvoreIterador() {
    if ( raiz != NULL )
        ArvoreIterador::pushNaPilha( raiz );
}

Objeto* ArvorePreOrdemIterador::prox() {
    Arv* perc = ArvoreIterador::popNaPilha();

    if ( perc->esq == NULL ) {
        ArvoreIterador::pushNaPilha( perc->dir );
    } else {
        ArvoreIterador::pushNaPilha( perc );
        ArvoreIterador::pushNaPilha( perc->esq );
    }

    return perc->dados;
}





