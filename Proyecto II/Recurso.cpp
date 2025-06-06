#include "Recurso.h"

// Clase base Recurso
Recurso::Recurso(int x, int y) : Entidad(x, y) {}




ComidaCarnivora::ComidaCarnivora(int x, int y):Recurso(x,y){
}
char ComidaCarnivora::obtenerSimbolo() const
{
	return 'C';
}
string ComidaCarnivora::tipo() const
{
	return "Comida carnivora";
}
int ComidaCarnivora::energiaConsumible() const
{
	return 5;
}

ComidaHervivoro::ComidaHervivoro(int x, int y):Recurso(x,y)
{
}

char ComidaHervivoro::obtenerSimbolo() const
{
	return 'H';
}

string ComidaHervivoro::tipo() const
{
	return "Comida Carnivora";
}

int ComidaHervivoro::energiaConsumible() const
{
	return 4;
}

ComidaOmnivoro::ComidaOmnivoro(int x, int y):Recurso(x,y)
{
}

char ComidaOmnivoro::obtenerSimbolo() const
{
	return 'O';
}

string ComidaOmnivoro::tipo() const
{
	return "Comida Omnivora";
}

int ComidaOmnivoro::energiaConsumible() const
{
	return 3;
}
