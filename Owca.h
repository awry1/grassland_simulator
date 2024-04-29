#pragma once
#include "Zwierze.h"

class Owca: public Zwierze
{
public:
	Owca(Swiat& swiat, int x, int y, int wiek);

	void rysuj() override;
	void rozmnazaj() override;
};