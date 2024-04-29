#include "Roslina.h"

Roslina::Roslina(Swiat& swiat, int sila, int inicjatywa, int wiek, int x, int y) : Organizm(swiat, sila, inicjatywa, 0, 0, 0, wiek, x, y) {}

void Roslina::akcja()
{
	int wiek = getWiek();
	bool statusZycia = getStatusZycia();
	if (wiek != 0 && statusZycia != 0)
	{
		rozmnazaj();
	}
	setWiek(wiek + 1);
}
void Roslina::kolizja(Organizm* przeciwnik) {}
bool Roslina::czyOdbija(Organizm* przeciwnik)
{
	return 0;
}
bool Roslina::czyUcieka()
{
	return 0;
}
bool Roslina::czyJestZwierzeciem()
{
	return 0;
}