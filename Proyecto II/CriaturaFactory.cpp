#include "CriaturaFactory.h"
#include <cstdlib> // Para rand()
#include "Carnivoros.h"
#include "Omnivoros.h"
#include "Herviroro.h"

unique_ptr<Criatura> CriaturaFactory::crearCriaturaAleatoria(int x, int y) {
	static bool bandera = false;
	if (!bandera) {
		srand(static_cast<unsigned int>(time(0))); // generacion a tiempo real de numeros aleatorios 
		bandera = true;
	}
	int tipo = rand() % 3; // aqui se crea carnivoro , hervivoro y omnivooro;
	string nombre = "Criatura_" + to_string(rand() % 100);
	int edad = rand() % 10; 
	switch (tipo)
	{
	case 0:
		return std::make_unique<CrituraCarnivora>(nombre, edad, x, y);
	case 1:
		return std::make_unique<CrituraHervivora>(nombre, edad, x, y);
	case 2:
		return std::make_unique<Criaturaomnivora>(nombre, edad, x, y);
	default:
		return nullptr;
	}
}

unique_ptr<Criatura> CriaturaFactory::crearcriaturaDios(int x, int y, int edad, int energia, string nombre, char tipo)
{
	if (tipo == 'C') {
		return make_unique<CrituraCarnivora>(nombre, edad, x, y, energia);
	}
	if (tipo == 'H') {
		return make_unique<CrituraHervivora>(nombre, edad, x, y, energia);
	}
	if (tipo == 'O') {
		return make_unique<Criaturaomnivora>(nombre, edad, x, y, energia);
	}
	return nullptr;
}


