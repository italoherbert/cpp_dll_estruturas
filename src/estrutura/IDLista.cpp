
#include "IDLista.h"
#include "comp/IDCampoComparador.h"

IDLista::IDLista() : Lista() {

}

IDObjeto* IDLista::busca( int id ) {
	IDCampoComparador* comp = new IDCampoComparador( id );
	return (IDObjeto*)Lista::busca( comp );
}

bool IDLista::altera( IDObjeto* obj ) {
	int id = obj->getId();
	IDCampoComparador* comp = new IDCampoComparador( id );
	return Lista::altera( comp, obj );
}

IDObjeto* IDLista::deleta( int id ) {
	IDCampoComparador* comp = new IDCampoComparador( id );
	return (IDObjeto*)Lista::deleta( comp );
}

