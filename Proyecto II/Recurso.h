#ifndef RECURSO_H
#define RECURSO_H

#include "Entidad.h"
#include <string>
using namespace std;
class Recurso : public Entidad {
public:
    Recurso(int x, int y);
    virtual char obtenerSimbolo() const = 0;
    virtual string tipo() const = 0;
    virtual int energiaConsumible() const = 0;
    virtual ~Recurso() {}
};


class ComidaCarnivora : public Recurso {
public:
    ComidaCarnivora(int x, int y);
    char obtenerSimbolo() const override;
    string tipo() const override;
    int energiaConsumible() const override;
};

class ComidaHervivoro : public Recurso {
public:
    ComidaHervivoro(int x, int y);
    char obtenerSimbolo() const override;
    string tipo() const override;
    int energiaConsumible() const override;
};

class ComidaOmnivoro : public Recurso {
public:
    ComidaOmnivoro(int x, int y);
    char obtenerSimbolo() const override;
    string tipo() const override;
    int energiaConsumible() const override;
};
#endif 
