
#include "IDArvore.h"
#include "comp/IDCampoComparador.h"

IDArvore::IDArvore() : Arvore( new IDObjComparador() ) {

}

void IDArvore::insere( IDObjeto* obj ) {
	Arvore::insere( obj );
}

IDObjeto* IDArvore::busca( int id ) {
	IDCampoComparador* comp = new IDCampoComparador( id );
	return (IDObjeto*)Arvore::busca( comp );
}

bool IDArvore::altera( IDObjeto* obj ) {
	int id = obj->getId();
	IDCampoComparador* comp = new IDCampoComparador( id );
	return Arvore::altera( comp, obj );
}

IDObjeto* IDArvore::deleta( int id ) {
	IDCampoComparador* comp = new IDCampoComparador( id );
	return (IDObjeto*)Arvore::deleta( comp );
}
