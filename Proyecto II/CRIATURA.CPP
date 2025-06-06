#include "Criatura.h"

Criatura::Criatura(string nombre, int energia1, int age, int x1, int y1) :Nombre(nombre), edad(age), energia(energia1), x(x1), y(y1) 
{
}

void Criatura::movimiento(int dx, int dy, int ancho, int alto)
{
    int nx = x + dx;
    int ny = y + dy;
    if (nx >= 0 && nx < ancho && ny >= 0 && ny < alto) {
        x = nx;
        y = ny;
    }
}


