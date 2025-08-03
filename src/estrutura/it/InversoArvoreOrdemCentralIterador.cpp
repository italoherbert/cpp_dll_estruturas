
#include "InversoArvoreOrdemCentralIterador.h"

InversoArvoreOrdemCentralIterador::InversoArvoreOrdemCentralIterador( Arv* raiz ) {
    perc = menorDir( raiz );
    vaiParaBaixo = true;
    vemDaDireita = false;
}

bool InversoArvoreOrdemCentralIterador::temProx() {
    return perc != nullptr;
}

Objeto* InversoArvoreOrdemCentralIterador::prox() {
    if ( perc == nullptr )
        return nullptr;

    Arv* aux = perc;
    if ( vaiParaBaixo ) {
        if ( perc->esq == nullptr && perc->dir == nullptr ) {
            if ( perc == perc->pai->dir ) {
                perc = perc->pai;
                vaiParaBaixo = false;
                vemDaDireita = true;
            } else {
                perc = paiNaoIterado( perc );
                vaiParaBaixo = false;
            }
        } else {
            if ( perc->esq == nullptr ) {
                perc = paiNaoIterado( perc );
                vaiParaBaixo = false;
            } else {
                perc = menorDir( perc->esq );
            }
        }
    } else {
        if ( vemDaDireita ) {
            if ( perc->esq == nullptr ) {
                perc = paiNaoIterado( perc );
                vaiParaBaixo = true;
            } else {
                perc = menorDir( perc->esq );
            }
        } else {
            perc = paiNaoIterado( perc );
            vaiParaBaixo = true;
        }
    }
    aux->iterado = true;
    return aux->dados;
}

Arv* InversoArvoreOrdemCentralIterador::paiNaoIterado( Arv* perc ) {
    if ( perc == nullptr )
        return nullptr;

    if ( perc->pai != nullptr )
        vemDaDireita = ( perc == perc->pai->dir ? true : false );

    Arv* p = perc->pai;
    bool iterado = ( p != nullptr ? p->iterado : false );
    while( p != nullptr && iterado ) {
        if ( p->pai != nullptr )
            vemDaDireita = ( p == p->pai->dir ? true : false );

        p = p->pai;
        iterado = ( p != nullptr ? p->iterado : false );
    }

    return p;
}

Arv* InversoArvoreOrdemCentralIterador::menorDir( Arv* perc ) {
    if ( perc == nullptr )
        return nullptr;

    Arv* p = perc;
    p->iterado = false;
    while( p->dir != nullptr ) {
        p = p->dir;
        p->iterado = false;
    }
    return p;
}





