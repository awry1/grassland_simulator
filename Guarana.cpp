#include "Guarana.h"

Guarana::Guarana(Swiat& swiat, int x, int y, int wiek) :Roslina(swiat, 0, 0, wiek, x, y)
{
	setNazwa("Guarana");
}

void Guarana::rysuj()
{
	printf("g");
}
void Guarana::rozmnazaj()
{
	int szansaNaZasianie = rand() % 10;
	if (szansaNaZasianie < 3)
	{
		int nowaPozycja[2] = { getX(), getY() };
		getSasiedniePole(nowaPozycja);
		if (nowaPozycja[0] > -1 && nowaPozycja[1] > -1)
			swiat.dodajOrganizm(new Guarana(swiat, nowaPozycja[0], nowaPozycja[1], 0));
		/*else
			swiat.aktualizujDziennik("brak miejca na nowy organizm\n");*/
	}
}