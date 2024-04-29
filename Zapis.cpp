#include "Zapis.h"

Zapis::Zapis(std::string NazwaPliku)
{
	this->nazwaPliku = NazwaPliku;
}

void Zapis::ZapiszSwiat(Swiat& swiat)
{
	std::ofstream saveFile(nazwaPliku);
	saveFile << swiat.getX() << " " << swiat.getY() << " " << swiat.getSeed() << " " << swiat.getKolejka().size() << '\n';
	std::list<Organizm*> kolejka = swiat.getKolejka();
	std::list<Organizm*>::iterator i;
	for (i = kolejka.begin(); i != kolejka.end(); ++i)
	{
		if ((*i)->getNazwa() != "Czlowiek")
			ZapiszOrganizm((**i), saveFile);
	}
	ZapiszCzlowieka((*swiat.getCzlowiek()), saveFile);
	saveFile.close();
}
void Zapis::ZapiszOrganizm(Organizm& organizm, std::ofstream& saveFile)
{
	saveFile << organizm.getNazwa() << " " << organizm.getSila() << " " << organizm.getInicjatywa() << " " << organizm.getWiek() << " " << organizm.getX() << " " << organizm.getY() << "\n";
}
void Zapis::ZapiszCzlowieka(Czlowiek& czlowiek, std::ofstream& saveFile)
{
	saveFile << czlowiek.getNazwa() << " " << czlowiek.getSila() << " " << czlowiek.getInicjatywa() << " " << czlowiek.getWiek() << " " << czlowiek.getX() << " " << czlowiek.getY() << " " << czlowiek.getZdolnosc() << " \n";
}

Swiat* Zapis::WczytajSwiat()
{
	std::ifstream saveFile(nazwaPliku);
	if (saveFile.good())
	{
		int x, y;
		unsigned int seed, liczbaOrg;
		saveFile >> x >> y >> seed >> liczbaOrg;
		Swiat* swiat = new Swiat(x, y, seed, 0);
		for (unsigned int i = 0; i < liczbaOrg - 1; i++)
		{
			Organizm* organizm = WczytajOrganizm(*swiat, saveFile);
			swiat->dodajOrganizm(organizm);
		}
		Czlowiek* czlowiek = WczytajCzlowieka(*swiat, saveFile);
		swiat->dodajOrganizm(czlowiek);
		swiat->setCzlowiek(czlowiek);
		swiat->setDziennik("");
		saveFile.close();
		return swiat;
	}
	else
	{
		saveFile.close();
		return NULL;
	}
}
Organizm* Zapis::WczytajOrganizm(Swiat& swiat, std::ifstream& saveFile)
{
	int sila, inicjatywa, wiek, x, y;
	std::string nazwa;
	saveFile >> nazwa;
	if (nazwa == "Wilcze" || nazwa == "Barszcz")
		saveFile >> nazwa;
	saveFile >> sila >> inicjatywa >> wiek >> x >> y;
	Organizm* organizm = NULL;
	if (nazwa == "Wilk")
		organizm = new Wilk(swiat, x, y, wiek);
	else if (nazwa == "Owca")
		organizm = new Owca(swiat, x, y, wiek);
	else if (nazwa == "Lis")
		organizm = new Lis(swiat, x, y, wiek);
	else if (nazwa == "Zolw")
		organizm = new Zolw(swiat, x, y, wiek);
	else if (nazwa == "Antylopa")
		organizm = new Antylopa(swiat, x, y, wiek);
	else if (nazwa == "Trawa")
		organizm = new Trawa(swiat, x, y, wiek);
	else if (nazwa == "Mlecz")
		organizm = new Mlecz(swiat, x, y, wiek);
	else if (nazwa == "Guarana")
		organizm = new Guarana(swiat, x, y, wiek);
	else if (nazwa == "Jagody")
		organizm = new Wilcze_Jagody(swiat, x, y, wiek);
	else if (nazwa == "Sosnowskiego")
		organizm = new Barszcz_Sosnowskiego(swiat, x, y, wiek);
	if (organizm != NULL)
	{
		if (nazwa == "Jagody")
			nazwa = "Wilcze Jagody";
		if (nazwa == "Sosnowskiego")
			nazwa = "Barszcz Sosnowskiego";
		organizm->setNazwa(nazwa);
		organizm->setSila(sila);
		organizm->setInicjatywa(inicjatywa);
	}
	else
		printf("blad przy wczytywaniu\n");
	return organizm;
}
Czlowiek* Zapis::WczytajCzlowieka(Swiat& swiat, std::ifstream& saveFile)
{
	int sila, inicjatywa, wiek, x, y, zdolnosc;
	std::string nazwa;
	saveFile >> nazwa >> sila >> inicjatywa >> wiek >> x >> y >> zdolnosc;
	Czlowiek* czlowiek = new Czlowiek(swiat, x, y, wiek);
	czlowiek->setSila(sila);
	czlowiek->setInicjatywa(inicjatywa);
	czlowiek->setZdolnosc(zdolnosc);
	return czlowiek;
}