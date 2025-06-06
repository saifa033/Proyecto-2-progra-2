#include "Omnivoros.h"

Criaturaomnivora::Criaturaomnivora( string nombre, int age, int x, int y) :Criatura(nombre, 30, age, x, y) {
}

Criaturaomnivora::Criaturaomnivora(string nombre, int age, int x, int y, int energia) :Criatura(nombre, energia, age, x, y)
{
}



void Criaturaomnivora::buscaralimento()
{

}

Criatura* Criaturaomnivora::reproducirse()
{
	energia -= 1;
	return new Criaturaomnivora( Nombre, energia, x, y);
}

char Criaturaomnivora::tipo()
{
	return'O';
}

void Criaturaomnivora::envejecer()
{
	energia -= 1;
	edad += 10;
}

string Criaturaomnivora::Tostring()
{
	stringstream s;
	s << "Mostrando informacion de la criatura " << endl;
	s << "Categoria " <<tipo() << endl;
	s << "Nombre " << Nombre << endl;
	s << "Edad " << edad << endl;
	s << "Energia " << energia << endl;
	return s.str();
}

char Criaturaomnivora::obtenerSimbolo() const { return 'O'; }

bool Criaturaomnivora::puedeConsumir(const Recurso* recurso)
{
	return false;
}

