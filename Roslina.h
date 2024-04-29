#pragma once
#include "Organizm.h"

class Roslina : public Organizm
{
public:
	Roslina(Swiat& swiat, int sila, int inicjatywa, int wiek, int x, int y);
	virtual ~Roslina() = default;

	virtual void akcja() override;
	virtual void kolizja(Organizm* przeciwnik) override;
	virtual void rysuj() override = 0;
	virtual void rozmnazaj() override = 0;
	bool czyOdbija(Organizm* przeciwnik) override;
	bool czyUcieka() override;
	bool czyJestZwierzeciem() override;
};