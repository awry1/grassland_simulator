#pragma once
#include "Roslina.h"

class Trawa : public Roslina
{
public:
	Trawa(Swiat& swiat, int x, int y, int wiek);

	void rysuj() override;
	void rozmnazaj() override;
};