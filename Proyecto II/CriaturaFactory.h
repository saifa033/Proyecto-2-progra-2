#ifndef CRIATURA_FACTORY_H
#define CRIATURA_FACTORY_H

#include "Criatura.h"
#include <memory>

class CriaturaFactory {
public:
    // Crea una criatura aleatoria en la posición (x, y)
    static unique_ptr<Criatura> crearCriaturaAleatoria(int x, int y);
    unique_ptr<Criatura> crearcriaturaDios(int x, int y, int edad, int energia, string nombre, char tipo);
};

#endif // CRIATURA_FACTORY_H
