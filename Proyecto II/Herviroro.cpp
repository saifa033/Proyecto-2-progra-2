#include "Herviroro.h"


CrituraHervivora::CrituraHervivora( string nombre, int age, int x, int y) :Criatura(nombre, 80, age, x, y)
{
}

CrituraHervivora::CrituraHervivora(string nombre, int age, int x, int y, int energia):Criatura(nombre, energia, age, x, y)
{

}



void CrituraHervivora::buscaralimento()
{

}

Criatura* CrituraHervivora::reproducirse()
{
	energia -= 8;
	return new CrituraHervivora( Nombre, energia, x, y);
}

char CrituraHervivora::tipo()
{
	return 'H';
}

void CrituraHervivora::envejecer()
{
	energia -= 6;
	edad += 6;
}

string CrituraHervivora::Tostring()
{
	stringstream s;
	s << "Mostrando informacion de la criatura " << endl;
	s << "Categoria " << tipo() << endl;
	s << "Nombre " << Nombre << endl;
	s << "Edad " << edad << endl;
	s << "Energia " << energia << endl;
	return s.str();
}


char CrituraHervivora::obtenerSimbolo() const { return 'H'; }

bool CrituraHervivora::puedeConsumir(const Recurso* recurso)
{
	return false;
}



