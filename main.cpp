#define _CRT_SECURE_NO_WARNINGS
#include <conio.h>
#include "Swiat.h"
#include "Zapis.h"
#define MINSIZE 10

int main()
{
    printf("Podaj rozmiar swiata (min %d): ", MINSIZE);
    int x, y;
    int niekrzycznamnievisual = scanf("%d", &x);
    y = x;
    system("CLS"); // wyczysc konsole
    if (x >= MINSIZE)
    {
        unsigned int seed = (unsigned int)time(NULL);
        Swiat* swiat = new Swiat(x, y, seed, 1);
        Zapis* zapis = new Zapis("save.txt");
        int c = 0;
        while (true)
        {
            c = 0;
            swiat->wykonajTure();
            swiat->rysujSwiat();
            if (swiat->getStanGry() == 0)
            {
                printf("\nKoniec gry, kliknij dowolny klawisz aby zakonczyc program.\n");
                c = _getch();
                return 0;
            }
            while (c != 13)     // dopoki nie enter
            {
                c = _getch();
                if (c == 32)     // spacja
                {
                    if (swiat->getZdolnoscCzlowieka() >= 6)
                    {
                        printf("umiejetnosc jest juz aktywna\n");
                    }
                    else if (swiat->getZdolnoscCzlowieka() >= 1)
                    {
                        printf("nie mozna uzyc umiejetnosci\n");
                    }
                    else if (swiat->getZdolnoscCzlowieka() == 0)
                    {
                        printf("aktywowano umiejetnosc specjalna\n");
                        swiat->setZdolnoscCzlowieka(10);
                    }
                }
                else if (c == 115)      // S
                {
                    zapis->ZapiszSwiat(*swiat);
                    printf("zapisano gre\n");
                }
                else if (c == 108)      // L
                {
                    delete swiat;
                    swiat = zapis->WczytajSwiat();
                    system("CLS");
                    swiat->rysujSwiat();
                    printf("wczytano gre\n");
                }
                else
                {
                    while (_kbhit())
                    {
                        c = _getch();
                        switch (c)
                        {
                        case 72:        // gora
                            printf("kierunek: gora\n");
                            swiat->setKierunekCzlowieka(1);
                            break;
                        case 75:        // lewo
                            printf("kierunek: lewo\n");
                            swiat->setKierunekCzlowieka(2);
                            break;
                        case 80:        // dol
                            printf("kierunek: dol\n");
                            swiat->setKierunekCzlowieka(3);
                            break;
                        case 77:        // prawo
                            printf("kierunek: prawo\n");
                            swiat->setKierunekCzlowieka(4);
                            break;
                        default:
                            break;
                        }
                    }
                } 
            }
        }
    }
    return 0;
}

#define gotoxy(x,y) printf("\033[%d;%dH", (y), (x))
#define clear() printf("\033[H\033[J")