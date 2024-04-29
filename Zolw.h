#pragma once
#include "Zwierze.h"

class Zolw : public Zwierze
{
public:
	Zolw(Swiat& swiat, int x, int y, int wiek);

	void rysuj() override;
	void rozmnazaj() override;
	void ruch(int odleglosc) override;
};