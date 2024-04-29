#pragma once
#include "Organizm.h"

class Zwierze: public Organizm
{
public:
	Zwierze(Swiat& swiat, int sila, int inicjatywa, bool odbijanie, bool uciekanie, int wiek, int x, int y);
	virtual ~Zwierze() = default;

	virtual void akcja() override;
	virtual void kolizja(Organizm* przeciwnik) override;
	virtual void rysuj() override = 0;
	virtual void rozmnazaj() override = 0;
	bool czyOdbija(Organizm* przeciwnik) override;
	bool czyUcieka() override;
	bool czyJestZwierzeciem() override;
	virtual void ruch(int odleglosc);
};