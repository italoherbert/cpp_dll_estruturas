
#include "Lista.h"
#include "it/ListaIterador.h"
#include "it/InversoListaIterador.h"

Lista::Lista() {
    descritor = new Descritor();
    descritor->tamanho = 0;
    descritor->prim = nullptr;
    descritor->ult = nullptr;
}

Lista::~Lista() {
    deletaTodos( false );
}

void Lista::insere( Objeto* dados ) {
    insereNoFim( descritor, dados );
}

void Lista::insereNoInicio( Objeto* dados ) {
    insereNoInicio( descritor, dados );
}

void Lista::insereNoFim( Objeto* dados ) {
    insereNoFim( descritor, dados );
}

void Lista::percorre( PercIT* perc ) {
    percorreLista( descritor, perc );
}

void Lista::percorreOrdemInversa( PercIT* perc ) {
    percorreListaOrdemInversa( descritor, perc );
}

Iterador* Lista::it() {
    return new ListaIterador( descritor->prim );
}

Iterador* Lista::inversoIt() {
    return new InversoListaIterador( descritor->ult );
}

Objeto* Lista::busca( CampoComparador* comparador ) {
    return buscaNaLista( descritor, comparador );
}

bool Lista::altera( CampoComparador* comparador, Objeto* obj ) {
    return alteraNaLista( descritor, comparador, obj );
}

Objeto* Lista::deleta( CampoComparador* comparador ) {
    return deletaNaLista( descritor, comparador );
}

void Lista::deletaTodos( bool deletarObjetos ) {
    deletaTodosNaLista( descritor, deletarObjetos );
}

Objeto* Lista::pop() {
    return popEmLista( descritor );
}

int Lista::getTamanho() {
    return descritor->tamanho;
}

int Lista::tamanho() {
    return tamanhoDaLista( descritor );
}

Objeto* Lista::get( int indice ) {
    return getEmLista( descritor, indice );
}

void Lista::insereNoInicio( Descritor* desc, Objeto* dados ) {
    Lst* novo = new Lst();
    novo->dados = dados;

    if ( desc->prim == nullptr ) {
        novo->ant = nullptr;
        novo->prox = nullptr;
        desc->prim = novo;
        desc->ult = novo;
    } else {
        novo->ant = nullptr;
        novo->prox = desc->prim;
        desc->prim->ant = novo;
        desc->prim = novo;
    }

    desc->tamanho++;
}

void Lista::insereNoFim( Descritor* desc, Objeto* dados ) {
    Lst* novo = new Lst();
    novo->dados = dados;

    if ( desc->prim == nullptr ) {
        novo->ant = nullptr;
        novo->prox = nullptr;
        desc->prim = novo;
        desc->ult = novo;
    } else {
        novo->ant = desc->ult;
        novo->prox = nullptr;
        desc->ult->prox = novo;
        desc->ult = novo;
    }

    desc->tamanho++;
}

void Lista::percorreLista( Descritor* desc, PercIT* perc ) {
    Lst* p = desc->prim;
    while( p != nullptr ) {
        perc->processa( p->dados );
        p = p->prox;
    }
}

void Lista::percorreListaOrdemInversa( Descritor* desc, PercIT* perc ) {
    Lst* p = desc->ult;
    while( p != nullptr ) {
        perc->processa( p->dados );
        p = p->ant;
    }
}

Objeto* Lista::buscaNaLista( Descritor* desc, CampoComparador* comparador ) {
    Lst* p = desc->prim;
    while( p != nullptr ) {
        if ( comparador->compara( p->dados ) == 0 )
            return p->dados;
        p = p->prox;
    }
    return nullptr;
}

bool Lista::alteraNaLista( Descritor* desc, CampoComparador* comparador, Objeto* dados ) {
    Lst* p = desc->prim;
    while( p != nullptr ) {
        if ( comparador->compara( p->dados ) == 0 ) {
            p->dados = dados;
            return true;
        }
        p = p->prox;
    }
    return false;
}

Objeto* Lista::deletaNaLista( Descritor* desc, CampoComparador* comparador ) {
    Lst* p = desc->prim;
    Lst* aux = nullptr;
    while( aux == nullptr && p != nullptr ) {
        if ( comparador->compara( p->dados ) == 0 )
            aux = p;
        else p = p->prox;
    }

    if ( aux != nullptr ) {
        if ( aux == desc->prim ) {
            aux->prox->ant = nullptr;
            desc->prim = aux->prox;
        } else if ( aux == desc->ult ) {
            aux->ant->prox = nullptr;
            desc->ult = aux->ant;
        } else {
            aux->ant->prox = aux->prox;
            aux->prox->ant = aux->ant;
        }
        Objeto* dados = aux->dados;
        delete aux;

        desc->tamanho--;
        return dados;
    }
    return nullptr;
}

void Lista::deletaTodosNaLista( Descritor* desc, bool deletarObjetos ) {
    while( desc->prim != nullptr ) {
        Lst* aux = desc->prim;
        desc->prim = desc->prim->prox;
        if ( deletarObjetos )
            delete aux->dados;
        delete aux;
    }
    desc->ult = nullptr;
    desc->tamanho = 0;
}

Objeto* Lista::popEmLista( Descritor* desc ) {
    Lst* aux = desc->prim;
    if ( aux != nullptr ) {
        aux->prox->ant = nullptr;
        desc->prim = aux->prox;

        Objeto* dados = aux->dados;
        delete aux;
        return dados;
    }
    return nullptr;
}

Objeto* Lista::getEmLista( Descritor* desc, int indice ) {
    Lst* p = desc->prim;
    int contador = 0;
    while( p != nullptr ) {
        if ( indice == contador )
            return p->dados;

        contador++;
        p = p->prox;
    }
    return nullptr;
}

int Lista::tamanhoDaLista( Descritor* desc ) {
    Lst* p = desc->prim;
    int contador = 0;
    while( p != nullptr ) {
        contador++;
        p = p->prox;
    }
    return contador;
}
