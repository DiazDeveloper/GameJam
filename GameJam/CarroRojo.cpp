#include "CarroRojo.h"

CarroRojo::CarroRojo(int x, int y) : CarroPadre(x, y, "modelosCarro/carroRojo.png")
{
	int r, r2; 
	r = GenerarNumeroRandom(); 
	r2 = GenerarNumeroRandom(); 
	dx = r; 
	dy = r2;  
}

void CarroRojo::MoverCarrera(Graphics^ canvas)
{
	x += dx;    
}

void CarroRojo::MoverDiagonal(Graphics^ canvas)
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

int  CarroRojo::GenerarNumeroRandom()
{
	Random r;
	int numero;
	numero = r.Next(6, 21);
	return numero;
}
