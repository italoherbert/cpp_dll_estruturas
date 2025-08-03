
#include "Arvore.h"
#include "it/ArvoreOrdemCentralIterador.h"
#include "it/InversoArvoreOrdemCentralIterador.h"

Arvore::Arvore( ObjComparador* objComparador ) {
	this->raiz = nullptr;
	this->objComparador = objComparador;
	this->tam = 0;
}

Arvore::~Arvore() {
    deletaTodos( false );
}

void Arvore::insere( Objeto* dados ) {
	insereEmArvore( &raiz, nullptr, dados );
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

Iterador* Arvore::it() {
    return new ArvoreOrdemCentralIterador( raiz );
}

Iterador* Arvore::inversoIt() {
    return new InversoArvoreOrdemCentralIterador( raiz );
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

int Arvore::getTamanho() {
    return tam;
}

int Arvore::tamanho() {
    return tamanhoDaArvore( raiz );
}

void Arvore::insereEmArvore( Arv** arv, Arv* pai, Objeto* dados ) {
	if ( *arv == nullptr ) {
		*arv = new Arv;
		(*arv)->dados = dados;
		(*arv)->pai = pai;
		(*arv)->esq = nullptr;
		(*arv)->dir = nullptr;

		this->tam++;
	} else if ( objComparador->compara( dados, (*arv)->dados ) == -1 ) {
		insereEmArvore( &((*arv)->esq), *arv, dados );
	} else {
		insereEmArvore( &((*arv)->dir), *arv, dados );
	}

}

void Arvore::percorreArvorePreOrdem( Arv* arv, PercIT* perc ) {
	if ( arv != nullptr ) {
		perc->processa( arv->dados );
		percorreArvorePreOrdem( arv->esq, perc );
		percorreArvorePreOrdem( arv->dir, perc );
	}
}

void Arvore::percorreArvoreOrdemCentral( Arv* arv, PercIT* perc ) {
	if ( arv != nullptr ) {
		percorreArvoreOrdemCentral( arv->esq, perc );
		perc->processa( arv->dados );
		percorreArvoreOrdemCentral( arv->dir, perc );
	}
}

void Arvore::percorreArvorePosOrdem( Arv* arv, PercIT* perc ) {
	if ( arv != nullptr ) {
		percorreArvorePosOrdem( arv->esq, perc );
		percorreArvorePosOrdem( arv->dir, perc );
		perc->processa( arv->dados );
	}
}

Objeto* Arvore::buscaEmArvore( Arv* arv, CampoComparador* comparador ) {
	if ( arv == nullptr )
		return nullptr;

	if ( comparador->compara( arv->dados ) == 0 ) {
		return arv->dados;
	} else if ( comparador->compara( arv->dados ) == -1 ) {
		return buscaEmArvore( arv->esq, comparador );
	} else {
		return buscaEmArvore( arv->dir, comparador );
	}
}

bool Arvore::alteraEmArvore( Arv* arv, CampoComparador* comparador, Objeto* dados ) {
	if ( arv == nullptr )
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
	if ( *arv == nullptr )
		return nullptr;

	if ( comparador->compara( (*arv)->dados ) == 0 ) {
		Arv* aux = *arv;
		if ( (*arv)->esq == nullptr && (*arv)->dir == nullptr ) {
			*arv = nullptr;
		} else if ( (*arv)->esq == nullptr ) {
		    (*arv)->dir->pai = (*arv)->pai;
			*arv = (*arv)->dir;
		} else if ( (*arv)->dir == nullptr ) {
		    (*arv)->esq->pai = (*arv)->pai;
			*arv = (*arv)->esq;
		} else {
			Arv* perc = (*arv)->dir;
			while( perc->esq != nullptr )
				perc = perc->esq;
			perc->esq = (*arv)->esq;
			(*arv)->esq->pai = perc;
			(*arv)->dir->pai = (*arv)->pai;
			*arv = (*arv)->dir;

		}
		Objeto* dados = aux->dados;
		delete aux;

		this->tam--;

		return dados;
	} else if ( comparador->compara( (*arv)->dados ) == -1 ) {
		return deletaEmArvore( &(*arv)->esq, comparador );
	} else {
		return deletaEmArvore( &(*arv)->dir, comparador );
	}
}

void Arvore::deletaTodosEmArvore( Arv** arv, bool deletarObjetos ) {
    if ( *arv != nullptr ) {
        deletaTodosEmArvore( &(*arv)->esq, deletarObjetos );
        deletaTodosEmArvore( &(*arv)->dir, deletarObjetos );
        if ( deletarObjetos )
            delete (*arv)->dados;
        delete *arv;
        *arv = nullptr;
    }
    this->tam = 0;
}

int Arvore::tamanhoDaArvore( Arv* arv ) {
    if ( arv == nullptr )
        return 0;
    return tamanhoDaArvore( arv->esq ) + tamanhoDaArvore( arv->dir ) + 1;
}
