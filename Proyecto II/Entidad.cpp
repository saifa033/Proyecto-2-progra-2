#include "Entidad.h"

Entidad::Entidad(int x, int y) : x(x), y(y) {}

int Entidad::getX() const { return x; }
int Entidad::getY() const { return y; }

void Entidad::setPosicion(int nuevaX, int nuevaY) {
    x = nuevaX;
    y = nuevaY;
}
