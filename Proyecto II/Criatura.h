#ifndef CRIATURA_H
#define CRIATURA_H

#include "Entidad.h"
#include <algorithm>
using namespace std;
#include <iostream>
#include "Recurso.h"

// Clase base abstracta
class Criatura : public Entidad {
protected:
	string Nombre;
	int edad, energia;
	int x, y;
public:
	Criatura(string nombre, int energia1, int age, int x1, int y1);
	virtual void movimiento(int dx, int dy, int ancho, int alto);
	virtual void buscaralimento() = 0;
	virtual Criatura* reproducirse() = 0;
	virtual bool vive() { return energia; }
	void setposicion(int x1, int y1) { x = x1, y = y1; };
	virtual char tipo() = 0;
	virtual void envejecer() = 0;
	int getenergia() { return energia; }
	int getX() { return x; }
	int getY() { return y; }
	virtual string Tostring() = 0;
	string getnombre() { return Nombre; }
	int getedad() { return edad;  }

	////////////////////////////////////// codigo josue 

	virtual char obtenerSimbolo() const = 0;
	virtual bool puedeConsumir(const Recurso* recurso)  = 0;
};
#endif
