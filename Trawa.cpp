#include "Trawa.h"

Trawa::Trawa(Swiat& swiat, int x, int y, int wiek) :Roslina(swiat, 0, 0, wiek, x, y)
{
	setNazwa("Trawa");
}

void Trawa::rysuj()
{
	printf("t");
}
void Trawa::rozmnazaj()
{
	int szansaNaZasianie = rand() % 10;
	if (szansaNaZasianie < 3)
	{
		int nowaPozycja[2] = { getX(), getY() };
		getSasiedniePole(nowaPozycja);
		if (nowaPozycja[0] > -1 && nowaPozycja[1] > -1)
			swiat.dodajOrganizm(new Trawa(swiat, nowaPozycja[0], nowaPozycja[1], 0));
		/*else
			swiat.aktualizujDziennik("brak miejca na nowy organizm\n");*/
	}
}