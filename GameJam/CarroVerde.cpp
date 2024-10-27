#include "CarroVerde.h"

CarroVerde::CarroVerde(int x, int y) : CarroPadre(x, y, "modelosCarro/carroVerde.png")  
{
	int r, r2; 
	r = GenerarNumeroRandom(); 
	r2 = GenerarNumeroRandom(); 
	dx = r;  
	dy = r2; 
	tipo = 2;
}

void CarroVerde::MoverCarrera(Graphics^ canvas)
{
	x += dx;   
}

void CarroVerde::MoverDiagonal(Graphics^ canvas)
{
	x += dx; 
	y += dy; 

	if (x < 0 || x + ancho > canvas->VisibleClipBounds.Width) 
	{
		dx = -dx; 
	}
	if (y < 0 || y + alto > canvas->VisibleClipBounds.Height) 
	{
		dy = -dy;
	}
}

int  CarroVerde::GenerarNumeroRandom()
{
	Random r;
	int numero;
	numero = r.Next(6, 21);
	return numero;
}

int CarroVerde::getTipo()
{
	return tipo;  
}
