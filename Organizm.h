#pragma once
#include "Swiat.h"

class Organizm
{
protected:
	int sila, inicjatywa, wiek;
	int pozycja[2];
	bool statusZycia;
	bool odbijanie, uciekanie, jestZwierzeciem;
	std::string nazwa;
	Swiat& swiat;
public:
	Organizm(Swiat& swiat, int sila, int inicjatywa, bool odbijanie, bool uciekanie, bool jestZwierzeciem, int wiek, int x, int y);
	virtual ~Organizm() = default;

	void setSila(int sila);
	void setInicjatywa(int inicjatywa);
	void setWiek(int wiek);
	void setStatusZycia(bool statusZycia);
	void setX(int x);
	void setY(int y);
	void setNazwa(std::string nazwa);

	int getSila();
	int getInicjatywa();
	bool getOdbijanie();
	int getWiek();
	bool getStatusZycia();
	int getX();
	int getY();
	std::string getNazwa();
	void getSasiedniePole(int(&pozycja)[2]);
	void getSlabePole(int(&pozycja)[2], int sila);

	virtual void akcja() = 0;
	virtual void kolizja(Organizm* przeciwnik) = 0;
	virtual void rysuj() = 0;
	virtual void rozmnazaj() = 0;
	virtual bool czyOdbija(Organizm* przeciwnik) = 0;
	virtual bool czyUcieka() = 0;
	virtual bool czyJestZwierzeciem() = 0;
};