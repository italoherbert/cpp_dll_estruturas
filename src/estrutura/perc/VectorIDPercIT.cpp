
#include "VectorIDPercIT.h"
#include "../IDObjeto.h"

void VectorIDPercIT::processa( Objeto* obj ) {
    vetor.push_back( ((IDObjeto*)obj)->getId() );
}

vector<int> VectorIDPercIT::getVector() {
    return vetor;
}
