#include "Antylopa.h"

Antylopa::Antylopa(Swiat& swiat, int x, int y, int wiek) :Zwierze(swiat, 4, 4, 0, 1, wiek, x, y)
{
	setNazwa("Antylopa");
}

void Antylopa::rysuj()
{
	printf("A");
}
void Antylopa::rozmnazaj()
{
	int nowaPozycja[2] = { getX(), getY() };
	getSasiedniePole(nowaPozycja);
	if (nowaPozycja[0] > -1 && nowaPozycja[1] > -1)
		swiat.dodajOrganizm(new Antylopa(swiat, nowaPozycja[0], nowaPozycja[1], 0));
	/*else
		swiat.aktualizujDziennik("brak miejca na nowy organizm\n");*/
}
void Antylopa::akcja()
{
	int wiek = getWiek();
	bool statusZycia = getStatusZycia();
	if (wiek != 0 && statusZycia != 0)
		ruch(2);
	setWiek(wiek + 1);
}
bool Antylopa::czyUcieka()
{
	return 1;
}