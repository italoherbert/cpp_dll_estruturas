
#include "IDPercIT.h"
#include "../IDObjeto.h"

#include <iostream>

void IDPercIT::percorre( Objeto* obj ) {
    std::cout << ((IDObjeto*)obj)->getId() << " ";
}
