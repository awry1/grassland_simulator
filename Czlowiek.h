#pragma once
#include "Zwierze.h"

class Czlowiek : public Zwierze
{
private:
	int kierunek, zdolnosc;
public:
	Czlowiek(Swiat& swiat, int x, int y, int wiek);

	void setKierunek(int kierunek);
	void setZdolnosc(int zdolnosc);

	int getZdolnosc();

	void rysuj() override;
	void rozmnazaj() override;
	void akcja() override;
	void ruch();
	void calopalenie();
};