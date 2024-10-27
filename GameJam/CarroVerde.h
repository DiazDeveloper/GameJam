#pragma once
#include "CarroPadre.h"
class CarroVerde : public CarroPadre
{
public:

	CarroVerde(int x, int y); 
	void MoverCarrera(Graphics^ canvas);
	void MoverDiagonal(Graphics^ canvas);
	int GenerarNumeroRandom();
	int getTipo();
};

