#include "CarroPadre.h"

void CarroPadre::cambiarImagen(char* nombreDelArchivo)
{
	strcpy(imagen, nombreDelArchivo);   
	Bitmap^ sprite = gcnew Bitmap(gcnew System::String(imagen));
	ancho = sprite->Width;
	alto = sprite->Height;
	delete sprite;
}

void CarroPadre::dibujarImagen(Graphics^ canvas, Bitmap^ sprite, Rectangle zoom, Rectangle corte)
{
	canvas->DrawImage(sprite, zoom, corte, GraphicsUnit::Pixel);
}

CarroPadre::CarroPadre(int x, int y, char* imagen)
{
	this->x = x; 
	this->y = y; 
	this->imagen = new char[48];
	cambiarImagen(imagen);

}

void CarroPadre::mostrar(Graphics^ canvas)
{
	Bitmap^ sprite = gcnew Bitmap(gcnew System::String(imagen));  
	Rectangle corte = Rectangle(0,0, ancho, alto); 
	Rectangle zoom = Rectangle	(x, y, ancho / 3, alto / 3);  
	dibujarImagen(canvas, sprite, zoom, corte);  
}



void CarroPadre::reset()
{
	x = 0;
	dx = 0;
}

void CarroPadre::MoverCarrera(Graphics^ canvas)
{
}

void CarroPadre::MoverDiagonal(Graphics^ canvas)
{
}



Rectangle CarroPadre::getRectangle()
{
	return Rectangle(x,y,ancho,alto);
}

int CarroPadre::getX()
{
	return x;
}

int CarroPadre::getY()
{
	return y;
}

int CarroPadre::getAlto()
{
	return alto;
}

int CarroPadre::getAncho()
{
	return ancho;
}

bool CarroPadre::hayColision(CarroPadre* carropadre)
{
	return getRectangle().IntersectsWith(carropadre->getRectangle());
}

int CarroPadre::getTipo()
{
	return tipo;  
}

void CarroPadre::SetNuevaDireccion() 
{
	dx *= -1; 
	dy *= -1; 
}


