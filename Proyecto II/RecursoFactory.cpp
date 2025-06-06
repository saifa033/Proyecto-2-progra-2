#include "RecursoFactory.h"
#include <memory>
#include <cstdlib>
#include <ctime>
unique_ptr<Recurso> RecursoFactory::crearRecursoAleatorio( int x, int y)
{
    static bool bandera = false;
    if (!bandera) {
        srand(static_cast<unsigned int>(time(0)));
        bandera = true;
    }

    int tipoRandom = rand() % 4; 

    switch (tipoRandom) {
    case 1: return make_unique<ComidaCarnivora>(x, y);
    case 2: return make_unique<ComidaHervivoro>(x, y);
    case 3: return make_unique<ComidaOmnivoro>(x, y);
    default: return nullptr;
    }
}

unique_ptr<Recurso> RecursoFactory::crearRecursoDios(int x, int y, char tipo)
{
    if (tipo == 'C') {
        return make_unique<ComidaCarnivora>(x, y);
    }
    if (tipo == 'H') {
        return make_unique<ComidaHervivoro>(x, y);
    }
    if (tipo == 'O')
    {
        return make_unique<ComidaOmnivoro>(x, y);
    }
}
