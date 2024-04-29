#pragma once
#include "Zwierze.h"

class Lis : public Zwierze
{
public:
	Lis(Swiat& swiat, int x, int y, int wiek);

	void rysuj() override;
	void rozmnazaj() override;
	void ruch(int odleglosc) override;
};