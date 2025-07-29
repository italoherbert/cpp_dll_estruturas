
#include "Arvore.h"

#include <cstdlib>

Arvore::Arvore( ObjComparador* objComparador ) {
	this->raiz = NULL;
	this->objComparador = objComparador;
}

Arvore::~Arvore() {
    deletaTodos( false );
}

void Arvore::insere( Objeto* dados ) {
	insereEmArvore( &raiz, dados );
}

void Arvore::percorre( PercIT* perc ) {
    percorreArvoreOrdemCentral( raiz, perc );
}

void Arvore::percorrePreOrdem( PercIT* perc ) {
	percorreArvorePreOrdem( raiz, perc );
}

void Arvore::percorreOrdemCentral( PercIT* perc ) {
	percorreArvoreOrdemCentral( raiz, perc );
}

void Arvore::percorrePosOrdem( PercIT* perc ) {
	percorreArvorePosOrdem( raiz, perc );
}

Objeto* Arvore::busca( CampoComparador* comparador ) {
	return buscaEmArvore( raiz, comparador );
}

bool Arvore::altera( CampoComparador* comparador, Objeto* dados ) {
	return alteraEmArvore( raiz, comparador, dados );
}

Objeto* Arvore::deleta( CampoComparador* comparador ) {
	return deletaEmArvore( &raiz, comparador );
}

void Arvore::deletaTodos( bool deletarObjetos ) {
    deletaTodosEmArvore( &raiz, deletarObjetos );
}

int Arvore::tamanho() {
    return tamanhoDaArvore( raiz );
}

void Arvore::insereEmArvore( Arv** arv, Objeto* dados ) {
	if ( *arv == NULL ) {
		*arv = (Arv*) malloc( sizeof( Arv ) );
		(*arv)->dados = dados;
		(*arv)->esq = NULL;
		(*arv)->dir = NULL;
	} else if ( objComparador->compara( dados, (*arv)->dados ) == -1 ) {
		insereEmArvore( &((*arv)->esq), dados );
	} else {
		insereEmArvore( &((*arv)->dir), dados );
	}

}

void Arvore::percorreArvorePreOrdem( Arv* arv, PercIT* perc ) {
	if ( arv != NULL ) {
		perc->processa( arv->dados );
		percorreArvorePreOrdem( arv->esq, perc );
		percorreArvorePreOrdem( arv->dir, perc );
	}
}

void Arvore::percorreArvoreOrdemCentral( Arv* arv, PercIT* perc ) {
	if ( arv != NULL ) {
		percorreArvoreOrdemCentral( arv->esq, perc );
		perc->processa( arv->dados );
		percorreArvoreOrdemCentral( arv->dir, perc );
	}
}

void Arvore::percorreArvorePosOrdem( Arv* arv, PercIT* perc ) {
	if ( arv != NULL ) {
		percorreArvorePosOrdem( arv->esq, perc );
		percorreArvorePosOrdem( arv->dir, perc );
		perc->processa( arv->dados );
	}
}

Objeto* Arvore::buscaEmArvore( Arv* arv, CampoComparador* comparador ) {
	if ( arv == NULL )
		return NULL;

	if ( comparador->compara( arv->dados ) == 0 ) {
		return arv->dados;
	} else if ( comparador->compara( arv->dados ) == -1 ) {
		return buscaEmArvore( arv->esq, comparador );
	} else {
		return buscaEmArvore( arv->dir, comparador );
	}
}

bool Arvore::alteraEmArvore( Arv* arv, CampoComparador* comparador, Objeto* dados ) {
	if ( arv == NULL )
		return false;

	if ( comparador->compara( arv->dados ) == 0 ) {
		arv->dados = dados;
		return true;
	} else if ( comparador->compara( arv->dados ) == -1 ) {
		return alteraEmArvore( arv->esq, comparador, dados );
	} else {
		return alteraEmArvore( arv->dir, comparador, dados );
	}
}

Objeto* Arvore::deletaEmArvore( Arv** arv, CampoComparador* comparador ) {
	if ( *arv == NULL )
		return NULL;

	if ( comparador->compara( (*arv)->dados ) == 0 ) {
		Arv* aux = *arv;
		if ( (*arv)->esq == NULL && (*arv)->dir == NULL ) {
			*arv = NULL;
		} else if ( (*arv)->esq == NULL ) {
			*arv = (*arv)->dir;
		} else if ( (*arv)->dir == NULL ) {
			*arv = (*arv)->esq;
		} else {
			Arv* perc = (*arv)->dir;
			while( perc->esq != NULL )
				perc = perc->esq;
			perc->esq = (*arv)->esq;
			*arv = (*arv)->dir;
		}
		Objeto* dados = aux->dados;
		delete aux;
		return dados;
	} else if ( comparador->compara( (*arv)->dados ) == -1 ) {
		return deletaEmArvore( &(*arv)->esq, comparador );
	} else {
		return deletaEmArvore( &(*arv)->dir, comparador );
	}
}

void Arvore::deletaTodosEmArvore( Arv** arv, bool deletarObjetos ) {
    if ( *arv != NULL ) {
        deletaTodosEmArvore( &(*arv)->esq, deletarObjetos );
        deletaTodosEmArvore( &(*arv)->dir, deletarObjetos );
        if ( deletarObjetos )
            delete (*arv)->dados;
        delete *arv;
        *arv = NULL;
    }
}

int Arvore::tamanhoDaArvore( Arv* arv ) {
    if ( arv == NULL )
        return 0;
    return tamanhoDaArvore( arv->esq ) + tamanhoDaArvore( arv->dir ) + 1;
}
