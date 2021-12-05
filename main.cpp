#include <iostream>

#include "KsiazkaAdresowa.h"


using namespace std;




int main()
{
    KsiazkaAdresowa ksiazkaAdresowa("Uzytkownicy.txt", "Adresaci.txt");
    KsiazkaAdresowa wczytajMenu();
    ksiazkaAdresowa.wypiszWszystkichUzytkownikow();
    ksiazkaAdresowa.rejestracjaUzytkownika();
    ksiazkaAdresowa.logowanieUzytkownika();
    ksiazkaAdresowa.wypiszWszystkichUzytkownikow();
        ksiazkaAdresowa.wczytajAdresatowZPliku();
    ksiazkaAdresowa.dodanieAdresata();
    ksiazkaAdresowa.wylogowanieUzytkownika();

    return 0;
}

