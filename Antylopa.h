#pragma once
#include "Zwierze.h"

class Antylopa : public Zwierze
{
public:
	Antylopa(Swiat& swiat, int x, int y, int wiek);

	void rysuj() override;
	void rozmnazaj() override;
	void akcja() override;
	bool czyUcieka() override;
};