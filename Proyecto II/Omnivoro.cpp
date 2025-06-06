#include "Omnivoro.h"

Criaturaomnivora::Criaturaomnivora(string cate, string nombre, int age, int x, int y) :Criatura(nombre, 30, age, x, y) {
}

void Criaturaomnivora::movimiento()
{
	static bool semilla = false;
	if (!semilla) {
		srand(time(nullptr));
		semilla = true;
	}
	int movimientox = (rand() % 2) + 3;
	int movimientoy = (rand() % 2) + 3;
	if (rand() % 2 == 0) {
		movimientox = -movimientox;
	}
	if (rand() % 2 == 0) {
		movimientoy = -movimientoy;
	}
	setposicion(x + movimientox, y + movimientoy);
}

void Criaturaomnivora::buscaralimento()
{

}

Criatura* Criaturaomnivora::reproducirse()
{
	energia -= 1;
	return new Criaturaomnivora(categoria, Nombre, energia, x, y);
}

string Criaturaomnivora::tipo()
{
	return categoria;
}

void Criaturaomnivora::envejecer()
{
	energia -= 1;
	edad + 10;
}

string Criaturaomnivora::Tostring()
{
	stringstream s;
	s << "Mostrando informacion de la criatura " << endl;
	s << "Categoria " << categoria << endl;
	s << "Nombre " << Nombre << endl;
	s << "Edad " << edad << endl;
	s << "Energia " << energia << endl;
	return s.str();
}