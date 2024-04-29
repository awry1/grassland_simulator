#include "Lis.h"

Lis::Lis(Swiat& swiat, int x, int y, int wiek) :Zwierze(swiat, 3, 7, 0, 0, wiek, x, y)
{
	setNazwa("Lis");
}

void Lis::rysuj()
{
	printf("L");
}
void Lis::rozmnazaj()
{
	int nowaPozycja[2] = { getX(), getY() };
	getSasiedniePole(nowaPozycja);
	if (nowaPozycja[0] > -1 && nowaPozycja[1] > -1)
		swiat.dodajOrganizm(new Lis(swiat, nowaPozycja[0], nowaPozycja[1], 0));
	/*else
		swiat.aktualizujDziennik("brak miejca na nowy organizm\n");*/
}
void Lis::ruch(int odleglosc)
{
	int nowaPozycja[2] = { pozycja[0], pozycja[1] };
	int maxX = swiat.getX() - 1;
	int maxY = swiat.getY() - 1;
	getSlabePole(nowaPozycja, getSila());
	if (nowaPozycja[0] > -1 && nowaPozycja[1] > -1)
	{
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
}