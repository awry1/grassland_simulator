#include "Wilcze_Jagody.h"

Wilcze_Jagody::Wilcze_Jagody(Swiat& swiat, int x, int y, int wiek) :Roslina(swiat, 99, 0, wiek, x, y)
{
	setNazwa("Wilcze Jagody");
}

void Wilcze_Jagody::rysuj()
{
	printf("w");
}
void Wilcze_Jagody::rozmnazaj()
{
	int szansaNaZasianie = rand() % 10;
	if (szansaNaZasianie < 3)
	{
		int nowaPozycja[2] = { getX(), getY() };
		getSasiedniePole(nowaPozycja);
		if (nowaPozycja[0] > -1 && nowaPozycja[1] > -1)
			swiat.dodajOrganizm(new Wilcze_Jagody(swiat, nowaPozycja[0], nowaPozycja[1], 0));
		/*else
			swiat.aktualizujDziennik("brak miejca na nowy organizm\n");*/
	}
}