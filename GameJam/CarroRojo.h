#pragma once
#include "CarroPadre.h"
class CarroRojo :  public CarroPadre
{
public:

	CarroRojo(int x, int y); 
	void MoverCarrera(Graphics^ canvas); 
	void MoverDiagonal(Graphics^ canvas);
	int GenerarNumeroRandom();
	int getTipo(); 
};

