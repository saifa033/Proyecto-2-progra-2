#pragma once
using namespace std;
#include "Criatura.h"
#include <iostream>
#include <sstream>
#include <cstdlib>  
#include <ctime> 
class Criaturaomnivora :public Criatura {
private:
	string categoria;
public:
	Criaturaomnivora(string cate, string nombre, int age, int x, int y);
	void movimiento() override;
	void  buscaralimento() override;
	Criatura* reproducirse()override;
	string tipo()override;
	void envejecer() override;
	string Tostring();


};
