#pragma once
#include <fstream>
#include "Swiat.h"
#include "Czlowiek.h"
#include "Wilk.h"
#include "Owca.h"
#include "Lis.h"
#include "Zolw.h"
#include "Antylopa.h"
#include "Trawa.h"
#include "Mlecz.h"
#include "Guarana.h"
#include "Wilcze_Jagody.h"
#include "Barszcz_Sosnowskiego.h"

class Zapis
{
private:
	std::string nazwaPliku;
public:
	Zapis(std::string NazwaPliku);
	~Zapis() = default;

	void ZapiszSwiat(Swiat& Swiat);
	void ZapiszOrganizm(Organizm& organizm, std::ofstream& saveFile);
	void ZapiszCzlowieka(Czlowiek& czlowiek, std::ofstream& saveFile);

	Swiat* WczytajSwiat();
	Organizm* WczytajOrganizm(Swiat& swiat, std::ifstream& saveFile);
	Czlowiek* WczytajCzlowieka(Swiat& swiat, std::ifstream& saveFile);
};
