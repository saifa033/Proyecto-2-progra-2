#include "Carnivoros.h"

CrituraCarnivora::CrituraCarnivora( string nombre, int age, int x, int y):Criatura(nombre, 50, age, x, y) {
}

CrituraCarnivora::CrituraCarnivora(string nombre, int age, int x, int y, int energy):Criatura(nombre, energy, age, x, y)
{

}
void CrituraCarnivora::buscaralimento()
{
}

Criatura* CrituraCarnivora::reproducirse()
{
	energia -= 4;
	return new CrituraCarnivora(Nombre, energia, x, y);
}

char CrituraCarnivora::tipo()
{
	return 'C';
}

void CrituraCarnivora::envejecer()
{
	energia -= 2;
	edad += 9;
}

string CrituraCarnivora::Tostring()
{
	stringstream s;
	s << "Mostrando informacion de la criatura " << endl;
	s << "Categoria " << tipo() << endl;
	s << "Nombre " << Nombre << endl;
	s << "Edad " << edad << endl;
	s << "Energia " << energia << endl;
	return s.str();
}

char CrituraCarnivora::obtenerSimbolo() const{return 'C';}

bool CrituraCarnivora::puedeConsumir(const Recurso* recurso) {
	if (recurso->obtenerSimbolo() == 'C') {
		setposicion(recurso->getX(), recurso->getY());
		energia += recurso->energiaConsumible();
		return true;
	}
	return false;
}



