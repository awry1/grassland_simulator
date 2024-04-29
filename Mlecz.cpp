#include "Mlecz.h"

Mlecz::Mlecz(Swiat& swiat, int x, int y, int wiek) :Roslina(swiat, 0, 0, wiek, x, y)
{
	setNazwa("Mlecz");
}

void Mlecz::rysuj()
{
	printf("m");
}
void Mlecz::rozmnazaj()
{
	for (int i = 0; i < 3; i++)
	{
		int szansaNaZasianie = rand() % 10;
		if (szansaNaZasianie < 3)
		{
			int nowaPozycja[2] = { getX(), getY() };
			getSasiedniePole(nowaPozycja);
			if (nowaPozycja[0] > -1 && nowaPozycja[1] > -1)
				swiat.dodajOrganizm(new Mlecz(swiat, nowaPozycja[0], nowaPozycja[1], 0));
			/*else
				swiat.aktualizujDziennik("brak miejca na nowy organizm\n");*/
		}
	}
}