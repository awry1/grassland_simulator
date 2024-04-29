#include "Organizm.h"
#include <algorithm>

Organizm::Organizm(Swiat& swiat, int sila, int inicjatywa, bool odbijanie, bool uciekanie, bool jestZwierzeciem, int wiek, int x, int y) : swiat(swiat), sila(sila), inicjatywa(inicjatywa), odbijanie(odbijanie), uciekanie(uciekanie), jestZwierzeciem(jestZwierzeciem), wiek(wiek), statusZycia(1)
{
	setX(x);
	setY(y);
	swiat.setPole(this, x, y);
}

void Organizm::setSila(int sila)
{
	this->sila = sila;
}
void Organizm::setInicjatywa(int inicjatywa)
{
	this->inicjatywa = inicjatywa;
}
void Organizm::setWiek(int wiek)
{
	this->wiek = wiek;
}
void Organizm::setStatusZycia(bool statusZycia)
{
	this->statusZycia = statusZycia;
}
void Organizm::setX(int x)
{
	this->pozycja[0] = x;
}
void Organizm::setY(int y)
{
	this->pozycja[1] = y;
}
void Organizm::setNazwa(std::string nazwa)
{
	this->nazwa = nazwa;
}

int Organizm::getSila()
{
	return sila;
}
int Organizm::getInicjatywa()
{
	return inicjatywa;
}
bool Organizm::getOdbijanie()
{
	return odbijanie;
}
int Organizm::getWiek()
{
	return wiek;
}
bool Organizm::getStatusZycia()
{
	return statusZycia;
}
int Organizm::getX()
{
	return pozycja[0];
}
int Organizm::getY()
{
	return pozycja[1];
}
std::string Organizm::getNazwa()
{
	return nazwa;
}
void Organizm::getSasiedniePole(int (&pozycja)[2])
{
	int maxX = swiat.getX() - 1;
	int maxY = swiat.getY() - 1;
	int kierunek[4] = { 0, 1, 2, 3 };
	std::random_shuffle(&kierunek[0], &kierunek[4]);
	for (int i = 0; i < 4; i++)
	{
		switch (kierunek[i])
		{
		case 0:		// gora
			if (pozycja[1] - 1 >= 0)
				pozycja[1] -= 1;
			break;
		case 1:		// lewo
			if (pozycja[0] - 1 >= 0)
				pozycja[0] -= 1;
			break;
		case 2:		// dol
			if (pozycja[1] + 1 <= maxY)
				pozycja[1] += 1;
			break;
		case 3:		// prawo
			if (pozycja[0] + 1 <= maxX)
				pozycja[0] += 1;
			break;
		}
		if (swiat.getPole(pozycja[0], pozycja[1]) == NULL)
			break;
	}
	if (swiat.getPole(pozycja[0], pozycja[1]) != NULL)
	{
		pozycja[0] = -1;
		pozycja[1] = -1;
	}
}
void Organizm::getSlabePole(int(&pozycja)[2], int sila)
{
	int maxX = swiat.getX() - 1;
	int maxY = swiat.getY() - 1;
	int staraPozycja[2] = { pozycja[0], pozycja[1] };
	int kierunek[4] = { 0, 1, 2, 3 };
	std::random_shuffle(&kierunek[0], &kierunek[4]);
	for (int i = 0; i < 4; i++)
	{
		switch (kierunek[i])
		{
		case 0:		// gora
			if (pozycja[1] - 1 >= 0)
				pozycja[1] -= 1;
			break;
		case 1:		// lewo
			if (pozycja[0] - 1 >= 0)
				pozycja[0] -= 1;
			break;
		case 2:		// dol
			if (pozycja[1] + 1 <= maxY)
				pozycja[1] += 1;
			break;
		case 3:		// prawo
			if (pozycja[0] + 1 <= maxX)
				pozycja[0] += 1;
			break;
		}
		if ((staraPozycja[0] != pozycja[0] && staraPozycja[1] != pozycja[1]) && (swiat.getPole(pozycja[0], pozycja[1]) == NULL || swiat.getPole(pozycja[0], pozycja[1])->getSila() <= sila))
			break;
	}
	if ((staraPozycja[0] == pozycja[0] && staraPozycja[1] == pozycja[1]) || (swiat.getPole(pozycja[0], pozycja[1]) != NULL && swiat.getPole(pozycja[0], pozycja[1])->getSila() > sila))
	{
		pozycja[0] = -1;
		pozycja[1] = -1;
	}
}