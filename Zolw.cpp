#include "Zolw.h"

Zolw::Zolw(Swiat& swiat, int x, int y, int wiek) :Zwierze(swiat, 2, 1, 1, 0, wiek, x, y)
{
	setNazwa("Zolw");
}

void Zolw::rysuj()
{
	printf("Z");
}
void Zolw::rozmnazaj()
{
	int nowaPozycja[2] = { getX(), getY() };
	getSasiedniePole(nowaPozycja);
	if (nowaPozycja[0] > -1 && nowaPozycja[1] > -1)
		swiat.dodajOrganizm(new Zolw(swiat, nowaPozycja[0], nowaPozycja[1], 0));
	/*else
		swiat.aktualizujDziennik("brak miejca na nowy organizm\n");*/
}
void Zolw::ruch(int odleglosc)
{
	int szansaNaRuch = rand() % 4;
	if (szansaNaRuch != 0)
		return;
	int nowaPozycja[2] = { pozycja[0], pozycja[1] };
	int maxX = swiat.getX() - 1;
	int maxY = swiat.getY() - 1;
	bool done = 0;
	while (done != 1)
	{
		int kierunek = rand() % (4 * odleglosc);
		switch (kierunek)
		{
		case 0:		// gora
			if (nowaPozycja[1] - odleglosc >= 0)
			{
				nowaPozycja[1] -= odleglosc;
				done = 1;
			}
			break;
		case 1:		// lewo
			if (nowaPozycja[0] - odleglosc >= 0)
			{
				nowaPozycja[0] -= odleglosc;
				done = 1;
			}
			break;
		case 2:		// dol
			if (nowaPozycja[1] + odleglosc <= maxY)
			{
				nowaPozycja[1] += odleglosc;
				done = 1;
			}
			break;
		case 3:		// prawo
			if (nowaPozycja[0] + odleglosc <= maxX)
			{
				nowaPozycja[0] += odleglosc;
				done = 1;
			}
			break;
		case 4:		// gora lewo
			if (nowaPozycja[1] - 1 >= 0 && nowaPozycja[0] - 1 >= 0)
			{
				nowaPozycja[0] -= 1;
				nowaPozycja[1] -= 1;
				done = 1;
			}
			break;
		case 5:		// gora prawo
			if (nowaPozycja[1] - 1 >= 0 && nowaPozycja[0] + 1 <= maxX)
			{
				nowaPozycja[0] += 1;
				nowaPozycja[1] -= 1;
				done = 1;
			}
			break;
		case 6:		// dol lewo
			if (nowaPozycja[1] + 1 <= maxY && nowaPozycja[0] - 1 >= 0)
			{
				nowaPozycja[0] -= 1;
				nowaPozycja[1] += 1;
				done = 1;
			}
			break;
		case 7:		// dol prawo
			if (nowaPozycja[1] + 1 <= maxY && nowaPozycja[0] + 1 <= maxX)
			{
				nowaPozycja[0] += 1;
				nowaPozycja[1] += 1;
				done = 1;
			}
			break;
		default:
			break;
		}
	}
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