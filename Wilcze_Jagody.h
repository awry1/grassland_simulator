#pragma once
#include "Roslina.h"

class Wilcze_Jagody : public Roslina
{
public:
	Wilcze_Jagody(Swiat& swiat, int x, int y, int wiek);

	void rysuj() override;
	void rozmnazaj() override;
};