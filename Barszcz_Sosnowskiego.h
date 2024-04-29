#pragma once
#include "Roslina.h"

class Barszcz_Sosnowskiego : public Roslina
{
public:
	Barszcz_Sosnowskiego(Swiat& swiat, int x, int y, int wiek);

	void rysuj() override;
	void rozmnazaj() override;
	void akcja() override;
	void calopalenie();
};