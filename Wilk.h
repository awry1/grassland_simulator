#pragma once
#include "Zwierze.h"

class Wilk : public Zwierze
{
public:
	Wilk(Swiat& swiat, int x, int y, int wiek);

	void rysuj() override;
	void rozmnazaj() override;
};