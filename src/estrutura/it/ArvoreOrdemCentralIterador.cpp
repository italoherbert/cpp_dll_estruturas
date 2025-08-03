
#include "ArvoreOrdemCentralIterador.h"

ArvoreOrdemCentralIterador::ArvoreOrdemCentralIterador( Arv* raiz ) {
    perc = menorEsq( raiz );
    vemDeCima = true;
    vaiParaBaixo = true;
}

bool ArvoreOrdemCentralIterador::temProx() {
    return perc != nullptr;
}

Objeto* ArvoreOrdemCentralIterador::prox() {
    Arv* aux = perc;
    if ( vaiParaBaixo ) {
        if ( perc->esq == nullptr && perc->dir == nullptr ) {
            if ( perc == perc->pai->esq ) {
                perc = perc->pai;
                vaiParaBaixo = false;
                vemDeCima = true;
            } else {
                perc = paiNaoIterado( perc );
                vaiParaBaixo = false;
                vemDeCima = true;
            }
        } else {
            perc = menorEsq( perc->dir );
        }
    } else {
        if ( vemDeCima ) {
            if ( perc->dir == nullptr ) {
                perc = paiNaoIterado( perc );
                vaiParaBaixo = true;
                vemDeCima = false;
            } else {
                perc = menorEsq( perc->dir );
            }
        } else {
            perc = paiNaoIterado( perc );
            vaiParaBaixo = true;
            vemDeCima = false;
        }
    }
    aux->iterado = true;
    return aux->dados;
}

Arv* ArvoreOrdemCentralIterador::paiNaoIterado( Arv* perc ) {
    if ( perc == nullptr )
        return nullptr;

    Arv* p = perc->pai;
    bool iterado = ( p != nullptr ? p->iterado : false );
    while( p != nullptr && iterado ) {
        p = p->pai;
        iterado = ( p != nullptr ? p->iterado : false );
    }

    return p;
}

Arv* ArvoreOrdemCentralIterador::menorEsq( Arv* perc ) {
    if ( perc == nullptr )
        return nullptr;

    Arv* p = perc;
    p->iterado = false;
    while( p->esq != nullptr ) {
        p = p->esq;
        p->iterado = false;
    }
    return p;
}





