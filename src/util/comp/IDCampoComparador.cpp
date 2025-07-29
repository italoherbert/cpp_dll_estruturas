
#include "IDCampoComparador.h"
#include "../IDObjeto.h"

IDCampoComparador::IDCampoComparador( int id ) {
	this->id = id;
}

int IDCampoComparador::compara( Objeto* obj ) {
	if ( id < ((IDObjeto*)obj)->getId() ) {
		return -1;
	} else if ( id > ((IDObjeto*)obj)->getId() ) {
		return 1;
	} else {
		return 0;
	}

}
