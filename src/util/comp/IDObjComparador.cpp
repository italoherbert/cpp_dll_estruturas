
#include "IDObjComparador.h"
#include "../IDObjeto.h"

int IDObjComparador::compara( Objeto* o1, Objeto* o2 ) {
	if ( ((IDObjeto*)o1)->getId() > ((IDObjeto*)o2)->getId() ) {
		return 1;
	} else if ( ((IDObjeto*)o1)->getId() < ((IDObjeto*)o2)->getId() ) {
		return -1;
	} else {
		return 0;
	}
}
