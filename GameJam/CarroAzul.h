#pragma once
#include "CarroPadre.h"
class CarroAzul : public CarroPadre
{
public:

	CarroAzul(int x, int y);  
	void MoverCarrera(Graphics^ canvas);
	void MoverDiagonal(Graphics^ canvas);
	int GenerarNumeroRandom(); 

};

