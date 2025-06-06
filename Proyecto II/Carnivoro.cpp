#include "Carnivoro.h"

#include "Carnivoro.h"

CrituraCarnivora::CrituraCarnivora(string cate, string nombre, int age, int x, int y) :Criatura(nombre, 50, age, x, y) {
	categoria = cate;
}

void CrituraCarnivora::movimiento()
{
	static bool semilla = false;
	if (!semilla) {
		srand(time(nullptr));
		semilla = true;
	}
	int movimientox = (rand() % 2) + 1;
	int movimientoy = (rand() % 2) + 1;
	if (rand() % 2 == 0) {
		movimientox = -movimientox;
	}
	if (rand() % 2 == 0) {
		movimientoy = -movimientoy;
	}
	setposicion(x + movimientox, y + movimientoy);
}

void CrituraCarnivora::buscaralimento()
{
}

Criatura* CrituraCarnivora::reproducirse()
{
	energia -= 4;
	return new CrituraCarnivora(categoria, Nombre, energia, x, y);
}

string CrituraCarnivora::tipo()
{
	return categoria;
}

void CrituraCarnivora::envejecer()
{
	energia -= 2;
	edad + 9;
}

string CrituraCarnivora::Tostring()
{
	stringstream s;
	s << "Mostrando informacion de la criatura " << endl;
	s << "Categoria " << categoria << endl;
	s << "Nombre " << Nombre << endl;
	s << "Edad " << edad << endl;
	s << "Energia " << energia << endl;
	return s.str();
}
