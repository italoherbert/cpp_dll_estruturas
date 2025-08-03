g++.exe -Wall -g -DBUILDING_DLL  -c C:\Users\italo\workspace-cpp\dlls\Estruturas\src\estrutura\Arvore.cpp -o obj\Debug\src\estrutura\Arvore.o
g++.exe -Wall -g -DBUILDING_DLL  -c C:\Users\italo\workspace-cpp\dlls\Estruturas\src\estrutura\comp\IDCampoComparador.cpp -o obj\Debug\src\estrutura\comp\IDCampoComparador.o
g++.exe -Wall -g -DBUILDING_DLL  -c C:\Users\italo\workspace-cpp\dlls\Estruturas\src\estrutura\comp\IDObjComparador.cpp -o obj\Debug\src\estrutura\comp\IDObjComparador.o
g++.exe -Wall -g -DBUILDING_DLL  -c C:\Users\italo\workspace-cpp\dlls\Estruturas\src\estrutura\IDArvore.cpp -o obj\Debug\src\estrutura\IDArvore.o
g++.exe -Wall -g -DBUILDING_DLL  -c C:\Users\italo\workspace-cpp\dlls\Estruturas\src\estrutura\IDLista.cpp -o obj\Debug\src\estrutura\IDLista.o
g++.exe -Wall -g -DBUILDING_DLL  -c C:\Users\italo\workspace-cpp\dlls\Estruturas\src\estrutura\IDObjeto.cpp -o obj\Debug\src\estrutura\IDObjeto.o
g++.exe -Wall -g -DBUILDING_DLL  -c C:\Users\italo\workspace-cpp\dlls\Estruturas\src\estrutura\it\ArvoreOrdemCentralIterador.cpp -o obj\Debug\src\estrutura\it\ArvoreOrdemCentralIterador.o
g++.exe -Wall -g -DBUILDING_DLL  -c C:\Users\italo\workspace-cpp\dlls\Estruturas\src\estrutura\it\InversoListaIterador.cpp -o obj\Debug\src\estrutura\it\InversoListaIterador.o
g++.exe -Wall -g -DBUILDING_DLL  -c C:\Users\italo\workspace-cpp\dlls\Estruturas\src\estrutura\it\ListaIterador.cpp -o obj\Debug\src\estrutura\it\ListaIterador.o
g++.exe -Wall -g -DBUILDING_DLL  -c C:\Users\italo\workspace-cpp\dlls\Estruturas\src\estrutura\Lista.cpp -o obj\Debug\src\estrutura\Lista.o
g++.exe -Wall -g -DBUILDING_DLL  -c C:\Users\italo\workspace-cpp\dlls\Estruturas\src\estrutura\perc\IDPercIT.cpp -o obj\Debug\src\estrutura\perc\IDPercIT.o
g++.exe -Wall -g -DBUILDING_DLL  -c C:\Users\italo\workspace-cpp\dlls\Estruturas\src\estrutura\perc\VectorIDPercIT.cpp -o obj\Debug\src\estrutura\perc\VectorIDPercIT.o
g++.exe -shared -Wl,--output-def=bin\Debug\libEstruturas.def -Wl,--out-implib=bin\Debug\libEstruturas.a -Wl,--dll  obj\Debug\src\estrutura\Arvore.o obj\Debug\src\estrutura\comp\IDCampoComparador.o obj\Debug\src\estrutura\comp\IDObjComparador.o obj\Debug\src\estrutura\IDArvore.o obj\Debug\src\estrutura\IDLista.o obj\Debug\src\estrutura\IDObjeto.o obj\Debug\src\estrutura\it\ArvoreOrdemCentralIterador.o obj\Debug\src\estrutura\it\InversoListaIterador.o obj\Debug\src\estrutura\it\ListaIterador.o obj\Debug\src\estrutura\Lista.o obj\Debug\src\estrutura\perc\IDPercIT.o obj\Debug\src\estrutura\perc\VectorIDPercIT.o  -o bin\Debug\Estruturas.dll  -luser32

