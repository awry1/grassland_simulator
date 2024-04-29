#include "Owca.h"

Owca::Owca(Swiat& swiat, int x, int y, int wiek) :Zwierze(swiat, 4, 4, 0, 0, wiek, x, y)
{
	setNazwa("Owca");
}

void Owca::rysuj()
{
	printf("O");
}
void Owca::rozmnazaj()
{
	int nowaPozycja[2] = { getX(), getY() };
	getSasiedniePole(nowaPozycja);
	if (nowaPozycja[0] > -1 && nowaPozycja[1] > -1)
		swiat.dodajOrganizm(new Owca(swiat, nowaPozycja[0], nowaPozycja[1], 0));
	/*else
		swiat.aktualizujDziennik("brak miejca na nowy organizm\n");*/
}