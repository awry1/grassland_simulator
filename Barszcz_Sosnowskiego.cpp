#include "Barszcz_Sosnowskiego.h"

Barszcz_Sosnowskiego::Barszcz_Sosnowskiego(Swiat& swiat, int x, int y, int wiek) :Roslina(swiat, 10, 0, wiek, x, y)
{
	setNazwa("Barszcz Sosnowskiego");
}

void Barszcz_Sosnowskiego::rysuj()
{
	printf("b");
}
void Barszcz_Sosnowskiego::rozmnazaj()
{
	int szansaNaZasianie = rand() % 10;
	if (szansaNaZasianie < 3)
	{
		int nowaPozycja[2] = { getX(), getY() };
		getSasiedniePole(nowaPozycja);
		if (nowaPozycja[0] > -1 && nowaPozycja[1] > -1)
			swiat.dodajOrganizm(new Barszcz_Sosnowskiego(swiat, nowaPozycja[0], nowaPozycja[1], 0));
		/*else
			swiat.aktualizujDziennik("brak miejca na nowy organizm\n");*/
	}
}
void Barszcz_Sosnowskiego::akcja()
{
	int wiek = getWiek();
	bool statusZycia = getStatusZycia();
	if (wiek != 0 && statusZycia != 0)
	{
		calopalenie();
		rozmnazaj();
	}
	setWiek(wiek + 1);
}
void Barszcz_Sosnowskiego::calopalenie()
{
	int maxX = swiat.getX() - 1;
	int maxY = swiat.getY() - 1;
	int x = getX();
	int y = getY();
	Organizm* ofiara;
	if (y - 1 >= 0)
	{
		ofiara = swiat.getPole(x, y - 1);
		if (ofiara != NULL && ofiara->czyJestZwierzeciem() == 1)
		{
			swiat.usunOrganizm(ofiara, this);
			swiat.setPole(NULL, x, y - 1);
		}
	}
	if (x - 1 >= 0)
	{
		ofiara = swiat.getPole(x - 1, y);
		if (ofiara != NULL && ofiara->czyJestZwierzeciem() == 1)
		{
			swiat.usunOrganizm(ofiara, this);
			swiat.setPole(NULL, x - 1, y);
		}
	}
	if (y + 1 <= maxY)
	{
		ofiara = swiat.getPole(x, y + 1);
		if (ofiara != NULL && ofiara->czyJestZwierzeciem() == 1)
		{
			swiat.usunOrganizm(ofiara, this);
			swiat.setPole(NULL, x, y + 1);
		}
	}
	if (x + 1 <= maxX)
	{
		ofiara = swiat.getPole(x + 1, y);
		if (ofiara != NULL && ofiara->czyJestZwierzeciem() == 1)
		{
			swiat.usunOrganizm(ofiara, this);
			swiat.setPole(NULL, x + 1, y);
		}
	}
}