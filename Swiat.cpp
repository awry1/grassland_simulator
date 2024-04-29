#include "Swiat.h"
#include "Czlowiek.h"
#include "Wilk.h"
#include "Owca.h"
#include "Lis.h"
#include "Zolw.h"
#include "Antylopa.h"
#include "Trawa.h"
#include "Mlecz.h"
#include "Guarana.h"
#include "Wilcze_Jagody.h"
#include "Barszcz_Sosnowskiego.h"

Swiat::Swiat(int rozmX, int rozmY, unsigned int seed, bool nowaGra) : rozmX(rozmX), rozmY(rozmY), dziennik(""), seed(seed), czlowiek(NULL)
{
	srand(seed);
	mapa = (Organizm***)calloc(rozmY, sizeof(Organizm**));
	for (int i = 0; i < rozmY; i++)
	{
		mapa[i] = (Organizm**)calloc(rozmX, sizeof(Organizm*));
		for (int j = 0; j < rozmX; j++)
		{
			mapa[i][j] = NULL;
		}
	}
	koniecGry = 0;

	if (nowaGra == 1)
	{
		int pole[2];
		for (int i = 0; i < 2; i++)
		{
			getLosowePole(pole);
			kolejka.push_back(new Lis(*this, pole[0], pole[1], 0));
		}
		for (int i = 0; i < 2; i++)
		{
			getLosowePole(pole);
			kolejka.push_back(new Wilk(*this, pole[0], pole[1], 0));
		}

		getLosowePole(pole);
		czlowiek = new Czlowiek(*this, pole[0], pole[1], 0);
		kolejka.push_back(czlowiek);

		for (int i = 0; i < 2; i++)
		{
			getLosowePole(pole);
			kolejka.push_back(new Antylopa(*this, pole[0], pole[1], 0));
		}
		for (int i = 0; i < 2; i++)
		{
			getLosowePole(pole);
			kolejka.push_back(new Owca(*this, pole[0], pole[1], 0));
		}
		for (int i = 0; i < 2; i++)
		{
			getLosowePole(pole);
			kolejka.push_back(new Zolw(*this, pole[0], pole[1], 0));
		}
		for (int i = 0; i < 2; i++)
		{
			getLosowePole(pole);
			kolejka.push_back(new Trawa(*this, pole[0], pole[1], 0));
		}
		for (int i = 0; i < 2; i++)
		{
			getLosowePole(pole);
			kolejka.push_back(new Mlecz(*this, pole[0], pole[1], 0));
		}
		for (int i = 0; i < 2; i++)
		{
			getLosowePole(pole);
			kolejka.push_back(new Guarana(*this, pole[0], pole[1], 0));
		}
		for (int i = 0; i < 2; i++)
		{
			getLosowePole(pole);
			kolejka.push_back(new Wilcze_Jagody(*this, pole[0], pole[1], 0));
		}
		for (int i = 0; i < 2; i++)
		{
			getLosowePole(pole);
			kolejka.push_back(new Barszcz_Sosnowskiego(*this, pole[0], pole[1], 0));
		}
	}
}
Swiat::~Swiat()
{
	for (int i = 0; i < rozmX; i++)
	{
		for (int j = 0; j < rozmY; j++)
		{
			delete(mapa[i][j]);
		}
		free(mapa[i]);
	}
	free(mapa);
}

void Swiat::setCzlowiek(Czlowiek* czlowiek)
{
	this->czlowiek = czlowiek;
}
void Swiat::setDziennik(std::string string)
{
	dziennik = string;
}
void Swiat::setPole(Organizm* organizm, int x, int y)
{
	mapa[x][y] = organizm;
}
void Swiat::setKierunekCzlowieka(int kierunek)
{
	czlowiek->setKierunek(kierunek);
}
void Swiat::setZdolnoscCzlowieka(int zdolnosc)
{
	czlowiek->setZdolnosc(zdolnosc);
}

int Swiat::getX()
{
	return rozmX;
}
int Swiat::getY()
{
	return rozmY;
}
unsigned int Swiat::getSeed()
{
	return seed;
}
Czlowiek* Swiat::getCzlowiek()
{
	return czlowiek;
}
std::list<Organizm*> Swiat::getKolejka()
{
	return kolejka;
}
std::string Swiat::getDziennik()
{
	return dziennik;
}
Organizm* Swiat::getPole(int x, int y)
{
	return mapa[x][y];
}
void Swiat::getLosowePole(int(&pole)[2])
{
	do
	{
		pole[0] = rand() % (rozmX);
		pole[1] = rand() % (rozmY);
	} while (getPole(pole[0], pole[1]) != NULL);
}
bool Swiat::getStanGry()
{
	if (koniecGry == 0)
		return true;
	else
		return false;
}
int Swiat::getZdolnoscCzlowieka()
{
	return czlowiek->getZdolnosc();
}

void Swiat::aktualizujDziennik(std::string wiadomosc)
{
	dziennik += wiadomosc;
}
void Swiat::rysujSwiat()
{
	system("CLS");	// wyczysc konsole
	printf("Kamil Lubarski 18859 projekt C++\n");

	for (int i = 0; i < rozmX + 2; i++)
		printf("#");
	printf("\n");
	for (int i = 0; i < rozmY; i++)
	{
		printf("#");
		for (int j = 0; j < rozmX; j++)
		{
			if (mapa[j][i] != NULL)
				mapa[j][i]->rysuj();
			else
				printf(" ");
		}
		printf("#\n");
	}
	for (int i = 0; i < rozmX + 2; i++)
		printf("#");
	printf("\n\n%s", dziennik.c_str());
	setDziennik("");
}
void Swiat::usunOrganizm(Organizm* ofiara, Organizm* przeciwnik)
{
	std::string nekrolog = ofiara->getNazwa() + " zostal zjedzony";
	if (przeciwnik != NULL)
		nekrolog += " przez " + przeciwnik->getNazwa();
	aktualizujDziennik(nekrolog + "\n");
	ofiara->setStatusZycia(0);
}
void Swiat::dodajOrganizm(Organizm* dziecko)
{
	bool done = 0;
	std::list<Organizm*>::iterator i = kolejka.begin();
	for (i = kolejka.begin(); i != kolejka.end() && done != 1; ++i)
	{
		if (dziecko->getInicjatywa() > (*i)->getInicjatywa())
		{
			kolejka.insert(i, dziecko);
			done = 1;
		}
	}
	if(done != 1)
		kolejka.push_back(dziecko);
	aktualizujDziennik(dziecko->getNazwa() + " rozmnozyl sie\n");
}
void Swiat::wykonajTure()
{
	std::list<Organizm*>::iterator i;
	for (i = kolejka.begin(); i != kolejka.end(); ++i)
	{
		if ((*i)->getStatusZycia() == 1)
			(*i)->akcja();
	}
	koniecGry = !czlowiek->getStatusZycia();
	for (i = kolejka.begin(); i != kolejka.end();)
	{
		if ((*i)->getStatusZycia() == 0)
		{
			delete(*i);
			i = kolejka.erase(i);
		}
		else
			i++;
	}
	int zdolnosc = getZdolnoscCzlowieka();
	if (zdolnosc > 0)
		setZdolnoscCzlowieka(zdolnosc - 1);
}