#include "Zwierze.h"

Zwierze::Zwierze(Swiat& swiat, int sila, int inicjatywa, bool odbijanie, bool uciekanie, int wiek, int x, int y) : Organizm(swiat, sila, inicjatywa, odbijanie, uciekanie, 1, wiek, x, y) {}

void Zwierze::akcja()
{
	int wiek = getWiek();
	bool statusZycia = getStatusZycia();
	if (wiek != 0 && statusZycia != 0)
		ruch(1);
	setWiek(wiek + 1);
}
void Zwierze::kolizja(Organizm* przeciwnik)
{
	if (getNazwa() == przeciwnik->getNazwa())
	{
		if (getWiek() > 0 && przeciwnik->getWiek() > 0)
			rozmnazaj();
	}
	else if (czyOdbija(przeciwnik) == 0)
	{
		swiat.setPole(NULL, pozycja[0], pozycja[1]);
		pozycja[0] = przeciwnik->getX();
		pozycja[1] = przeciwnik->getY();
		if (przeciwnik->czyUcieka() == 1)
		{
			int szansaNaUcieczke = rand() % 2;
			if (szansaNaUcieczke == 0)
			{
				int nowaPozycja[2] = { przeciwnik->getX(), przeciwnik->getY() };
				getSasiedniePole(nowaPozycja);
				if (nowaPozycja[0] > -1 && nowaPozycja[1] > -1)
				{
					swiat.aktualizujDziennik(przeciwnik->getNazwa() + " uciekl przed " + getNazwa() + "\n");
					swiat.setPole(this, pozycja[0], pozycja[1]);
					przeciwnik->setX(nowaPozycja[0]);
					przeciwnik->setY(nowaPozycja[1]);
					swiat.setPole(przeciwnik, nowaPozycja[0], nowaPozycja[1]);
					return;
				}				
			}
		}
		if (getSila() >= przeciwnik->getSila())
		{
			if (przeciwnik->getNazwa() == "Guarana")
			{
				int sila = getSila();
				setSila(sila + 3);
			}
			swiat.usunOrganizm(przeciwnik, this);
			swiat.setPole(this, pozycja[0], pozycja[1]);
		}
		else if (getSila() < przeciwnik->getSila())
		{
			swiat.usunOrganizm(this, przeciwnik);
		}
	}
}
void Zwierze::ruch(int odleglosc)
{
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
bool Zwierze::czyOdbija(Organizm* przeciwnik)
{
	if (przeciwnik->getOdbijanie() == 1 && getSila() < 5)
	{
		swiat.aktualizujDziennik(przeciwnik->getNazwa() + " odbil atak " + getNazwa() + "\n");
		return 1;
	}
	else
		return 0;
}
bool Zwierze::czyUcieka()
{
	return 0;
}
bool Zwierze::czyJestZwierzeciem()
{
	return 1;
}