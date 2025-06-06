#ifndef RECURSO_FACTORY_H
#define RECURSO_FACTORY_H

#include <memory>
#include <cstdlib>
#include "Recurso.h"

class RecursoFactory {
public:
    static unique_ptr<Recurso>crearRecursoAleatorio( int x, int y);
    static unique_ptr<Recurso>crearRecursoDios( int x, int y, char tipo);
};

#endif // RECURSO_FACTORY_H
