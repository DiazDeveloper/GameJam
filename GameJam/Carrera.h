#pragma once
#include "CarroPadre.h"
#include "CarroRojo.h"
#include "CarroAzul.h"
#include "CarroVerde.h"
#include <vector>
using namespace std;

class Carrera
{
private:

	vector<CarroPadre*> carros;
	int round = 1; 
	int meta = 1180;

public:
	Carrera();
	~Carrera();
	void moverCarrera(Graphics^ canvas);
	void moverDiagonal(Graphics^ canvas); 
	void reset();
	void mostrar(Graphics^ canvas);
	void AcabarCarrera(Graphics^ canvas);
	void GenerarCarro(int numero);
	int GenerarNumeroRandom(); 
	void detectarColision1();
	void detectarColision2();
	void detectarColision3();

};

