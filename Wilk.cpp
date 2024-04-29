#include "Wilk.h"

Wilk::Wilk(Swiat& swiat, int x, int y, int wiek) :Zwierze(swiat, 9, 5, 0, 0, wiek, x, y)
{
	setNazwa("Wilk");
}

void Wilk::rysuj()
{
	printf("W");
}
void Wilk::rozmnazaj()
{
	int nowaPozycja[2] = { getX(), getY() };
	getSasiedniePole(nowaPozycja);
	if (nowaPozycja[0] > -1 && nowaPozycja[1] > -1)
		swiat.dodajOrganizm(new Wilk(swiat, nowaPozycja[0], nowaPozycja[1], 0));
	/*else
		swiat.aktualizujDziennik("brak miejca na nowy organizm\n");*/
}