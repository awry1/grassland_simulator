#pragma once
#include <initializer_list>
#include <string>
#include <list>
#include <vector>
#include <time.h>

class Organizm;
class Czlowiek;
class Swiat
{
private:
	int rozmX, rozmY;
	Organizm*** mapa;
	bool koniecGry;
	std::list<Organizm*> kolejka;
	std::string dziennik;
	Czlowiek* czlowiek;
	unsigned int seed;
public:
	Swiat(int x, int y, unsigned int seed, bool nowaGra);
	~Swiat();

	void setCzlowiek(Czlowiek* czlowiek);
	void setDziennik(std::string string);
	void setPole(Organizm* organizm, int x, int y);
	void setKierunekCzlowieka(int kierunek);
	void setZdolnoscCzlowieka(int zdolnosc);

	int getX();
	int getY();
	unsigned int getSeed();
	Czlowiek* getCzlowiek();
	std::list<Organizm*> getKolejka();
	std::string getDziennik();
	Organizm* getPole(int x, int y);
	void getLosowePole(int (&pole)[2]);
	bool getStanGry();
	int getZdolnoscCzlowieka();

	void aktualizujDziennik(std::string wiadomosc);
	void rysujSwiat();
	void usunOrganizm(Organizm* ofiara, Organizm* przeciwnik);
	void dodajOrganizm(Organizm* dziecko);
	void wykonajTure();
};