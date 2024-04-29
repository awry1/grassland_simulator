#include "Czlowiek.h"

Czlowiek::Czlowiek(Swiat& swiat, int x, int y, int wiek) :Zwierze(swiat, 5, 4, 0, 0, wiek, x, y), kierunek(0), zdolnosc(0)
{
	setNazwa("Czlowiek");
}

void Czlowiek::setKierunek(int kierunek)
{
	this->kierunek = kierunek;
}
void Czlowiek::setZdolnosc(int zdolnosc)
{
	this->zdolnosc = zdolnosc;
}

int Czlowiek::getZdolnosc()
{
	return zdolnosc;
}

void Czlowiek::rysuj()
{
	printf("C");
}
void Czlowiek::rozmnazaj() {}
void Czlowiek::akcja()
{
	bool statusZycia = getStatusZycia();
	if (statusZycia != 0)
	{
		calopalenie();
		ruch();
		calopalenie();
	}
	setWiek(wiek + 1);
}
void Czlowiek::ruch()
{
	int nowaPozycja[2] = { pozycja[0], pozycja[1] };
	int maxX = swiat.getX() - 1;
	int maxY = swiat.getY() - 1;
	switch (kierunek)
	{
	case 0:		// brak ruchu
		return;
		break;
	case 1:		// gora
		if (nowaPozycja[1] - 1 >= 0)
		{
			nowaPozycja[1] -= 1;
		}
		break;
	case 2:		// lewo
		if (nowaPozycja[0] - 1 >= 0)
		{
			nowaPozycja[0] -= 1;
		}
		break;
	case 3:		// dol
		if (nowaPozycja[1] + 1 <= maxY)
		{
			nowaPozycja[1] += 1;
		}
		break;
	case 4:		// prawo
		if (nowaPozycja[0] + 1 <= maxX)
		{
			nowaPozycja[0] += 1;
		}
		break;
	default:
		break;
	}
	setKierunek(0);
	Organizm* poleDocelowe = swiat.getPole(nowaPozycja[0], nowaPozycja[1]);
	if (poleDocelowe == NULL)
	{
		swiat.setPole(NULL, pozycja[0], pozycja[1]);
		pozycja[0] = nowaPozycja[0];
		pozycja[1] = nowaPozycja[1];
		swiat.setPole(this, nowaPozycja[0], nowaPozycja[1]);
	}
	else
		kolizja(poleDocelowe);
}
void Czlowiek::calopalenie()
{
	if (getZdolnosc() <= 5)
		return;
	int maxX = swiat.getX() - 1;
	int maxY = swiat.getY() - 1;
	int x = getX();
	int y = getY();
	Organizm* ofiara;
	if (y - 1 >= 0)
	{
		ofiara = swiat.getPole(x, y - 1);
		if (ofiara != NULL)
		{
			swiat.usunOrganizm(ofiara, this);
			swiat.setPole(NULL, x, y - 1);
		}
	}
	if (x - 1 >= 0)
	{
		ofiara = swiat.getPole(x - 1, y);
		if (ofiara != NULL)
		{
			swiat.usunOrganizm(ofiara, this);
			swiat.setPole(NULL, x - 1, y);
		}
	}
	if (y + 1 <= maxY)
	{
		ofiara = swiat.getPole(x, y + 1);
		if (ofiara != NULL)
		{
			swiat.usunOrganizm(ofiara, this);
			swiat.setPole(NULL, x, y + 1);
		}
	}
	if (x + 1 <= maxX)
	{
		ofiara = swiat.getPole(x + 1, y);
		if (ofiara != NULL)
		{
			swiat.usunOrganizm(ofiara, this);
			swiat.setPole(NULL, x + 1, y);
		}
	}
}