#pragma once
#include <string.h>
#include <iostream>
using namespace std;
using namespace System;
using namespace System::Drawing;

class CarroPadre
{
protected:
	int x;
	int y;
	int dx, dy;
	int alto, ancho;
	char* imagen;

	void cambiarImagen(char* nombreDelArchivo);
	virtual void dibujarImagen(Graphics^ canvas, Bitmap^ sprite, Rectangle zoom, Rectangle corte);

public:
	CarroPadre(int x, int y, char* imagen);
	virtual void mostrar(Graphics^ canvas);
	void reset(); 
	virtual void MoverCarrera(Graphics^ canvas); 
	virtual void MoverDiagonal(Graphics^ canvas);
	Rectangle getRectangle();
	int getX();
	int getY();
	int getAlto();
	int getAncho();
	bool hayColision(CarroPadre* carropadre);

};

