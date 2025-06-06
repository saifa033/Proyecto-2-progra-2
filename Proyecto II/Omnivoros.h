#pragma once
#pragma once
using namespace std;
#include "Criatura.h"
#include <iostream>
#include <sstream>
#include <cstdlib>  
#include <ctime> 
class Criaturaomnivora :public Criatura {
public:
	Criaturaomnivora( string nombre, int age, int x, int y);
	Criaturaomnivora(string nombre, int age, int x, int y, int energia);
	void  buscaralimento() override;
	Criatura* reproducirse()override;
	char tipo()override;
	void envejecer() override;
	string Tostring();

	char obtenerSimbolo() const override;
	bool puedeConsumir(const Recurso* recurso)override;
};
