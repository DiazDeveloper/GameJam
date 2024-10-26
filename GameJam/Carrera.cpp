#include "Carrera.h"

Carrera::Carrera()
{
	carros.push_back(new CarroRojo(15,90));
	carros.push_back(new CarroAzul(15,280));
	carros.push_back(new CarroVerde(15,470));
}

Carrera::~Carrera()
{
	for (int i = 0; i < carros.size(); i++)
	{
		delete carros[i];
	}
	carros.clear();
}

void Carrera::moverCarrera(Graphics^ canvas)  
{
	for (int i = 0; i < carros.size(); i++)
	{
		carros[i]->MoverCarrera(canvas);   
	}
}

void Carrera::moverDiagonal(Graphics^ canvas)
{
	for (int i = 0; i < carros.size(); i++)
	{
		carros[i]->MoverDiagonal(canvas); 
	}
}

void Carrera::reset()
{
	for (int i = 0; i < carros.size(); i++)
	{
		carros[i]->reset(); 
	}
}

void Carrera::mostrar(Graphics^ canvas) 
{
    canvas->Clear(Color::White);
	for (int i = 0; i < carros.size(); i++)
	{
		carros[i]->mostrar(canvas);
	}
}

void Carrera::AcabarCarrera(Graphics^ canvas)  
{
	Rectangle rect = Rectangle(meta, 0, 20, canvas->VisibleClipBounds.Height);
	canvas->FillRectangle(Brushes::Black, rect); 
	for (int i = 0; i < carros.size(); i++)
	{
		if (rect.IntersectsWith(carros[i]->getRectangle()))
		{
			reset();
		}
	}
}

void Carrera::GenerarCarro(int numero)
{
	if (carros.size() <= 20)
	{
		if (numero == 1)
		{
			Random r, r2; 
			int posX = r.Next(0, 850);
			int posY = r2.Next(0, 550);
			carros.push_back(new CarroRojo(posX, posY));  
		}

		else if (numero == 2)
		{
			Random r, r2;
			int posX = r.Next(0, 850);
			int posY = r2.Next(0, 550);
			carros.push_back(new CarroVerde(posX, posY));  
		}

		else if (numero == 3)
		{
			Random r, r2;
			int posX = r.Next(0, 850);
			int posY = r2.Next(0, 550); 
			carros.push_back(new CarroAzul(posX, posY));   
		}
	}
}

int  Carrera::GenerarNumeroRandom()
{
	Random r; 
	int numero; 
	numero = r.Next(1, 4); 
	return numero;
}


