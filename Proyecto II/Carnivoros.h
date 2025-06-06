#pragma once
using namespace std;
#include "Criatura.h"
#include <iostream>
#include <sstream>
#include <cstdlib>  
#include <ctime> 
class CrituraCarnivora :public Criatura {

public:
	CrituraCarnivora( string nombre, int age, int x, int y);
	CrituraCarnivora(string nombre, int age, int x, int y, int energy);
	void  buscaralimento() override;
	Criatura* reproducirse()override;
	char tipo()override;
	void envejecer() override;
	string Tostring();
	char obtenerSimbolo() const override;
	bool puedeConsumir(const Recurso* recurso)  override;
};


