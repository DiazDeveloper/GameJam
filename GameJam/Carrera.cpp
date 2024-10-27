#include "Carrera.h"

Carrera::Carrera()
{
	carros.push_back(new CarroRojo(15,90));     //
	carros.push_back(new CarroVerde(15, 470)); //
	carros.push_back(new CarroAzul(15,280));    //
    	  
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
			int posX = r.Next(0, 750);
			int posY = r2.Next(0, 550);
			carros.push_back(new CarroRojo(posX, posY));  
		}

		else if (numero == 2)
		{
			Random r, r2;
			int posX = r.Next(0, 750);
			int posY = r2.Next(0, 550);
			carros.push_back(new CarroVerde(posX, posY));   
		}

		else if (numero == 3)
		{
			Random r, r2;
			int posX = r.Next(0, 750);
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

void Carrera::detectarColision1()
{
	for (int i = 0; i < carros.size(); i++)
	{
		if (carros[i]->getTipo() == 3)  //carro azul
		{
			for (int j = 0; j < carros.size(); j++)
			{
				if (i != j && carros[j]->getTipo() == 2) 
				{
					if (carros[i]->getRectangle().IntersectsWith(carros[j]->getRectangle())) //choque con verde
					{
						delete carros[j]; // elmina verde
						carros.erase(carros.begin() + j); 
						j--;
					}
				}
			}
		}
	}
}

void Carrera::detectarColision2()
{
	for (int i = 0; i < carros.size(); i++)
	{
		if (carros[i]->getTipo() == 3)
		{
			for (int j = 0; j < carros.size(); j++)
			{
				if (i != j && carros[j]->getTipo() == 1)
				{
					if (carros[i]->getRectangle().IntersectsWith(carros[j]->getRectangle())) 
					{
						carros[i]->SetNuevaDireccion();
						carros[j]->SetNuevaDireccion();
					}
				}
			}
		}
	}
}

void Carrera::detectarColision3()  
{
	for (int i = 0; i < carros.size(); i++)
	{
		if (carros[i]->getTipo() == 3)
		{
			for (int j = 0; j < carros.size(); j++)
			{
				if (i != j && carros[j]->getTipo() == 1)
				{
					if (carros[i]->getRectangle().IntersectsWith(carros[j]->getRectangle()) || carros[j]->getRectangle().IntersectsWith(carros[i]->getRectangle()))
					{
						Random r, r2; 
						int posX = r.Next(0, 750); 
						int posY = r2.Next(0, 550); 
						carros.push_back(new CarroRojo(posX, posY)); 
					}
				}
			}
		}
	}
}

/*
COMO NO ENCONTRAMOS MODELOS DE CARROS DE LOS COLORES ESPECIFICACOS EN EL DOCUMENTO, USAMOS OTROS COLORES
CARRO 1 -> ROJO
CARRO 2 -> VERDE
CARRO 3 -> AZUL

*/


