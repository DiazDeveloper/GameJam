#include "CarroAzul.h"

CarroAzul::CarroAzul(int x, int y) : CarroPadre(x, y, "modelosCarro/carroAzul.png")   
{
	int r, r2; 
	r = GenerarNumeroRandom();
	r2 = GenerarNumeroRandom(); 
	dx = r; 
	dy = r2;   
	tipo = 3;
}

void CarroAzul::MoverCarrera(Graphics^ canvas)
{
	x += dx; 
}

void CarroAzul::MoverDiagonal(Graphics^ canvas)
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

int  CarroAzul::GenerarNumeroRandom() 
{
	Random r;
	int numero;
	numero = r.Next(6, 21); 
	return numero;
}

int CarroAzul::getTipo()
{
	return tipo;   
}

